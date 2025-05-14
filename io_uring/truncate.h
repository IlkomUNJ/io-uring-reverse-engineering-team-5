// SPDX-License-Identifier: GPL-2.0

// Mempersiapkan operasi truncate dengan memvalidasi parameter dan membaca 
// panjang baru dari struktur sqe.
int io_ftruncate_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

//Melakukan operasi truncate pada file dengan panjang yang ditentukan, 
// memastikan operasi berjalan dalam konteks blocking.
int io_ftruncate(struct io_kiocb *req, unsigned int issue_flags);
