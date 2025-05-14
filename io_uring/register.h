// SPDX-License-Identifier: GPL-2.0
#ifndef IORING_REGISTER_H
#define IORING_REGISTER_H

/*
 * Menghapus eventfd dari konteks io_uring.
 * Digunakan untuk membersihkan dan menghapus eventfd
 * yang sebelumnya telah didaftarkan dalam instance io_uring.
 */
int io_eventfd_unregister(struct io_ring_ctx *ctx);


/*
 * Menghapus personality dari konteks io_uring berdasarkan ID-nya
 * dan melepaskan kredensial yang terkait.
 * Memastikan pembersihan personality yang telah didaftarkan.
 */
int io_unregister_personality(struct io_ring_ctx *ctx, unsigned id);

/*
 * Mengambil file berdasarkan file descriptor yang diberikan.
 * Jika 'registered' bernilai true, file diambil dari ring yang
 * telah didaftarkan; jika tidak, dari tabel file biasa.
 * Mendukung akses ke file baik yang terdaftar maupun tidak
 * dalam operasi io_uring.
 */
struct file *io_uring_register_get_file(unsigned int fd, bool registered);

#endif
