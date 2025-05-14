#ifndef INTERNAL_IO_WQ_H
#define INTERNAL_IO_WQ_H

#include <linux/refcount.h>
#include <linux/io_uring_types.h>

struct io_wq;

enum {
	IO_WQ_WORK_CANCEL	= 1,
	IO_WQ_WORK_HASHED	= 2,
	IO_WQ_WORK_UNBOUND	= 4,
	IO_WQ_WORK_CONCURRENT	= 16,

	IO_WQ_HASH_SHIFT	= 24,	/* upper 8 bits are used for hash key */
};

enum io_wq_cancel {
	IO_WQ_CANCEL_OK,	/* cancelled before started */
	IO_WQ_CANCEL_RUNNING,	/* found, running, and attempted cancelled */
	IO_WQ_CANCEL_NOTFOUND,	/* work not found */
};

typedef struct io_wq_work *(free_work_fn)(struct io_wq_work *);
typedef void (io_wq_work_fn)(struct io_wq_work *);

struct io_wq_hash {
	refcount_t refs;
	unsigned long map;
	struct wait_queue_head wait;
};

static inline void io_wq_put_hash(struct io_wq_hash *hash)
{
	if (refcount_dec_and_test(&hash->refs))
		kfree(hash);
}

struct io_wq_data {
	struct io_wq_hash *hash;
	struct task_struct *task;
	io_wq_work_fn *do_work;
	free_work_fn *free_work;
};

/** 
 * Membuat instance io_wq baru. 
 * Digunakan untuk menginisialisasi struktur io_wq.
 */
struct io_wq *io_wq_create(unsigned bounded, struct io_wq_data *data);
/** 
 * Memulai proses penghentian io_wq. 
 * Digunakan untuk menandai bahwa io_wq sedang dihentikan.
 */
void io_wq_exit_start(struct io_wq *wq);
/** 
 * Menghentikan dan menghancurkan io_wq. 
 * Digunakan untuk membersihkan semua sumber daya sebelum keluar.
 */
void io_wq_put_and_exit(struct io_wq *wq);

/** 
 * Menambahkan pekerjaan ke antrean io_wq. 
 * Digunakan untuk menjadwalkan pekerjaan untuk diproses.
 */
void io_wq_enqueue(struct io_wq *wq, struct io_wq_work *work);
/** 
 * Menandai pekerjaan sebagai pekerjaan hash. 
 * Digunakan untuk membatasi pekerjaan yang berjalan secara paralel.
 */
void io_wq_hash_work(struct io_wq_work *work, void *val);

/** 
 * Mengatur afinitas CPU untuk io_wq. 
 * Digunakan untuk mengikat pekerjaan ke CPU tertentu.
 */
int io_wq_cpu_affinity(struct io_uring_task *tctx, cpumask_var_t mask);
/** 
 * Mengatur jumlah maksimum worker yang tidak terikat. 
 * Digunakan untuk membatasi jumlah worker yang dapat dibuat.
 */
int io_wq_max_workers(struct io_wq *wq, int *new_count);
/** 
 * Memeriksa apakah worker telah dihentikan. 
 * Digunakan untuk memastikan worker tidak lagi aktif.
 */
bool io_wq_worker_stopped(void);

/** 
 * Memeriksa apakah pekerjaan memiliki flag hashed. 
 * Digunakan untuk menentukan apakah pekerjaan adalah pekerjaan hash.
 */
static inline bool __io_wq_is_hashed(unsigned int work_flags)
{
	return work_flags & IO_WQ_WORK_HASHED;
}

static inline bool io_wq_is_hashed(struct io_wq_work *work)
{
	return __io_wq_is_hashed(atomic_read(&work->flags));
}

typedef bool (work_cancel_fn)(struct io_wq_work *, void *);

/** 
 * Membatalkan pekerjaan yang sedang berjalan atau tertunda. 
 * Digunakan untuk menghentikan pekerjaan berdasarkan kriteria tertentu.
 */
enum io_wq_cancel io_wq_cancel_cb(struct io_wq *wq, work_cancel_fn *cancel,
					void *data, bool cancel_all);

#if defined(CONFIG_IO_WQ)
/** 
 * Menandai worker sebagai sedang tidur. 
 * Digunakan untuk mengelola worker yang tidak aktif.
 */
extern void io_wq_worker_sleeping(struct task_struct *);
/** 
 * Menandai worker sebagai sedang berjalan. 
 * Digunakan untuk melacak status worker.
 */
extern void io_wq_worker_running(struct task_struct *);
#else
static inline void io_wq_worker_sleeping(struct task_struct *tsk)
{
}
/** 
 * Menandai worker sebagai sedang berjalan. 
 * Digunakan untuk melacak status worker.
 */
static inline void io_wq_worker_running(struct task_struct *tsk)
{
}
#endif

/** 
 * Memeriksa apakah thread saat ini adalah worker io_wq. 
 * Digunakan untuk memastikan operasi dilakukan oleh worker.
 */
static inline bool io_wq_current_is_worker(void)
{
	return in_task() && (current->flags & PF_IO_WORKER) &&
		current->worker_private;
}
#endif
