// SPDX-License-Identifier: GPL-2.0
/**
 * Persiapkan permintaan rename file/direktori.
 */
int io_renameat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Jalankan operasi rename file/direktori.
 */
int io_renameat(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Bersihkan resource setelah operasi rename.
 */
void io_renameat_cleanup(struct io_kiocb *req);

/**
 * Persiapkan permintaan unlink (hapus file/direktori).
 */
int io_unlinkat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Jalankan operasi unlink (hapus file/direktori).
 */
int io_unlinkat(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Bersihkan resource setelah operasi unlink.
 */
void io_unlinkat_cleanup(struct io_kiocb *req);

/**
 * Persiapkan permintaan mkdir (buat direktori).
 */
int io_mkdirat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Jalankan operasi mkdir (buat direktori).
 */
int io_mkdirat(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Bersihkan resource setelah operasi mkdir.
 */
void io_mkdirat_cleanup(struct io_kiocb *req);

/**
 * Persiapkan permintaan symlink (buat symbolic link).
 */
int io_symlinkat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Jalankan operasi symlink (buat symbolic link).
 */
int io_symlinkat(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Bersihkan resource setelah operasi symlink.
 */
void io_symlinkat_cleanup(struct io_kiocb *req);
/**
 * Persiapkan permintaan link (buat hard link).
 */
int io_linkat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Jalankan operasi link (buat hard link).
 */
int io_linkat(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Bersihkan resource setelah operasi link.
 */
void io_link_cleanup(struct io_kiocb *req);
