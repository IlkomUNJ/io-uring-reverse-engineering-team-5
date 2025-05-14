// SPDX-License-Identifier: GPL-2.0

// Membersihkan sumber daya terkait operasi xattr, termasuk nama file dan nilai atribut.
void io_xattr_cleanup(struct io_kiocb *req);

// Mempersiapkan operasi fsetxattr dengan memvalidasi parameter dan menyalin nilai atribut.
int io_fsetxattr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Melakukan operasi fsetxattr pada file yang diberikan dan menyelesaikan permintaan.
int io_fsetxattr(struct io_kiocb *req, unsigned int issue_flags);

// Mempersiapkan operasi setxattr dengan memvalidasi parameter dan mendapatkan nama file.
int io_setxattr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Melakukan operasi setxattr pada nama file yang diberikan dan menyelesaikan permintaan.
int io_setxattr(struct io_kiocb *req, unsigned int issue_flags);

// Mempersiapkan operasi fgetxattr dengan memvalidasi parameter dan mengimpor nama atribut.
int io_fgetxattr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Melakukan operasi fgetxattr pada file yang diberikan dan menyelesaikan permintaan.
int io_fgetxattr(struct io_kiocb *req, unsigned int issue_flags);

// Mempersiapkan operasi getxattr dengan memvalidasi parameter dan mendapatkan nama file.
int io_getxattr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Melakukan operasi getxattr pada nama file yang diberikan dan menyelesaikan permintaan.
int io_getxattr(struct io_kiocb *req, unsigned int issue_flags);
