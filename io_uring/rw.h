// SPDX-License-Identifier: GPL-2.0

#include <linux/io_uring_types.h>
#include <linux/pagemap.h>

struct io_meta_state {
	u32			seed;
	struct iov_iter_state	iter_meta;
};

struct io_async_rw {
	struct iou_vec			vec;
	size_t				bytes_done;

	struct_group(clear,
		struct iov_iter			iter;
		struct iov_iter_state		iter_state;
		struct iovec			fast_iov;
		/*
		 * wpq is for buffered io, while meta fields are used with
		 * direct io
		 */
		union {
			struct wait_page_queue		wpq;
			struct {
				struct uio_meta			meta;
				struct io_meta_state		meta_state;
			};
		};
	);
};
//Mengatur operasi baca menggunakan buffer tetap yang telah didaftarkan.
int io_prep_read_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
//Mengatur operasi tulis menggunakan buffer tetap yang telah didaftarkan.
int io_prep_write_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
//Menangani operasi baca dengan beberapa buffer tetap.
int io_prep_readv_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
//Menangani operasi tulis dengan beberapa buffer tetap.
int io_prep_writev_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
//Mengatur operasi baca dengan beberapa buffer.
int io_prep_readv(struct io_kiocb *req, const struct io_uring_sqe *sqe);
//Mengatur operasi tulis dengan beberapa buffer.
int io_prep_writev(struct io_kiocb *req, const struct io_uring_sqe *sqe);
//Mengatur operasi baca standar.
int io_prep_read(struct io_kiocb *req, const struct io_uring_sqe *sqe);
//Mengatur operasi tulis standar.
int io_prep_write(struct io_kiocb *req, const struct io_uring_sqe *sqe);
//Mengimplementasikan logika utama untuk pembacaan data dalam io_uring.
int io_read(struct io_kiocb *req, unsigned int issue_flags);
//Mengimplementasikan logika utama untuk penulisan data dalam io_uring.
int io_write(struct io_kiocb *req, unsigned int issue_flags);
//Menangani pembacaan menggunakan buffer tetap yang telah didaftarkan.
int io_read_fixed(struct io_kiocb *req, unsigned int issue_flags);
//Menangani penulisan menggunakan buffer tetap yang telah didaftarkan.
int io_write_fixed(struct io_kiocb *req, unsigned int issue_flags);
//Memastikan pembersihan vektor I/O setelah operasi.
void io_readv_writev_cleanup(struct io_kiocb *req);
//Menjamin penanganan kesalahan yang tepat untuk operasi I/O yang gagal.
void io_rw_fail(struct io_kiocb *req);
//Menyelesaikan operasi I/O dan melaporkan hasilnya.
void io_req_rw_complete(struct io_kiocb *req, io_tw_token_t tw);
//Mengatur operasi baca multishot untuk file yang dapat dipolling.
int io_read_mshot_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
//Mengimplementasikan pembacaan multishot untuk file yang dapat dipolling.
int io_read_mshot(struct io_kiocb *req, unsigned int issue_flags);
//Memastikan pembersihan struktur baca/tulis yang dicache dengan benar.
void io_rw_cache_free(const void *entry);
