// SPDX-License-Identifier: GPL-2.0
//Mengatur operasi statx, termasuk memvalidasi parameter, mengambil nama file, dan menandai permintaan untuk dibersihkan dan dieksekusi secara asynchronous.
int io_statx_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
//Mengimplementasikan logika utama dari operasi statx dalam io_uring.
int io_statx(struct io_kiocb *req, unsigned int issue_flags);
//Memastikan sumber daya dibersihkan dengan benar setelah operasi statx selesai dijalankan.
void io_statx_cleanup(struct io_kiocb *req);
