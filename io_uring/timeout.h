// SPDX-License-Identifier: GPL-2.0

// Struktur yang menyimpan data terkait timeout, termasuk permintaan, timer, waktu, mode, dan flag.
struct io_timeout_data {
	struct io_kiocb			*req;
	struct hrtimer			timer;
	struct timespec64		ts;
	enum hrtimer_mode		mode;
	u32				flags;
};

// Fungsi untuk membatalkan timeout yang terhubung dan menghapusnya dari daftar jika berhasil.
struct io_kiocb *__io_disarm_linked_timeout(struct io_kiocb *req,
					    struct io_kiocb *link);

// Fungsi inline untuk memeriksa dan membatalkan timeout yang terhubung jika opcode cocok.
static inline struct io_kiocb *io_disarm_linked_timeout(struct io_kiocb *req)
{
	struct io_kiocb *link = req->link;

	if (link && link->opcode == IORING_OP_LINK_TIMEOUT)
		return __io_disarm_linked_timeout(req, link);

	return NULL;
}

// Membersihkan semua timeout yang telah kedaluwarsa dari daftar dan menyelesaikan permintaan terkait.
__cold void io_flush_timeouts(struct io_ring_ctx *ctx);
struct io_cancel_data;

// Membatalkan permintaan timeout tertentu berdasarkan data pembatalan yang diberikan.
int io_timeout_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd);

// Membatalkan semua timeout yang cocok dengan task tertentu atau membatalkan semua timeout jika diminta.
__cold bool io_kill_timeouts(struct io_ring_ctx *ctx, struct io_uring_task *tctx,
			     bool cancel_all);

//Menambahkan timeout yang terhubung ke daftar dan memulai timer jika referensi masih valid.
void io_queue_linked_timeout(struct io_kiocb *req);

//Menonaktifkan timeout yang terhubung berikutnya dan menyelesaikan permintaan terkait.
void io_disarm_next(struct io_kiocb *req);

// Mempersiapkan permintaan timeout reguler dengan memvalidasi parameter dan menginisialisasi data timeout
int io_timeout_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Mempersiapkan permintaan timeout yang terhubung dengan memvalidasi parameter dan menginisialisasi data timeout.
int io_link_timeout_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Menambahkan permintaan timeout ke daftar dan memulai timer berdasarkan urutan atau waktu absolut.
int io_timeout(struct io_kiocb *req, unsigned int issue_flags);

// Mempersiapkan penghapusan atau pembaruan timeout dengan memvalidasi parameter.
int io_timeout_remove_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Menghapus atau memperbarui timeout yang ada berdasarkan parameter yang diberikan.
int io_timeout_remove(struct io_kiocb *req, unsigned int issue_flags);
