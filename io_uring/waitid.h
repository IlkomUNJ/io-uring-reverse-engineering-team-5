// SPDX-License-Identifier: GPL-2.0

#include "../kernel/exit.h"

struct io_waitid_async {
	struct io_kiocb *req;
	struct wait_opts wo;
};

// Mempersiapkan permintaan waitid dengan memvalidasi parameter dan menginisialisasi data asinkron.
int io_waitid_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Menangani permintaan waitid, termasuk menambahkan ke antrean tunggu dan memproses hasilnya.
int io_waitid(struct io_kiocb *req, unsigned int issue_flags);

//Membatalkan permintaan waitid tertentu berdasarkan data pembatalan yang diberikan.
int io_waitid_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd,
		     unsigned int issue_flags);
			 
// Membatalkan semua permintaan waitid yang terkait dengan task tertentu atau semua permintaan jika diminta.
bool io_waitid_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx,
			  bool cancel_all);
