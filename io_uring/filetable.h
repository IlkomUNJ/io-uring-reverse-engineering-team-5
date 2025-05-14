// SPDX-License-Identifier: GPL-2.0
#ifndef IOU_FILE_TABLE_H
#define IOU_FILE_TABLE_H

#include <linux/file.h>
#include <linux/io_uring_types.h>
#include "rsrc.h"

/**
 * Alokasikan tabel file untuk context io_uring.
 */
bool io_alloc_file_tables(struct io_ring_ctx *ctx, struct io_file_table *table, unsigned nr_files);
/**
 * Bebaskan tabel file pada context io_uring.
 */
void io_free_file_tables(struct io_ring_ctx *ctx, struct io_file_table *table);
/**
 * Instal file ke slot file tetap (fixed file) melalui permintaan io_uring.
 */
int io_fixed_fd_install(struct io_kiocb *req, unsigned int issue_flags,
			struct file *file, unsigned int file_slot);
/**
 * Instal file ke slot file tetap pada context.
 */			
int __io_fixed_fd_install(struct io_ring_ctx *ctx, struct file *file,
				unsigned int file_slot);
/**
 * Hapus file dari slot file tetap pada context.
 */				
int io_fixed_fd_remove(struct io_ring_ctx *ctx, unsigned int offset);
/**
 * Daftarkan rentang slot file yang dapat dialokasikan.
 */
int io_register_file_alloc_range(struct io_ring_ctx *ctx,
				 struct io_uring_file_index_range __user *arg);
/**
 * Ambil flags khusus dari objek file.
 */
io_req_flags_t io_file_get_flags(struct file *file);
/**
 * Bersihkan bit pada bitmap file table.
 */
static inline void io_file_bitmap_clear(struct io_file_table *table, int bit)
{
	WARN_ON_ONCE(!test_bit(bit, table->bitmap));
	__clear_bit(bit, table->bitmap);
	table->alloc_hint = bit;
}
/**
 * Set bit pada bitmap file table.
 */
static inline void io_file_bitmap_set(struct io_file_table *table, int bit)
{
	WARN_ON_ONCE(test_bit(bit, table->bitmap));
	__set_bit(bit, table->bitmap);
	table->alloc_hint = bit + 1;
}

#define FFS_NOWAIT		0x1UL
#define FFS_ISREG		0x2UL
#define FFS_MASK		~(FFS_NOWAIT|FFS_ISREG)
/**
 * Ambil flags slot dari node resource file.
 */
static inline unsigned int io_slot_flags(struct io_rsrc_node *node)
{

	return (node->file_ptr & ~FFS_MASK) << REQ_F_SUPPORT_NOWAIT_BIT;
}
/**
 * Ambil objek file dari node resource file.
 */
static inline struct file *io_slot_file(struct io_rsrc_node *node)
{
	return (struct file *)(node->file_ptr & FFS_MASK);
}
/**
 * Set objek file pada node resource file.
 */
static inline void io_fixed_file_set(struct io_rsrc_node *node,
				     struct file *file)
{
	node->file_ptr = (unsigned long)file |
		(io_file_get_flags(file) >> REQ_F_SUPPORT_NOWAIT_BIT);
}
/**
 * Set rentang alokasi file pada context.
 */
static inline void io_file_table_set_alloc_range(struct io_ring_ctx *ctx,
						 unsigned off, unsigned len)
{
	ctx->file_alloc_start = off;
	ctx->file_alloc_end = off + len;
	ctx->file_table.alloc_hint = ctx->file_alloc_start;
}

#endif
