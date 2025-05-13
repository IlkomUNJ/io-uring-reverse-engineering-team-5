// SPDX-License-Identifier: GPL-2.0

#include "alloc_cache.h"

/**
 * Membebaskan semua entri yang tersisa di cache dan mengosongkan cache.
 * Memanggil fungsi free untuk setiap entri yang diambil dari cache.
 */
void io_alloc_cache_free(struct io_alloc_cache *cache,
			 void (*free)(const void *))
{
	void *entry;

	if (!cache->entries)
		return;

	while ((entry = io_alloc_cache_get(cache)) != NULL)
		free(entry);

	kvfree(cache->entries);
	cache->entries = NULL;
}

/**
 * Menginisialisasi struktur cache untuk alokasi objek.
 * Mengalokasikan array pointer untuk cache sebanyak max_nr.
 * Mengatur ukuran elemen, jumlah maksimum, dan inisialisasi byte.
 * Return false jika inisialisasi berhasil, true jika gagal.
 */
bool io_alloc_cache_init(struct io_alloc_cache *cache,
			 unsigned max_nr, unsigned int size,
			 unsigned int init_bytes)
{
	cache->entries = kvmalloc_array(max_nr, sizeof(void *), GFP_KERNEL);
	if (!cache->entries)
		return true;

	cache->nr_cached = 0;
	cache->max_cached = max_nr;
	cache->elem_size = size;
	cache->init_clear = init_bytes;
	return false;
}

/**
 * Mengalokasikan objek baru dengan ukuran sesuai cache->elem_size.
 * Jika init_clear di-set, maka objek akan diinisialisasi dengan nol.
 * Return pointer ke objek baru, atau NULL jika gagal.
 */
void *io_cache_alloc_new(struct io_alloc_cache *cache, gfp_t gfp)
{
	void *obj;

	obj = kmalloc(cache->elem_size, gfp);
	if (obj && cache->init_clear)
		memset(obj, 0, cache->init_clear);
	return obj;
}
