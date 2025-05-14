// SPDX-License-Identifier: GPL-2.0

// Mempersiapkan dan memvalidasi parameter untuk operasi sync_file_range.
int io_sfr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Melakukan sinkronisasi rentang file dalam konteks blocking.
int io_sync_file_range(struct io_kiocb *req, unsigned int issue_flags);


// Mempersiapkan dan memvalidasi parameter untuk operasi fsync.
int io_fsync_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Menyinkronkan file dengan mendukung sinkronisasi penuh atau metadata saja.
int io_fsync(struct io_kiocb *req, unsigned int issue_flags);


// Mengalokasikan ruang file dan memicu notifikasi modifikasi jika berhasil.
int io_fallocate(struct io_kiocb *req, unsigned int issue_flags);

// Mempersiapkan dan memvalidasi parameter untuk operasi fallocate.
int io_fallocate_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
