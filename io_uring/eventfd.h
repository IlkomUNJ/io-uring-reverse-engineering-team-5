
struct io_ring_ctx;
/**
 * Mendaftarkan eventfd ke context io_uring.
 */
int io_eventfd_register(struct io_ring_ctx *ctx, void __user *arg,
			unsigned int eventfd_async);
/**
 * Melepas eventfd dari context io_uring.
 */
int io_eventfd_unregister(struct io_ring_ctx *ctx);

/**
 * Mengirim sinyal ke eventfd jika ada event yang belum diproses.
 */
void io_eventfd_flush_signal(struct io_ring_ctx *ctx);
/**
 * Mengambil eventfd dari context io_uring.
 */
void io_eventfd_signal(struct io_ring_ctx *ctx);
