// SPDX-License-Identifier: GPL-2.0

#include <linux/io_uring/cmd.h>
#include <linux/io_uring_types.h>

struct io_async_cmd {
	struct io_uring_cmd_data	data;
	struct iou_vec			vec;
	struct io_uring_sqe		sqes[2];
};

// Menjalankan perintah io_uring dengan memanggil handler driver dan menangani hasilnya.
int io_uring_cmd(struct io_kiocb *req, unsigned int issue_flags);

// Mempersiapkan perintah io_uring dengan memvalidasi flag dan parameter dari struktur sqe.
int io_uring_cmd_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Membersihkan sumber daya terkait perintah io_uring, termasuk data asinkron dan cache.
void io_uring_cmd_cleanup(struct io_kiocb *req);

//  Mencoba membatalkan perintah io_uring yang dapat dibatalkan berdasarkan konteks atau task tertentu.
bool io_uring_try_cancel_uring_cmd(struct io_ring_ctx *ctx,
				   struct io_uring_task *tctx, bool cancel_all);

// Membebaskan memori yang digunakan oleh perintah asinkron, termasuk vektor I/O.
void io_cmd_cache_free(const void *entry);

// Mengimpor vektor tetap untuk perintah io_uring dan menginisialisasi iterasi I/O.
int io_uring_cmd_import_fixed_vec(struct io_uring_cmd *ioucmd,
				  const struct iovec __user *uvec,
				  size_t uvec_segs,
				  int ddir, struct iov_iter *iter,
				  unsigned issue_flags);
