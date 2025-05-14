#ifndef INTERNAL_IO_SLIST_H
#define INTERNAL_IO_SLIST_H

#include <linux/io_uring_types.h>

// Makro untuk mengiterasi setiap node dalam daftar kerja mulai dari node pertama.
#define __wq_list_for_each(pos, head)				\
	for (pos = (head)->first; pos; pos = (pos)->next)

// Makro untuk mengiterasi setiap node dalam daftar kerja dengan menyimpan 
// referensi ke node sebelumnya.
#define wq_list_for_each(pos, prv, head)			\
	for (pos = (head)->first, prv = NULL; pos; prv = pos, pos = (pos)->next)

// Makro untuk melanjutkan iterasi daftar kerja dari posisi tertentu.
#define wq_list_for_each_resume(pos, prv)			\
	for (; pos; prv = pos, pos = (pos)->next)

// Mengecek apakah daftar kerja kosong dengan memeriksa node pertama.
#define wq_list_empty(list)	(READ_ONCE((list)->first) == NULL)

//  Menginisialisasi daftar kerja dengan mengatur node pertama ke NULL.
#define INIT_WQ_LIST(list)	do {				\
	(list)->first = NULL;					\
} while (0)

// Menambahkan node baru setelah node tertentu dalam daftar kerja.
static inline void wq_list_add_after(struct io_wq_work_node *node,
				     struct io_wq_work_node *pos,
				     struct io_wq_work_list *list)
{
	struct io_wq_work_node *next = pos->next;

	pos->next = node;
	node->next = next;
	if (!next)
		list->last = node;
}

// Menambahkan node baru di akhir daftar kerja.
static inline void wq_list_add_tail(struct io_wq_work_node *node,
				    struct io_wq_work_list *list)
{
	node->next = NULL;
	if (!list->first) {
		list->last = node;
		WRITE_ONCE(list->first, node);
	} else {
		list->last->next = node;
		list->last = node;
	}
}

// Menambahkan node baru di awal daftar kerja.
static inline void wq_list_add_head(struct io_wq_work_node *node,
				    struct io_wq_work_list *list)
{
	node->next = list->first;
	if (!node->next)
		list->last = node;
	WRITE_ONCE(list->first, node);
}

// Memotong daftar kerja dari node tertentu hingga akhir, dengan memperbarui referensi node sebelumnya.
static inline void wq_list_cut(struct io_wq_work_list *list,
			       struct io_wq_work_node *last,
			       struct io_wq_work_node *prev)
{
	/* first in the list, if prev==NULL */
	if (!prev)
		WRITE_ONCE(list->first, last->next);
	else
		prev->next = last->next;

	if (last == list->last)
		list->last = prev;
	last->next = NULL;
}

// Menggabungkan daftar kerja ke node tertentu tanpa memeriksa apakah daftar kosong.
static inline void __wq_list_splice(struct io_wq_work_list *list,
				    struct io_wq_work_node *to)
{
	list->last->next = to->next;
	to->next = list->first;
	INIT_WQ_LIST(list);
}

// Menggabungkan daftar kerja ke node tertentu jika daftar tidak kosong.
static inline bool wq_list_splice(struct io_wq_work_list *list,
				  struct io_wq_work_node *to)
{
	if (!wq_list_empty(list)) {
		__wq_list_splice(list, to);
		return true;
	}
	return false;
}

// Menambahkan node baru di awal stack kerja.
static inline void wq_stack_add_head(struct io_wq_work_node *node,
				     struct io_wq_work_node *stack)
{
	node->next = stack->next;
	stack->next = node;
}

// Menghapus node tertentu dari daftar kerja dengan memperbarui referensi node sebelumnya
static inline void wq_list_del(struct io_wq_work_list *list,
			       struct io_wq_work_node *node,
			       struct io_wq_work_node *prev)
{
	wq_list_cut(list, node, prev);
}

static inline
// Mengekstrak node pertama dari stack kerja.
struct io_wq_work_node *wq_stack_extract(struct io_wq_work_node *stack)
{
	struct io_wq_work_node *node = stack->next;

	stack->next = node->next;
	return node;
}

// Mendapatkan pekerjaan berikutnya dalam daftar kerja dari node saat ini.
static inline struct io_wq_work *wq_next_work(struct io_wq_work *work)
{
	if (!work->list.next)
		return NULL;

	return container_of(work->list.next, struct io_wq_work, list);
}

#endif // INTERNAL_IO_SLIST_H
