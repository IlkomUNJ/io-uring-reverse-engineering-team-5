// SPDX-License-Identifier: GPL-2.0

#if defined(CONFIG_EPOLL)
/**
 * Persiapkan permintaan operasi epoll_ctl.
 */
int io_epoll_ctl_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Jalankan operasi epoll_ctl.
 */
int io_epoll_ctl(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Persiapkan permintaan operasi epoll_wait.
 */
int io_epoll_wait_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Jalankan operasi epoll_wait.
 */
int io_epoll_wait(struct io_kiocb *req, unsigned int issue_flags);
#endif
