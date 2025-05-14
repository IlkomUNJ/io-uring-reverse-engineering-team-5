#ifndef IOU_ALLOC_CACHE_H
#define IOU_ALLOC_CACHE_H

#include <linux/io_uring_types.h>

/*
 * Don't allow the cache to grow beyond this size.
 */
#define IO_ALLOC_CACHE_MAX	128

/**
 * Membebaskan semua entri yang tersisa di cache dan mengosongkan cache.
 * Memanggil fungsi free untuk setiap entri yang diambil dari cache.
 * Setelah semua entri dibebaskan, memory cache->entries juga dibebaskan.
 */
void io_alloc_cache_free(struct io_alloc_cache *cache,
			 void (*free)(const void *));
/**
 * Menginisialisasi struktur cache untuk alokasi objek.
 * Mengalokasikan array pointer untuk cache sebanyak max_nr.
 * Mengatur ukuran elemen, jumlah maksimum, dan inisialisasi byte.
 * Return false jika inisialisasi berhasil, true jika gagal.
 */
bool io_alloc_cache_init(struct io_alloc_cache *cache,
			 unsigned max_nr, unsigned int size,
			 unsigned int init_bytes);

			 /**
 * Mengalokasikan objek baru dengan ukuran sesuai cache->elem_size.
 * Jika init_clear di-set, maka objek akan diinisialisasi dengan nol.
 * Return pointer ke objek baru, atau NULL jika gagal.
 */
void *io_cache_alloc_new(struct io_alloc_cache *cache, gfp_t gfp);
/**
 * Menyimpan objek ke dalam cache jika masih ada ruang.
 * Jika berhasil, objek dimasukkan ke cache dan return true.
 * Jika cache penuh, return false.
 */
static inline bool io_alloc_cache_put(struct io_alloc_cache *cache,
				      void *entry)
{
	if (cache->nr_cached < cache->max_cached) {
		if (!kasan_mempool_poison_object(entry))
			return false;
		cache->entries[cache->nr_cached++] = entry;
		return true;
	}
	return false;
}

/**
 * Mengambil satu objek dari cache jika tersedia.
 * Jika KASAN aktif, melakukan pembersihan pada objek.
 * Return pointer ke objek, atau NULL jika cache kosong.
 */
static inline void *io_alloc_cache_get(struct io_alloc_cache *cache)
{
	if (cache->nr_cached) {
		void *entry = cache->entries[--cache->nr_cached];

		/*
		 * If KASAN is enabled, always clear the initial bytes that
		 * must be zeroed post alloc, in case any of them overlap
		 * with KASAN storage.
		 */
#if defined(CONFIG_KASAN)
		kasan_mempool_unpoison_object(entry, cache->elem_size);
		if (cache->init_clear)
			memset(entry, 0, cache->init_clear);
#endif
		return entry;
	}

	return NULL;
}

/**
 * Mengambil objek dari cache jika tersedia, jika tidak maka alokasi baru.
 * Return pointer ke objek hasil cache atau hasil alokasi baru.
 */
static inline void *io_cache_alloc(struct io_alloc_cache *cache, gfp_t gfp)
{
	void *obj;

	obj = io_alloc_cache_get(cache);
	if (obj)
		return obj;
	return io_cache_alloc_new(cache, gfp);
}

/**
 * Mengambil objek dari cache jika tersedia, jika tidak maka alokasi baru.
 * Return pointer ke objek hasil cache atau hasil alokasi baru.
 */
static inline void io_cache_free(struct io_alloc_cache *cache, void *obj)
{
	if (!io_alloc_cache_put(cache, obj))
		kfree(obj);
}

#endif
