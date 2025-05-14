// SPDX-License-Identifier: GPL-2.0

struct io_tctx_node {
	struct list_head	ctx_node;
	struct task_struct	*task;
	struct io_ring_ctx	*ctx;
};

// Mengalokasikan dan menginisialisasi konteks task untuk io_uring, 
// termasuk struktur pendukung seperti workqueue.
int io_uring_alloc_task_context(struct task_struct *task,
				struct io_ring_ctx *ctx);

// Menghapus node konteks task dari xarray dan daftar konteks io_uring, 
// serta membersihkan sumber daya terkait.
void io_uring_del_tctx_node(unsigned long index);

//Menambahkan node konteks task ke dalam xarray dan daftar konteks io_uring jika belum ada.
int __io_uring_add_tctx_node(struct io_ring_ctx *ctx);

//Menambahkan node konteks task dari jalur submit dengan validasi tambahan untuk mode single issuer.
int __io_uring_add_tctx_node_from_submit(struct io_ring_ctx *ctx);

//Membersihkan semua node dan workqueue dari konteks task io_uring secara aman.
void io_uring_clean_tctx(struct io_uring_task *tctx);


//Membatalkan registrasi semua file descriptor ring yang terdaftar di task io_uring.
void io_uring_unreg_ringfd(void);

//Mendaftarkan file descriptor ring untuk menghindari overhead fdget/fdput 
// pada setiap panggilan io_uring_enter.
int io_ringfd_register(struct io_ring_ctx *ctx, void __user *__arg,
		       unsigned nr_args);

// Membatalkan registrasi file descriptor ring yang terdaftar dengan 
// validasi parameter dan penghapusan aman.
int io_ringfd_unregister(struct io_ring_ctx *ctx, void __user *__arg,
			 unsigned nr_args);

/*
 * Note that this task has used io_uring. We use it for cancelation purposes.
 */
// Menambahkan node konteks task ke daftar jika belum ada, 
// dengan optimisasi untuk menghindari duplikasi.
static inline int io_uring_add_tctx_node(struct io_ring_ctx *ctx)
{
	struct io_uring_task *tctx = current->io_uring;

	if (likely(tctx && tctx->last == ctx))
		return 0;

	return __io_uring_add_tctx_node_from_submit(ctx);
}
