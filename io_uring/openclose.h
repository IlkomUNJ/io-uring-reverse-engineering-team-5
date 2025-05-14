// SPDX-License-Identifier: GPL-2.0
/*
 * Menghapus fixed file descriptor dari konteks io_uring.
 * Menyediakan logika utama untuk menutup file descriptor tetap.
 */
int __io_close_fixed(struct io_ring_ctx *ctx, unsigned int issue_flags,
		     unsigned int offset);
/*
 * Menyiapkan operasi openat dengan menginisialisasi struktur io_open
 * dan memvalidasi field dari io_uring_sqe.
 * Memastikan operasi openat disiapkan dengan benar sebelum dijalankan.
 */
int io_openat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/*
 * Menjalankan operasi openat dengan meneruskan pemanggilan ke io_openat2.
 * Menyederhanakan penanganan openat dengan menggunakan logika openat2.
 */
int io_openat(struct io_kiocb *req, unsigned int issue_flags);

/*
 * Membersihkan sumber daya yang dialokasikan selama operasi open,
 * seperti melepas nama file yang digunakan.
 */
void io_open_cleanup(struct io_kiocb *req);

/*
 * Menyiapkan operasi openat2 dengan menyalin struktur open_how dari user space
 * dan meneruskannya ke __io_openat_prep.
 * Digunakan untuk menangani logika khusus openat2.
 */
int io_openat2_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/*
 * Menjalankan operasi openat2 dengan membangun open_flags,
 * membuka file, dan memasang file descriptor hasilnya.
 * Mencakup penanganan untuk non-blocking dan fixed file descriptor.
 */
int io_openat2(struct io_kiocb *req, unsigned int issue_flags);

/*
 * Menyiapkan operasi close dengan memvalidasi field pada io_uring_sqe
 * dan menginisialisasi struktur io_close.
 * Memastikan operasi close disiapkan dengan benar sebelum dijalankan.
 */
int io_close_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/*
 * Menjalankan operasi close dengan menutup fixed file descriptor
 * atau file descriptor biasa. Termasuk penanganan kasus khusus seperti flush.
 */
int io_close(struct io_kiocb *req, unsigned int issue_flags);

/*
 * Menyiapkan instalasi fixed file descriptor dengan memvalidasi field sqe
 * dan menginisialisasi struktur io_fixed_install.
 */
int io_install_fixed_fd_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/*
 * Menjalankan instalasi fixed file descriptor dengan menerima objek file
 * dan menerapkan flag yang ditentukan ke dalam konteks io_uring.
 */
int io_install_fixed_fd(struct io_kiocb *req, unsigned int issue_flags);
