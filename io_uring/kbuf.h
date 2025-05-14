// SPDX-License-Identifier: GPL-2.0
#ifndef IOU_KBUF_H
#define IOU_KBUF_H

#include <uapi/linux/io_uring.h>
#include <linux/io_uring_types.h>

enum {
	/* ring mapped provided buffers */
	IOBL_BUF_RING	= 1,
	/* buffers are consumed incrementally rather than always fully */
	IOBL_INC	= 2,
};

struct io_buffer_list {
	/*
	 * If ->buf_nr_pages is set, then buf_pages/buf_ring are used. If not,
	 * then these are classic provided buffers and ->buf_list is used.
	 */
	union {
		struct list_head buf_list;
		struct io_uring_buf_ring *buf_ring;
	};
	__u16 bgid;

	/* below is for ring provided buffers */
	__u16 buf_nr_pages;
	__u16 nr_entries;
	__u16 head;
	__u16 mask;

	__u16 flags;

	struct io_mapped_region region;
};

struct io_buffer {
	struct list_head list;
	__u64 addr;
	__u32 len;
	__u16 bid;
	__u16 bgid;
};

enum {
	/* can alloc a bigger vec */
	KBUF_MODE_EXPAND	= 1,
	/* if bigger vec allocated, free old one */
	KBUF_MODE_FREE		= 2,
};

struct buf_sel_arg {
	struct iovec *iovs;
	size_t out_len;
	size_t max_len;
	unsigned short nr_iovs;
	unsigned short mode;
};

/** 
 * Memilih buffer untuk permintaan IO. 
 * Digunakan untuk menentukan buffer yang akan digunakan.
 */
void __user *io_buffer_select(struct io_kiocb *req, size_t *len,
			      unsigned int issue_flags);
/** 
 * Memilih buffer untuk permintaan IO dengan parameter tambahan. 
 * Digunakan untuk operasi IO yang memerlukan buffer tertentu.
 */
int io_buffers_select(struct io_kiocb *req, struct buf_sel_arg *arg,
		      unsigned int issue_flags);
/** 
 * Melihat buffer yang tersedia untuk permintaan IO. 
 * Digunakan untuk menentukan buffer yang dapat digunakan tanpa mengubah state.
 */
int io_buffers_peek(struct io_kiocb *req, struct buf_sel_arg *arg);
/** 
 * Menghancurkan semua buffer yang terdaftar di konteks io_uring. 
 * Digunakan untuk membersihkan buffer saat ring dihancurkan.
 */
void io_destroy_buffers(struct io_ring_ctx *ctx);

/** 
 * Mempersiapkan penghapusan buffer berdasarkan SQE. 
 * Digunakan untuk memvalidasi dan mengatur parameter penghapusan buffer.
 */
int io_remove_buffers_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/** 
 * Menghapus buffer dari daftar buffer berdasarkan permintaan. 
 * Digunakan untuk membersihkan buffer yang tidak lagi diperlukan.
 */
int io_remove_buffers(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Mempersiapkan penambahan buffer berdasarkan SQE. 
 * Digunakan untuk memvalidasi dan mengatur parameter penambahan buffer.
 */
int io_provide_buffers_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/** 
 * Menambahkan buffer ke daftar buffer. 
 * Digunakan untuk mendaftarkan buffer baru untuk operasi IO.
 */
int io_provide_buffers(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Mendaftarkan ring buffer untuk buffer yang disediakan pengguna. 
 * Digunakan untuk mengatur ring buffer untuk operasi IO.
 */
int io_register_pbuf_ring(struct io_ring_ctx *ctx, void __user *arg);
/** 
 * Membatalkan pendaftaran ring buffer untuk buffer yang disediakan pengguna. 
 * Digunakan untuk membersihkan ring buffer yang tidak lagi diperlukan.
 */
int io_unregister_pbuf_ring(struct io_ring_ctx *ctx, void __user *arg);
/** 
 * Mendaftarkan status buffer yang disediakan pengguna. 
 * Digunakan untuk melaporkan status buffer ke pengguna.
 */
int io_register_pbuf_status(struct io_ring_ctx *ctx, void __user *arg);

/** 
 * Mendaur ulang buffer legacy untuk digunakan kembali. 
 * Digunakan untuk mengoptimalkan penggunaan buffer.
 */
bool io_kbuf_recycle_legacy(struct io_kiocb *req, unsigned issue_flags);
/** 
 * Menghapus buffer legacy dari permintaan. 
 * Digunakan untuk membersihkan buffer yang tidak lagi digunakan.
 */
void io_kbuf_drop_legacy(struct io_kiocb *req);

/** 
 * Mengelola buffer untuk permintaan IO. 
 * Digunakan untuk memperbarui buffer setelah operasi selesai.
 */
unsigned int __io_put_kbufs(struct io_kiocb *req, int len, int nbufs);
/** 
 * Mengelola komit buffer untuk permintaan tertentu. 
 * Digunakan untuk memastikan buffer diproses dengan benar.
 */
bool io_kbuf_commit(struct io_kiocb *req,
		    struct io_buffer_list *bl, int len, int nr);

/** 
 * Mendapatkan region yang dipetakan untuk buffer yang disediakan pengguna. 
 * Digunakan untuk mengakses region memori yang terkait dengan buffer.
 */
struct io_mapped_region *io_pbuf_get_region(struct io_ring_ctx *ctx,
					    unsigned int bgid);

/** 
 * Mendaur ulang buffer dari ring buffer. 
 * Digunakan untuk memastikan buffer dapat digunakan kembali.
 */
static inline bool io_kbuf_recycle_ring(struct io_kiocb *req)
{
	/*
	 * We don't need to recycle for REQ_F_BUFFER_RING, we can just clear
	 * the flag and hence ensure that bl->head doesn't get incremented.
	 * If the tail has already been incremented, hang on to it.
	 * The exception is partial io, that case we should increment bl->head
	 * to monopolize the buffer.
	 */
	if (req->buf_list) {
		req->buf_index = req->buf_list->bgid;
		req->flags &= ~(REQ_F_BUFFER_RING|REQ_F_BUFFERS_COMMIT);
		return true;
	}
	return false;
}

/** 
 * Memeriksa apakah buffer dapat dipilih untuk permintaan IO. 
 * Digunakan untuk menentukan apakah buffer dapat digunakan.
 */
static inline bool io_do_buffer_select(struct io_kiocb *req)
{
	if (!(req->flags & REQ_F_BUFFER_SELECT))
		return false;
	return !(req->flags & (REQ_F_BUFFER_SELECTED|REQ_F_BUFFER_RING));
}

/** 
 * Mendaur ulang buffer untuk permintaan IO. 
 * Digunakan untuk mengoptimalkan penggunaan buffer.
 */
static inline bool io_kbuf_recycle(struct io_kiocb *req, unsigned issue_flags)
{
	if (req->flags & REQ_F_BL_NO_RECYCLE)
		return false;
	if (req->flags & REQ_F_BUFFER_SELECTED)
		return io_kbuf_recycle_legacy(req, issue_flags);
	if (req->flags & REQ_F_BUFFER_RING)
		return io_kbuf_recycle_ring(req);
	return false;
}

/** 
 * Mengelola buffer untuk permintaan IO. 
 * Digunakan untuk memperbarui buffer setelah operasi selesai.
 */
static inline unsigned int io_put_kbuf(struct io_kiocb *req, int len,
				       unsigned issue_flags)
{
	if (!(req->flags & (REQ_F_BUFFER_RING | REQ_F_BUFFER_SELECTED)))
		return 0;
	return __io_put_kbufs(req, len, 1);
}

/** 
 * Mengelola beberapa buffer untuk permintaan IO. 
 * Digunakan untuk memperbarui beberapa buffer setelah operasi selesai.
 */
static inline unsigned int io_put_kbufs(struct io_kiocb *req, int len,
					int nbufs, unsigned issue_flags)
{
	if (!(req->flags & (REQ_F_BUFFER_RING | REQ_F_BUFFER_SELECTED)))
		return 0;
	return __io_put_kbufs(req, len, nbufs);
}
#endif
