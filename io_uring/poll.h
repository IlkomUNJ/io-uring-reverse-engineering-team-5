// SPDX-License-Identifier: GPL-2.0

#include <linux/io_uring_types.h>

#define IO_POLL_ALLOC_CACHE_MAX 32

enum {
	IO_APOLL_OK,
	IO_APOLL_ABORTED,
	IO_APOLL_READY
};

struct io_poll {
	struct file			*file;
	struct wait_queue_head		*head;
	__poll_t			events;
	int				retries;
	struct wait_queue_entry		wait;
};

struct async_poll {
	struct io_poll		poll;
	struct io_poll		*double_poll;
};

/*
 * Must only be called inside issue_flags & IO_URING_F_MULTISHOT, or
 * potentially other cases where we already "own" this poll request.
 */
static inline void io_poll_multishot_retry(struct io_kiocb *req)
{
	atomic_inc(&req->poll_refs);
}
/*
 * Menyiapkan permintaan penambahan poll dengan mem-parsing event mask
 * dan memvalidasi field dari io_uring_sqe.
 */
int io_poll_add_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/*
 * Menambahkan permintaan poll ke wait queue dan mengaktifkan handler-nya.
 */
int io_poll_add(struct io_kiocb *req, unsigned int issue_flags);

/*
 * Menyiapkan permintaan penghapusan poll dengan parsing event mask
 * dan validasi io_uring_sqe.
 */
int io_poll_remove_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/*
 * Menghapus permintaan poll dari wait queue dan opsional memperbarui
 * event atau user data-nya.
 */
int io_poll_remove(struct io_kiocb *req, unsigned int issue_flags);

struct io_cancel_data;
/*
 * Membatalkan permintaan poll berdasarkan data pembatalan yang diberikan.
 */
int io_poll_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd,
		   unsigned issue_flags);

/*
 * Mengaktifkan handler poll untuk permintaan yang diberikan,
 * memungkinkan permintaan tersebut memantau event.
 */
int io_arm_poll_handler(struct io_kiocb *req, unsigned issue_flags);

/*
 * Menghapus semua permintaan poll yang terkait dengan konteks task tertentu (tctx).
 * Jika cancel_all bernilai true, semua permintaan dibatalkan.
 */
bool io_poll_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx,
			bool cancel_all);

/*
 * Menangani task work untuk permintaan poll,
 * termasuk memeriksa event, menjalankan ulang, atau menyelesaikannya.
 */
void io_poll_task_func(struct io_kiocb *req, io_tw_token_t tw);
