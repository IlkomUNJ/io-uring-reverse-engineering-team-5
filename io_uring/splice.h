// SPDX-License-Identifier: GPL-2.0
//Mengatur operasi tee, yang menduplikasi data antar pipe tanpa mengonsumsinya.
int io_tee_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
//Mengimplementasikan logika inti dari operasi tee dalam io_uring.
int io_tee(struct io_kiocb *req, unsigned int issue_flags);
//enjamin pembersihan sumber daya dengan benar setelah operasi splice selesai.
void io_splice_cleanup(struct io_kiocb *req);
//Mengatur operasi splice, yaitu memindahkan data antar file descriptor.
int io_splice_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
//Mengimplementasikan logika inti dari operasi splice dalam io_uring.
int io_splice(struct io_kiocb *req, unsigned int issue_flags);
