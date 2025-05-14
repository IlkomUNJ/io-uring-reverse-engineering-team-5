// SPDX-License-Identifier: GPL-2.0

#include <linux/net.h>
#include <linux/uio.h>
#include <linux/io_uring_types.h>

#ifndef IOU_NET_H
#define IOU_NET_H

#include <linux/io_uring.h>

struct io_async_msghdr {
#if defined(CONFIG_NET)
	struct iou_vec				vec;

	struct_group(clear,
		int				namelen;
		struct iovec			fast_iov;
		__kernel_size_t			controllen;
		__kernel_size_t			payloadlen;
		struct sockaddr __user		*uaddr;
		struct msghdr			msg;
		struct sockaddr_storage		addr;
	);
#else
	struct_group(clear);
#endif
};

#if defined(CONFIG_NET)

/** 
 * Mempersiapkan permintaan shutdown pada socket. 
 * Digunakan untuk memvalidasi parameter shutdown.
 */
int io_shutdown_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/** 
 * Menangani permintaan shutdown pada socket. 
 * Digunakan untuk menutup koneksi socket secara parsial atau penuh.
 */
int io_shutdown(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Mempersiapkan permintaan sendmsg. 
 * Digunakan untuk memvalidasi parameter dan mengatur operasi sendmsg.
 */
int io_sendmsg_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/** 
 * Menangani operasi sendmsg pada socket. 
 * Digunakan untuk mengirim data melalui socket.
 */
int io_sendmsg(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Menangani operasi send pada socket. 
 * Digunakan untuk mengirim data melalui socket tanpa header pesan.
 */
int io_send(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Mempersiapkan permintaan recvmsg. 
 * Digunakan untuk memvalidasi parameter dan mengatur operasi recvmsg.
 */
int io_recvmsg_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/** 
 * Menangani operasi recvmsg pada socket. 
 * Digunakan untuk menerima data dari socket.
 */
int io_recvmsg(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Menangani operasi recv pada socket. 
 * Digunakan untuk menerima data dari socket tanpa header pesan.
 */
int io_recv(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Mempersiapkan permintaan recv dengan zero-copy. 
 * Digunakan untuk memvalidasi parameter dan mengatur operasi recv zero-copy.
 */
int io_recvzc_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/** 
 * Menangani operasi recv dengan zero-copy pada socket. 
 * Digunakan untuk menerima data dari socket dengan zero-copy.
 */
int io_recvzc(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Mempersiapkan permintaan send dengan zero-copy. 
 * Digunakan untuk memvalidasi parameter dan mengatur operasi send zero-copy.
 */
int io_send_zc_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/** 
 * Menangani operasi send dengan zero-copy pada socket. 
 * Digunakan untuk mengirim data melalui socket dengan zero-copy.
 */
int io_send_zc(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Menangani operasi sendmsg dengan zero-copy pada socket. 
 * Digunakan untuk mengirim data melalui socket dengan zero-copy.
 */
int io_sendmsg_zc(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Mempersiapkan permintaan accept pada socket. 
 * Digunakan untuk memvalidasi parameter dan mengatur operasi accept.
 */
int io_accept_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/** 
 * Menangani operasi accept pada socket. 
 * Digunakan untuk menerima koneksi baru pada socket.
 */
int io_accept(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Mempersiapkan permintaan socket. 
 * Digunakan untuk memvalidasi parameter dan mengatur operasi pembuatan socket.
 */
int io_socket_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/** 
 * Menangani operasi pembuatan socket. 
 * Digunakan untuk membuat socket baru.
 */
int io_socket(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Mempersiapkan permintaan connect pada socket. 
 * Digunakan untuk memvalidasi parameter dan mengatur operasi connect.
 */
int io_connect_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/** 
 * Menangani operasi connect pada socket. 
 * Digunakan untuk menghubungkan socket ke alamat tertentu.
 */
int io_connect(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Mempersiapkan permintaan bind pada socket. 
 * Digunakan untuk memvalidasi parameter dan mengatur operasi bind.
 */
int io_bind_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/** 
 * Menangani operasi bind pada socket. 
 * Digunakan untuk mengikat socket ke alamat tertentu.
 */
int io_bind(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Mempersiapkan permintaan listen pada socket. 
 * Digunakan untuk memvalidasi parameter dan mengatur operasi listen.
 */
int io_listen_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/** 
 * Menangani operasi listen pada socket. 
 * Digunakan untuk mendengarkan koneksi masuk pada socket.
 */
int io_listen(struct io_kiocb *req, unsigned int issue_flags);

/** 
 * Membersihkan sumber daya yang digunakan oleh operasi sendmsg atau recvmsg. 
 * Digunakan untuk membebaskan memori yang dialokasikan.
 */
void io_sendmsg_recvmsg_cleanup(struct io_kiocb *req);

/** 
 * Membebaskan cache pesan jaringan. 
 * Digunakan untuk membersihkan memori yang dialokasikan untuk pesan jaringan.
 */
void io_netmsg_cache_free(const void *entry);
#else
static inline void io_netmsg_cache_free(const void *entry)
{
}
#endif

#endif /* IOU_NET_H */
