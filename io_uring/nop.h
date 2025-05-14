// SPDX-License-Identifier: GPL-2.0

/** 
 * Mempersiapkan permintaan NOP (no operation). 
 * Digunakan untuk memvalidasi parameter dan mengatur operasi NOP.
 */
int io_nop_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/** 
 * Menangani operasi NOP (no operation). 
 * Digunakan untuk menjalankan operasi NOP dengan parameter yang diberikan.
 */
int io_nop(struct io_kiocb *req, unsigned int issue_flags);
