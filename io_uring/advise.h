// SPDX-License-Identifier: GPL-2.0
/**
 * Mempersiapkan permintaan madvise untuk io_uring.
 * Mengisi struktur io_madvise berdasarkan sqe yang diberikan.
 */
int io_madvise_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Menjalankan operasi madvise pada area memori yang diminta.
 * Memanggil do_madvise dengan parameter dari io_madvise.
 */
int io_madvise(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Mempersiapkan permintaan fadvise untuk io_uring.
 * Mengisi struktur io_fadvise berdasarkan sqe yang diberikan.
 */
int io_fadvise_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Menjalankan operasi fadvise pada file yang diminta.
 * Memanggil vfs_fadvise dengan parameter dari io_fadvise.
 */
int io_fadvise(struct io_kiocb *req, unsigned int issue_flags);
