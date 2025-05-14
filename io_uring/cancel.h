// SPDX-License-Identifier: GPL-2.0
#ifndef IORING_CANCEL_H
#define IORING_CANCEL_H

#include <linux/io_uring_types.h>

struct io_cancel_data {
	struct io_ring_ctx *ctx;
	union {
		u64 data;
		struct file *file;
	};
	u8 opcode;
	u32 flags;
	int seq;
};
/**
 * Mempersiapkan permintaan async cancel dari sqe.
 */
int io_async_cancel_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Menjalankan pembatalan permintaan async dari SQE.
 */
int io_async_cancel(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Mencoba membatalkan permintaan pada berbagai sumber (async, poll, waitid, futex, timeout).
 */
int io_try_cancel(struct io_uring_task *tctx, struct io_cancel_data *cd,
		  unsigned int issue_flags);
/**
 * Menjalankan pembatalan permintaan secara sinkron dari userspace.
 */
int io_sync_cancel(struct io_ring_ctx *ctx, void __user *arg);
/**
 * Cek apakah permintaan sesuai dengan kriteria pembatalan.
 */
bool io_cancel_req_match(struct io_kiocb *req, struct io_cancel_data *cd);
/**
 * Menghapus semua permintaan pada list yang cocok dengan task.
 */
bool io_cancel_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx,
			  struct hlist_head *list, bool cancel_all,
			  bool (*cancel)(struct io_kiocb *));
/**
 * Menghapus permintaan pada list yang cocok dengan data pembatalan.
 */
int io_cancel_remove(struct io_ring_ctx *ctx, struct io_cancel_data *cd,
		     unsigned int issue_flags, struct hlist_head *list,
		     bool (*cancel)(struct io_kiocb *));

			 /**
 * Membandingkan dan mengatur sequence pembatalan pada permintaan.
 */
static inline bool io_cancel_match_sequence(struct io_kiocb *req, int sequence)
{
	if (req->cancel_seq_set && sequence == req->work.cancel_seq)
		return true;

	req->cancel_seq_set = true;
	req->work.cancel_seq = sequence;
	return false;
}

#endif
