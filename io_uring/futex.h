// SPDX-License-Identifier: GPL-2.0

#include "cancel.h"

/**
 * Mempersiapkan permintaan operasi futex tunggal untuk io_uring.
 * Mengisi struktur permintaan berdasarkan sqe yang diberikan.
 * Return 0 jika sukses, atau kode error jika gagal.
 */
int io_futex_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_futexv_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
int io_futex_wait(struct io_kiocb *req, unsigned int issue_flags);
int io_futexv_wait(struct io_kiocb *req, unsigned int issue_flags);
int io_futex_wake(struct io_kiocb *req, unsigned int issue_flags);

#if defined(CONFIG_FUTEX)
/**
 * Membatalkan permintaan futex yang sedang berjalan pada context tertentu.
 * Return hasil pembatalan.
 */
int io_futex_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd,
		    unsigned int issue_flags);
/**
 * Menghapus semua permintaan futex yang terkait dengan task tertentu.
 * Jika cancel_all true, semua permintaan akan dibatalkan.
 * Return true jika ada permintaan yang dihapus, false jika tidak.
 */
bool io_futex_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx,
			 bool cancel_all);
/**
 * Menginisialisasi cache futex pada context io_uring.
 * Return true jika sukses, false jika gagal.
 */
bool io_futex_cache_init(struct io_ring_ctx *ctx);
/**
 * Membebaskan cache futex pada context io_uring.
 */
void io_futex_cache_free(struct io_ring_ctx *ctx);
#else
static inline int io_futex_cancel(struct io_ring_ctx *ctx,
				  struct io_cancel_data *cd,
				  unsigned int issue_flags)
{
	return 0;
}
static inline bool io_futex_remove_all(struct io_ring_ctx *ctx,
				       struct io_uring_task *tctx, bool cancel_all)
{
	return false;
}
static inline bool io_futex_cache_init(struct io_ring_ctx *ctx)
{
	return false;
}
static inline void io_futex_cache_free(struct io_ring_ctx *ctx)
{
}
#endif
