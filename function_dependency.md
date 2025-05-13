# Task 2: Dependency Injection
For this assigment, we want a little clarity regarding what kind of functions being imported and used on each source. Do note, we record all function actually being used by the source including function defined by itself if actually used inside the file. For the sake of completion, it's better if you straight disregard include list on the source. Instead, trace each function being used to the declared source.

Source | Libary | Function utilized | Time Used
-------|--------|--------------| ------------------
alloc_cache.h | /include/linux/kasan.h | kasan_mempool_unpoison_object | 1
| | arch/x86/include/asm/string_64.h| memset | 1
| | alloc_cache.h | io_alloc_cache_get | 1
| | alloc_cache.h | io_cache_alloc_new | 1
| | alloc_cache.h | io_alloc_cache_put | 1
| | linux/mm/slub.c | kfree | 1

Continue with the list untill all functions used in each source are listed.

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
io_uring.h | /include/linux/io_uring.h | io_req_task_complete | 1
| | /include/linux/io_uring.h | io_req_set_res | 1
| | /include/linux/io_uring.h | io_req_cqe_overflow | 1
| | /include/linux/io_uring.h | io_req_task_work_add | 1
| | io_uring.h | io_ring_ctx_alloc | 1
| | io_uring.h | io_ring_ctx_free | 1
| | io_uring.h | io_ring_submit | 1
| | io_uring.h | io_ring_cq_advance | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
io_uring.c | /include/linux/kernel.h | WARN_ON | 1
| | /include/linux/kernel.h | READ_ONCE | 1
| | /include/linux/kernel.h | WRITE_ONCE | 1
| | /include/linux/errno.h | -EINVAL | 1
| | /include/linux/errno.h | -ENOMEM | 1
| | /include/linux/fs.h | fput | 1
| | /include/linux/fs.h | get_unused_fd_flags | 1
| | /include/linux/io_uring.h | io_req_task_complete | 1
| | /include/linux/io_uring.h | io_req_set_res | 1
| | /include/linux/io_uring.h | io_req_task_work_add | 1
| | io_uring.h | io_ring_ctx_alloc | 1
| | io_uring.h | io_ring_ctx_free | 1
| | io_uring.h | io_ring_submit | 1
| | io_uring.h | io_ring_cq_advance | 1
| | io_uring.h | io_req_cqe_overflow | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
io_wq.h | /include/linux/kthread.h | kthread_create | 1
| | /include/linux/sched.h | wake_up_process | 1
| | /include/linux/slab.h | kmalloc | 1
| | /include/linux/slab.h | kfree | 1
| | io_wq.h | io_wq_create | 1
| | io_wq.h | io_wq_destroy | 1
| | io_wq.h | io_wq_enqueue | 1
| | io_wq.h | io_wq_worker | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
io_wq.c | /include/linux/kthread.h | kthread_run | 1
| | /include/linux/sched.h | schedule | 1
| | /include/linux/sched.h | set_current_state | 1
| | /include/linux/slab.h | kmalloc | 1
| | /include/linux/slab.h | kfree | 1
| | io_wq.h | io_wq_create | 1
| | io_wq.h | io_wq_destroy | 1
| | io_wq.h | io_wq_enqueue | 1
| | io_wq.h | io_wq_worker | 1
| | io_wq.c | io_wq_init | 1
| | io_wq.c | io_wq_exit | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
kbuf.h | /include/linux/uio.h | iov_iter_init | 1
| | /include/linux/uio.h | copy_from_iter | 1
| | /include/linux/uio.h | copy_to_iter | 1
| | /include/linux/slab.h | kmalloc | 1
| | /include/linux/slab.h | kfree | 1
| | kbuf.h | kbuf_alloc | 1
| | kbuf.h | kbuf_free | 1
| | kbuf.h | kbuf_copy_from_user | 1
| | kbuf.h | kbuf_copy_to_user | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
kbuf.c | /include/linux/uio.h | iov_iter_init | 1
| | /include/linux/uio.h | copy_from_iter | 1
| | /include/linux/uio.h | copy_to_iter | 1
| | /include/linux/slab.h | kmalloc | 1
| | /include/linux/slab.h | kfree | 1
| | kbuf.h | kbuf_alloc | 1
| | kbuf.h | kbuf_free | 1
| | kbuf.h | kbuf_copy_from_user | 1
| | kbuf.h | kbuf_copy_to_user | 1
| | kbuf.c | kbuf_init | 1
| | kbuf.c | kbuf_exit | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
memmap.h | /include/linux/mm.h | pfn_to_page | 1
| | /include/linux/mm.h | page_to_pfn | 1
| | /include/linux/mm.h | alloc_pages | 1
| | /include/linux/mm.h | __free_pages | 1
| | /include/linux/slab.h | kmalloc | 1
| | /include/linux/slab.h | kfree | 1
| | memmap.h | memmap_alloc | 1
| | memmap.h | memmap_free | 1
| | memmap.h | memmap_map_page | 1
| | memmap.h | memmap_unmap_page | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
memmap.c | /include/linux/mm.h | pfn_to_page | 1
| | /include/linux/mm.h | page_to_pfn | 1
| | /include/linux/mm.h | alloc_pages | 1
| | /include/linux/mm.h | __free_pages | 1
| | /include/linux/slab.h | kmalloc | 1
| | /include/linux/slab.h | kfree | 1
| | memmap.h | memmap_alloc | 1
| | memmap.h | memmap_free | 1
| | memmap.h | memmap_map_page | 1
| | memmap.h | memmap_unmap_page | 1
| | memmap.c | memmap_init | 1
| | memmap.c | memmap_exit | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
msg_ring.h | /include/linux/slab.h | kmalloc | 1
| | /include/linux/slab.h | kfree | 1
| | msg_ring.h | msg_ring_alloc | 1
| | msg_ring.h | msg_ring_free | 1
| | msg_ring.h | msg_ring_send | 1
| | msg_ring.h | msg_ring_receive | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
msg_ring.c | /include/linux/slab.h | kmalloc | 1
| | /include/linux/slab.h | kfree | 1
| | msg_ring.h | msg_ring_alloc | 1
| | msg_ring.h | msg_ring_free | 1
| | msg_ring.h | msg_ring_send | 1
| | msg_ring.h | msg_ring_receive | 1
| | msg_ring.c | msg_ring_init | 1
| | msg_ring.c | msg_ring_exit | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
napi.h | /include/linux/netdevice.h | napi_enable | 1
| | /include/linux/netdevice.h | napi_disable | 1
| | /include/linux/netdevice.h | napi_schedule | 1
| | /include/linux/netdevice.h | napi_complete | 1
| | napi.h | napi_alloc | 1
| | napi.h | napi_free | 1
| | napi.h | napi_poll | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
napi.c | /include/linux/netdevice.h | napi_enable | 1
| | /include/linux/netdevice.h | napi_disable | 1
| | /include/linux/netdevice.h | napi_schedule | 1
| | /include/linux/netdevice.h | napi_complete | 1
| | napi.h | napi_alloc | 1
| | napi.h | napi_free | 1
| | napi.h | napi_poll | 1
| | napi.c | napi_init | 1
| | napi.c | napi_exit | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
net.h | /include/linux/netdevice.h | netif_rx | 1
| | /include/linux/netdevice.h | netif_tx | 1
| | /include/linux/netdevice.h | netif_carrier_on | 1
| | /include/linux/netdevice.h | netif_carrier_off | 1
| | net.h | net_alloc | 1
| | net.h | net_free | 1
| | net.h | net_send | 1
| | net.h | net_receive | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
net.c | /include/linux/netdevice.h | netif_rx | 1
| | /include/linux/netdevice.h | netif_tx | 1
| | /include/linux/netdevice.h | netif_carrier_on | 1
| | /include/linux/netdevice.h | netif_carrier_off | 1
| | net.h | net_alloc | 1
| | net.h | net_free | 1
| | net.h | net_send | 1
| | net.h | net_receive | 1
| | net.c | net_init | 1
| | net.c | net_exit | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
nop.h | io_uring/nop.h | io_nop_prep | 1
| | io_uring/nop.h | io_nop | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
nop.c | /include/linux/kernel.h | READ_ONCE | 1
| | /include/linux/errno.h | -EINVAL | 1
| | /include/linux/fs.h | io_file_get_fixed | 1
| | /include/linux/fs.h | io_file_get_normal | 1
| | /include/linux/io_uring.h | io_req_set_res | 1
| | /include/linux/io_uring.h | req_set_fail | 1
| | nop.h | io_nop_prep | 1
| | nop.h | io_nop | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
notif.h | /include/linux/net.h | io_alloc_notif | 1
| | /include/linux/uio.h | io_tx_ubuf_complete | 1
| | /net/sock.h | io_notif_to_data | 1
| | /linux/nospec.h | io_notif_flush | 1
| | rsrc.h | io_notif_account_mem | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
notif.c | /include/linux/kernel.h | WRITE_ONCE | 1
| | /include/linux/errno.h | -EEXIST | 1
| | /include/linux/file.h | io_alloc_req | 1
| | /include/linux/slab.h | container_of | 1
| | /include/linux/net.h | net_zcopy_get | 1
| | /include/linux/net.h | skb_zcopy | 1
| | /include/linux/net.h | skb_zcopy_init | 1
| | /include/linux/io_uring.h | io_req_task_complete | 1
| | /include/linux/io_uring.h | __io_req_task_work_add | 1
| | notif.h | io_alloc_notif | 1
| | notif.h | io_tx_ubuf_complete | 1
| | notif.h | io_notif_to_data | 1
| | notif.h | io_notif_flush | 1
| | notif.h | io_notif_account_mem | 1


Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
tctx.h | /include/linux/sched.h | task_struct | 1
| | /include/linux/slab.h | kmalloc | 1
| | /include/linux/slab.h | kfree | 1
| | tctx.h | io_tctx_alloc | 1
| | tctx.h | io_tctx_free | 1
| | tctx.h | io_tctx_get | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
tctx.c | /include/linux/sched.h | task_struct | 1
| | /include/linux/slab.h | kmalloc | 1
| | /include/linux/slab.h | kfree | 1
| | /include/linux/io_uring.h | io_task_work_add | 1
| | /include/linux/io_uring.h | io_task_work_run | 1
| | tctx.h | io_tctx_alloc | 1
| | tctx.h | io_tctx_free | 1
| | tctx.h | io_tctx_get | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
timeout.h | /include/linux/time.h | ktime_get | 1
| | /include/linux/time.h | ktime_add_ns | 1
| | /include/linux/timer.h | add_timer | 1
| | /include/linux/timer.h | del_timer | 1
| | timeout.h | io_timeout_prep | 1
| | timeout.h | io_timeout | 1
| | timeout.h | io_timeout_cancel | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
timeout.c | /include/linux/time.h | ktime_get | 1
| | /include/linux/time.h | ktime_add_ns | 1
| | /include/linux/timer.h | add_timer | 1
| | /include/linux/timer.h | del_timer | 1
| | /include/linux/io_uring.h | io_req_task_complete | 1
| | timeout.h | io_timeout_prep | 1
| | timeout.h | io_timeout | 1
| | timeout.h | io_timeout_cancel | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
truncate.h | /include/linux/fs.h | vfs_truncate | 1
| | /include/linux/fs.h | vfs_fallocate | 1
| | truncate.h | io_truncate_prep | 1
| | truncate.h | io_truncate | 1
| | truncate.h | io_fallocate | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
truncate.c | /include/linux/fs.h | vfs_truncate | 1
| | /include/linux/fs.h | vfs_fallocate | 1
| | truncate.h | io_truncate_prep | 1
| | truncate.h | io_truncate | 1
| | truncate.h | io_fallocate | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
uring_cmd.h | /include/linux/io_uring.h | io_uring_cmd_prep | 1
| | /include/linux/io_uring.h | io_uring_cmd_complete | 1
| | uring_cmd.h | io_uring_cmd_exec | 1
| | uring_cmd.h | io_uring_cmd_cancel | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
uring_cmd.c | /include/linux/io_uring.h | io_uring_cmd_prep | 1
| | /include/linux/io_uring.h | io_uring_cmd_complete | 1
| | uring_cmd.h | io_uring_cmd_exec | 1
| | uring_cmd.h | io_uring_cmd_cancel | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
waitid.h | /include/linux/sched.h | task_struct | 1
| | /include/linux/wait.h | wait_event_interruptible | 1
| | /include/linux/wait.h | wake_up_process | 1
| | waitid.h | io_waitid_prep | 1
| | waitid.h | io_waitid | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
waitid.c | /include/linux/sched.h | task_struct | 1
| | /include/linux/wait.h | wait_event_interruptible | 1
| | /include/linux/wait.h | wake_up_process | 1
| | waitid.h | io_waitid_prep | 1
| | waitid.h | io_waitid | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
xattr.h | /include/linux/xattr.h | vfs_getxattr | 1
| | /include/linux/xattr.h | vfs_setxattr | 1
| | /include/linux/xattr.h | vfs_removexattr | 1
| | xattr.h | io_xattr_get_prep | 1
| | xattr.h | io_xattr_set_prep | 1
| | xattr.h | io_xattr_remove_prep | 1
| | xattr.h | io_xattr_get | 1
| | xattr.h | io_xattr_set | 1
| | xattr.h | io_xattr_remove | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
xattr.c | /include/linux/xattr.h | vfs_getxattr | 1
| | /include/linux/xattr.h | vfs_setxattr | 1
| | /include/linux/xattr.h | vfs_removexattr | 1
| | xattr.h | io_xattr_get_prep | 1
| | xattr.h | io_xattr_set_prep | 1
| | xattr.h | io_xattr_remove_prep | 1
| | xattr.h | io_xattr_get | 1
| | xattr.h | io_xattr_set | 1
| | xattr.h | io_xattr_remove | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
zcrx.h | /include/linux/net.h | skb_copy_datagram_iter | 1
| | /include/linux/net.h | skb_zcopy_clear | 1
| | /include/linux/net.h | skb_zcopy_set | 1
| | /include/linux/net.h | skb_zcopy_init | 1
| | /include/linux/uio.h | iov_iter_advance | 1
| | zcrx.h | io_zcrx_prep | 1
| | zcrx.h | io_zcrx_submit | 1
| | zcrx.h | io_zcrx_complete | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
zcrx.c | /include/linux/net.h | skb_copy_datagram_iter | 1
| | /include/linux/net.h | skb_zcopy_clear | 1
| | /include/linux/net.h | skb_zcopy_set | 1
| | /include/linux/net.h | skb_zcopy_init | 1
| | /include/linux/uio.h | iov_iter_advance | 1
| | zcrx.h | io_zcrx_prep | 1
| | zcrx.h | io_zcrx_submit | 1
| | zcrx.h | io_zcrx_complete | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
refs.h | /include/linux/refcount.h | refcount_inc | 1
| | /include/linux/refcount.h | refcount_dec_and_test | 1
| | /include/linux/refcount.h | refcount_dec | 1
| | refs.h | io_ref_get | 1
| | refs.h | io_ref_put | 1
| | refs.h | io_ref_put_and_test | 1

Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
slist.h | /include/linux/list.h | list_add | 1
| | /include/linux/list.h | list_del | 1
| | /include/linux/list.h | list_empty | 1
| | slist.h | io_slist_add | 1
| | slist.h | io_slist_del | 1
| | slist.h | io_slist_empty | 1

