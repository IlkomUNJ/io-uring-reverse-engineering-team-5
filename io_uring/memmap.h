#ifndef IO_URING_MEMMAP_H
#define IO_URING_MEMMAP_H

#define IORING_MAP_OFF_PARAM_REGION		0x20000000ULL
#define IORING_MAP_OFF_ZCRX_REGION		0x30000000ULL

/** 
 * Mem-pin halaman memori pengguna untuk digunakan kernel. 
 * Digunakan untuk mengakses memori pengguna secara aman.
 */
struct page **io_pin_pages(unsigned long ubuf, unsigned long len, int *npages);

#ifndef CONFIG_MMU
/** 
 * Mendapatkan kemampuan mmap pada sistem tanpa MMU. 
 * Digunakan untuk menentukan fitur mmap yang didukung.
 */
unsigned int io_uring_nommu_mmap_capabilities(struct file *file);
#endif

/** 
 * Mendapatkan area yang tidak dipetakan untuk mmap. 
 * Digunakan untuk menentukan lokasi mmap di ruang alamat pengguna.
 */
unsigned long io_uring_get_unmapped_area(struct file *file, unsigned long addr,
                                         unsigned long len, unsigned long pgoff,
                                         unsigned long flags);

/** 
 * Melakukan mmap pada file io_uring. 
 * Digunakan untuk memetakan region memori ke ruang alamat pengguna.
 */
int io_uring_mmap(struct file *file, struct vm_area_struct *vma);

/** 
 * Membebaskan region memori yang dipetakan. 
 * Digunakan untuk membersihkan sumber daya memori.
 */
void io_free_region(struct io_ring_ctx *ctx, struct io_mapped_region *mr);

/** 
 * Membuat region memori baru untuk operasi IO. 
 * Digunakan untuk mengatur region memori yang dipetakan.
 */
int io_create_region(struct io_ring_ctx *ctx, struct io_mapped_region *mr,
                     struct io_uring_region_desc *reg,
                     unsigned long mmap_offset);

/** 
 * Membuat region memori baru dengan aman untuk mmap. 
 * Digunakan untuk memastikan region memori dapat diakses dengan mmap.
 */
int io_create_region_mmap_safe(struct io_ring_ctx *ctx,
                               struct io_mapped_region *mr,
                               struct io_uring_region_desc *reg,
                               unsigned long mmap_offset);

/** 
 * Mendapatkan pointer ke region memori yang dipetakan. 
 * Digunakan untuk mengakses data di region memori.
 */
static inline void *io_region_get_ptr(struct io_mapped_region *mr)
{
    return mr->ptr;
}

/** 
 * Memeriksa apakah region memori telah diatur. 
 * Digunakan untuk memastikan region memori valid sebelum digunakan.
 */
static inline bool io_region_is_set(struct io_mapped_region *mr)
{
    return !!mr->nr_pages;
}

#endif
