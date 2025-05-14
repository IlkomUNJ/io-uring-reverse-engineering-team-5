// SPDX-License-Identifier: GPL-2.0

struct io_sq_data {
	refcount_t		refs;
	atomic_t		park_pending;
	struct mutex		lock;

	/* ctx's that are using this sqd */
	struct list_head	ctx_list;

	struct task_struct	*thread;
	struct wait_queue_head	wait;

	unsigned		sq_thread_idle;
	int			sq_cpu;
	pid_t			task_pid;
	pid_t			task_tgid;

	u64			work_time;
	unsigned long		state;
	struct completion	exited;
};
//Menyiapkan thread SQPOLL untuk memindahkan pemrosesan submission queue dari user space ke kernel.
int io_sq_offload_create(struct io_ring_ctx *ctx, struct io_uring_params *p);
//Menjamin pembersihan thread SQPOLL dengan benar saat konteks dihancurkan.
void io_sq_thread_finish(struct io_ring_ctx *ctx);
//Mengakhiri thread SQPOLL secara bersih dan terkontrol.
void io_sq_thread_stop(struct io_sq_data *sqd);
//Menangguhkan thread SQPOLL untuk sementara waktu.
void io_sq_thread_park(struct io_sq_data *sqd);
//Melanjutkan kembali eksekusi thread SQPOLL yang sedang diparkir.
void io_sq_thread_unpark(struct io_sq_data *sqd);
//Mengelola siklus hidup dari struktur data SQPOLL secara otomatis dan aman.
void io_put_sq_data(struct io_sq_data *sqd);
//Menjamin bahwa submission queue tidak penuh sebelum entri baru ditambahkan.
void io_sqpoll_wait_sq(struct io_ring_ctx *ctx);
//Mengatur thread SQPOLL agar berjalan pada CPU yang ditentukan untuk efisiensi dan isolasi kinerja.
int io_sqpoll_wq_cpu_affinity(struct io_ring_ctx *ctx, cpumask_var_t mask);
