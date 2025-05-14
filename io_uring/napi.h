/* SPDX-License-Identifier: GPL-2.0 */

#ifndef IOU_NAPI_H
#define IOU_NAPI_H

#include <linux/kernel.h>
#include <linux/io_uring.h>
#include <net/busy_poll.h>

#ifdef CONFIG_NET_RX_BUSY_POLL

/** 
 * Menginisialisasi pengaturan NAPI di konteks io_uring. 
 * Digunakan untuk menyiapkan daftar dan pengaturan NAPI.
 */
void io_napi_init(struct io_ring_ctx *ctx);

/** 
 * Membebaskan daftar dan hash table NAPI di konteks io_uring. 
 * Digunakan untuk membersihkan sumber daya NAPI.
 */
void io_napi_free(struct io_ring_ctx *ctx);

/** 
 * Mendaftarkan NAPI di konteks io_uring. 
 * Digunakan untuk menambahkan atau mengubah pengaturan NAPI.
 */
int io_register_napi(struct io_ring_ctx *ctx, void __user *arg);

/** 
 * Membatalkan pendaftaran NAPI di konteks io_uring. 
 * Digunakan untuk menghapus pengaturan NAPI yang ada.
 */
int io_unregister_napi(struct io_ring_ctx *ctx, void __user *arg);

/** 
 * Menambahkan ID NAPI ke konteks io_uring. 
 * Digunakan untuk mendaftarkan ID NAPI baru.
 */
int __io_napi_add_id(struct io_ring_ctx *ctx, unsigned int napi_id);

/** 
 * Melakukan loop busy polling untuk antrean tunggu IO. 
 * Digunakan untuk memproses pekerjaan dengan busy polling.
 */
void __io_napi_busy_loop(struct io_ring_ctx *ctx, struct io_wait_queue *iowq);

/** 
 * Melakukan loop busy polling untuk SQPOLL. 
 * Digunakan untuk memproses pekerjaan SQPOLL dengan busy polling.
 */
int io_napi_sqpoll_busy_poll(struct io_ring_ctx *ctx);

/** 
 * Memeriksa apakah daftar NAPI tidak kosong. 
 * Digunakan untuk menentukan apakah ada NAPI yang terdaftar.
 */
static inline bool io_napi(struct io_ring_ctx *ctx)
{
    return !list_empty(&ctx->napi_list);
}

/** 
 * Melakukan loop busy polling untuk NAPI jika ada entri yang terdaftar. 
 * Digunakan untuk memproses pekerjaan dengan busy polling.
 */
static inline void io_napi_busy_loop(struct io_ring_ctx *ctx,
                     struct io_wait_queue *iowq)
{
    if (!io_napi(ctx))
        return;
    __io_napi_busy_loop(ctx, iowq);
}

/** 
 * Menambahkan ID NAPI dari socket ke daftar busy poll. 
 * Digunakan untuk melacak ID NAPI yang terkait dengan socket.
 */
static inline void io_napi_add(struct io_kiocb *req)
{
    struct io_ring_ctx *ctx = req->ctx;
    struct socket *sock;

    if (READ_ONCE(ctx->napi_track_mode) != IO_URING_NAPI_TRACKING_DYNAMIC)
        return;

    sock = sock_from_file(req->file);
    if (sock && sock->sk)
        __io_napi_add_id(ctx, READ_ONCE(sock->sk->sk_napi_id));
}

#else

/** 
 * Fungsi dummy untuk menginisialisasi NAPI jika CONFIG_NET_RX_BUSY_POLL tidak diaktifkan. 
 */
static inline void io_napi_init(struct io_ring_ctx *ctx)
{
}

/** 
 * Fungsi dummy untuk membebaskan NAPI jika CONFIG_NET_RX_BUSY_POLL tidak diaktifkan. 
 */
static inline void io_napi_free(struct io_ring_ctx *ctx)
{
}

/** 
 * Fungsi dummy untuk mendaftarkan NAPI jika CONFIG_NET_RX_BUSY_POLL tidak diaktifkan. 
 */
static inline int io_register_napi(struct io_ring_ctx *ctx, void __user *arg)
{
    return -EOPNOTSUPP;
}

/** 
 * Fungsi dummy untuk membatalkan pendaftaran NAPI jika CONFIG_NET_RX_BUSY_POLL tidak diaktifkan. 
 */
static inline int io_unregister_napi(struct io_ring_ctx *ctx, void __user *arg)
{
    return -EOPNOTSUPP;
}

/** 
 * Fungsi dummy untuk memeriksa apakah ada NAPI jika CONFIG_NET_RX_BUSY_POLL tidak diaktifkan. 
 */
static inline bool io_napi(struct io_ring_ctx *ctx)
{
    return false;
}

/** 
 * Fungsi dummy untuk menambahkan NAPI jika CONFIG_NET_RX_BUSY_POLL tidak diaktifkan. 
 */
static inline void io_napi_add(struct io_kiocb *req)
{
}

/** 
 * Fungsi dummy untuk melakukan busy polling jika CONFIG_NET_RX_BUSY_POLL tidak diaktifkan. 
 */
static inline void io_napi_busy_loop(struct io_ring_ctx *ctx,
                     struct io_wait_queue *iowq)
{
}

/** 
 * Fungsi dummy untuk busy polling SQPOLL jika CONFIG_NET_RX_BUSY_POLL tidak diaktifkan. 
 */
static inline int io_napi_sqpoll_busy_poll(struct io_ring_ctx *ctx)
{
    return 0;
}

#endif /* CONFIG_NET_RX_BUSY_POLL */

#endif
