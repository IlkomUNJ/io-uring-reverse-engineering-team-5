// SPDX-License-Identifier: GPL-2.0

/** 
 * Menangani permintaan MSG_RING secara sinkron. 
 * Digunakan untuk memproses permintaan MSG_RING tanpa thread tambahan.
 */
int io_uring_sync_msg_ring(struct io_uring_sqe *sqe);

/** 
 * Mempersiapkan permintaan MSG_RING untuk eksekusi. 
 * Digunakan untuk memvalidasi dan mengatur parameter permintaan.
 */
int io_msg_ring_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/** 
 * Menangani permintaan MSG_RING untuk data atau file. 
 * Digunakan untuk memproses permintaan MSG_RING berdasarkan jenisnya.
 */
int io_msg_ring(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Membersihkan sumber daya yang digunakan oleh permintaan MSG_RING. 
 * Digunakan untuk membebaskan file sumber setelah operasi selesai.
 */
void io_msg_ring_cleanup(struct io_kiocb *req);
