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

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
opdef.c | /linux/kernel.h | WARN_ON_ONCE | 1
| | /linux/kernel.h | READ_ONCE | 1
| | /linux/kernel.h | WRITE_ONCE | 1
| | /linux/errno.h | -EINVAL | 1
| | /linux/errno.h | -EOPNOTSUPP | 1
| | /linux/io_uring.h | io_req_set_res | 1
| | /linux/io_uring.h | io_kiocb_to_cmd | 1
| | /linux/io_uring.h | io_prep_readv | 1
| | /linux/io_uring.h | io_read | 1
| | /linux/io_uring.h | io_prep_writev | 1
| | /linux/io_uring.h | io_write | 1
| | /linux/io_uring.h | io_fsync_prep | 1
| | /linux/io_uring.h | io_fsync | 1
| | /linux/io_uring.h | io_prep_read_fixed | 1
| | /linux/io_uring.h | io_read_fixed | 1
| | /linux/io_uring.h | io_prep_write_fixed | 1
| | /linux/io_uring.h | io_write_fixed | 1
| | /linux/io_uring.h | io_poll_add_prep | 1
| | /linux/io_uring.h | io_poll_add | 1
| | /linux/io_uring.h | io_poll_remove_prep | 1
| | /linux/io_uring.h | io_poll_remove | 1
| | /linux/io_uring.h | io_sfr_prep | 1
| | /linux/io_uring.h | io_sync_file_range | 1
| | /linux/io_uring.h | io_timeout_prep | 1
| | /linux/io_uring.h | io_timeout | 1
| | /linux/io_uring.h | io_openat_prep | 1
| | /linux/io_uring.h | io_openat | 1
| | /linux/io_uring.h | io_close_prep | 1
| | /linux/io_uring.h | io_close | 1
| | /linux/io_uring.h | io_statx_prep | 1
| | /linux/io_uring.h | io_statx | 1
| | /linux/io_uring.h | io_fallocate_prep | 1
| | /linux/io_uring.h | io_fallocate | 1
| | /linux/io_uring.h | io_splice_prep | 1
| | /linux/io_uring.h | io_splice | 1
| | /linux/io_uring.h | io_tee_prep | 1
| | /linux/io_uring.h | io_tee | 1
| | /linux/io_uring.h | io_msg_ring_prep | 1
| | /linux/io_uring.h | io_msg_ring | 1
| | /linux/io_uring.h | io_fadvise_prep | 1
| | /linux/io_uring.h | io_fadvise | 1
| | /linux/io_uring.h | io_madvise_prep | 1
| | /linux/io_uring.h | io_madvise | 1
| | /linux/io_uring.h | io_link_timeout_prep | 1
| | /linux/io_uring.h | io_no_issue | 1
| | /linux/io_uring.h | io_uring_cmd_prep | 1
| | /linux/io_uring.h | io_uring_cmd | 1
| | /linux/io_uring.h | io_readv_writev_cleanup | 1
| | /linux/io_uring.h | io_rw_fail | 1
| | /linux/io_uring.h | io_statx_cleanup | 1
| | /linux/io_uring.h | io_splice_cleanup | 1
| | notif.h | io_tx_ubuf_complete | 1
| | notif.h | io_notif_to_data | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
opdef.h | /io_uring/opdef.h | io_uring_op_supported | 1
| | /io_uring/opdef.h | io_uring_optable_init | 1
| | notif.h | io_notif_flush | 1
| | notif.h | io_notif_account_mem | 1

Source | Library | Function utilized | Time Used
-------|---------|-------------------|-----------
openclose.c | linux/fs.h | do_filp_open | 1
openclose.c | linux/file.h | fd_install | 1
openclose.c | linux/fdtable.h | file_close_fd_locked | 1
openclose.c | linux/fdtable.h | files_lookup_fd_locked | 1
openclose.c | linux/fs.h | filp_close | 1
openclose.c | linux/fs.h | flush | 1
openclose.c | linux/fs.h | force_o_largefile | 1
openclose.c | linux/namei.h | getname | 1
openclose.c | linux/fdtable.h | __get_unused_fd_flags | 1
openclose.c | io_uring.h | io_close | 1
openclose.c | io_uring.h | __io_close_fixed | 1
openclose.c | io_uring.h | io_close_fixed | 1
openclose.c | io_uring.h | io_close_prep | 1
openclose.c | io_uring.h | io_fixed_fd_install | 1
openclose.c | io_uring.h | io_fixed_fd_remove | 1
openclose.c | io_uring.h | io_install_fixed_fd | 1
openclose.c | io_uring.h | io_install_fixed_fd_prep | 1
openclose.c | io_uring.h | io_is_uring_fops | 1
openclose.c | io_uring.h | io_kiocb_to_cmd | 1
openclose.c | io_uring.h | io_openat | 1
openclose.c | io_uring.h | io_openat2 | 1
openclose.c | io_uring.h | io_openat2_prep | 1
openclose.c | io_uring.h | io_openat_force_async | 1
openclose.c | io_uring.h | __io_openat_prep | 1
openclose.c | io_uring.h | io_openat_prep | 1
openclose.c | io_uring.h | io_open_cleanup | 1
openclose.c | io_uring.h | io_req_set_res | 1
openclose.c | io_uring.h | io_ring_submit_lock | 1
openclose.c | io_uring.h | io_ring_submit_unlock | 1
openclose.c | linux/errno.h | IS_ERR | 1
openclose.c | linux/errno.h | PTR_ERR | 1
openclose.c | linux/kernel.h | READ_ONCE | 1
openclose.c | linux/kernel.h | putname | 1
openclose.c | linux/kernel.h | put_unused_fd | 1
openclose.c | linux/kernel.h | receive_fd | 1
openclose.c | linux/kernel.h | req_set_fail | 1
openclose.c | linux/kernel.h | rlimit | 1
openclose.c | linux/kernel.h | spin_lock | 1
openclose.c | linux/kernel.h | spin_unlock | 1
openclose.c | linux/kernel.h | u64_to_user_ptr | 1
openclose.c | linux/kernel.h | WARN_ON_ONCE | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
openclose.c | /io_uring/openclose.h | __io_close_fixed | 1
| | /io_uring/openclose.h | io_openat_prep | 1
| | /io_uring/openclose.h | io_openat | 1
| | /io_uring/openclose.h | io_open_cleanup | 1
| | /io_uring/openclose.h | io_openat2_prep | 1
| | /io_uring/openclose.h | io_openat2 | 1
| | /io_uring/openclose.h | io_close_prep | 1
| | /io_uring/openclose.h | io_close | 1
| | /io_uring/openclose.h | io_install_fixed_fd_prep | 1
| | /io_uring/openclose.h | io_install_fixed_fd | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
poll.c | /linux/kernel.h | READ_ONCE | 1
| | /linux/kernel.h | WARN_ON_ONCE | 1
| | /linux/errno.h | -EINVAL | 1
| | /linux/fs.h | vfs_poll | 1
| | /linux/slab.h | kmalloc | 1
| | /linux/slab.h | kfree | 1
| | /linux/poll.h | add_wait_queue | 1
| | /linux/poll.h | add_wait_queue_exclusive | 1
| | /linux/poll.h | init_waitqueue_func_entry | 1
| | /linux/poll.h | list_del_init | 1
| | /linux/poll.h | smp_load_acquire | 1
| | /linux/hashtable.h | hash_long | 1
| | /linux/hashtable.h | hlist_add_head | 1
| | /linux/hashtable.h | hlist_del_init | 1
| | /linux/hashtable.h | hlist_for_each_entry | 1
| | /linux/hashtable.h | hlist_for_each_entry_safe | 1
| | /linux/io_uring.h | io_req_set_res | 1
| | /linux/io_uring.h | io_ring_submit_lock | 1
| | /linux/io_uring.h | io_ring_submit_unlock | 1
| | /linux/io_uring.h | io_poll_remove_entries | 1
| | /linux/io_uring.h | io_poll_mark_cancelled | 1
| | /linux/io_uring.h | io_poll_get_ownership | 1
| | /linux/io_uring.h | io_poll_execute | 1
| | /linux/io_uring.h | io_poll_add_hash | 1
| | /linux/io_uring.h | io_poll_remove | 1
| | /linux/io_uring.h | io_poll_add | 1
| | /linux/io_uring.h | io_poll_cancel | 1
| | /linux/io_uring.h | io_poll_check_events | 1
| | /linux/io_uring.h | io_poll_task_func | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
poll.h | /linux/io_uring_types.h | io_poll_multishot_retry | 1
| | /io_uring/poll.h | io_poll_add_prep | 1
| | /io_uring/poll.h | io_poll_add | 1
| | /io_uring/poll.h | io_poll_remove_prep | 1
| | /io_uring/poll.h | io_poll_remove | 1
| | /io_uring/poll.h | io_poll_cancel | 1
| | /io_uring/poll.h | io_arm_poll_handler | 1
| | /io_uring/poll.h | io_poll_remove_all | 1
| | /io_uring/poll.h | io_poll_task_func | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
register.c | /linux/kernel.h | WARN_ON_ONCE | 1
| | /linux/kernel.h | READ_ONCE | 1
| | /linux/kernel.h | WRITE_ONCE | 1
| | /linux/errno.h | -EINVAL | 1
| | /linux/errno.h | -EFAULT | 1
| | /linux/errno.h | -ENOMEM | 1
| | /linux/errno.h | -EBADF | 1
| | /linux/errno.h | -EOVERFLOW | 1
| | /linux/errno.h | -EACCES | 1
| | /linux/errno.h | -EEXIST | 1
| | /linux/fs.h | fget | 1
| | /linux/fs.h | fput | 1
| | /linux/fs.h | get_file | 1
| | /linux/fs.h | put_cred | 1
| | /linux/fs.h | get_cred | 1
| | /linux/slab.h | kzalloc | 1
| | /linux/slab.h | kfree | 1
| | /linux/uaccess.h | copy_from_user | 1
| | /linux/uaccess.h | copy_to_user | 1
| | /linux/uaccess.h | memdup_user | 1
| | /linux/nospec.h | array_index_nospec | 1
| | /linux/refcount.h | refcount_inc | 1
| | /linux/io_uring.h | io_is_uring_fops | 1
| | /linux/io_uring.h | io_activate_pollwq | 1
| | /linux/io_uring.h | io_ringfd_register | 1
| | /linux/io_uring.h | io_ringfd_unregister | 1
| | /linux/io_uring.h | io_register_rsrc | 1
| | /linux/io_uring.h | io_register_rsrc_update | 1
| | /linux/io_uring.h | io_register_files_update | 1
| | /linux/io_uring.h | io_register_enable_rings | 1
| | /linux/io_uring.h | io_register_resize_rings | 1
| | /linux/io_uring.h | io_register_mem_region | 1
| | /linux/io_uring.h | io_register_clock | 1
| | /linux/io_uring.h | io_register_personality | 1
| | /linux/io_uring.h | io_unregister_personality | 1
| | /linux/io_uring.h | io_register_iowq_aff | 1
| | /linux/io_uring.h | io_unregister_iowq_aff | 1
| | /linux/io_uring.h | io_register_iowq_max_workers | 1
| | /linux/io_uring.h | io_register_pbuf_ring | 1
| | /linux/io_uring.h | io_unregister_pbuf_ring | 1
| | /linux/io_uring.h | io_register_sync_cancel | 1
| | /linux/io_uring.h | io_register_clone_buffers | 1
| | /linux/io_uring.h | io_register_zcrx_ifq | 1
| | /linux/io_uring.h | io_register_napi | 1
| | /linux/io_uring.h | io_unregister_napi | 1
| | /linux/io_uring.h | io_register_pbuf_status | 1
| | /linux/io_uring.h | io_sync_cancel | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
register.h | /io_uring/register.h | io_eventfd_unregister | 1
| | /io_uring/register.h | io_unregister_personality | 1
| | /io_uring/register.h | io_uring_register_get_file | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
rsrc.c | /linux/kernel.h | WARN_ON_ONCE | 1
| | /linux/kernel.h | READ_ONCE | 1
| | /linux/kernel.h | WRITE_ONCE | 1
| | /linux/errno.h | -EINVAL | 1
| | /linux/errno.h | -EFAULT | 1
| | /linux/errno.h | -ENOMEM | 1
| | /linux/errno.h | -ENXIO | 1
| | /linux/errno.h | -EBADF | 1
| | /linux/errno.h | -EOVERFLOW | 1
| | /linux/fs.h | fget | 1
| | /linux/fs.h | fput | 1
| | /linux/fs.h | rlimit | 1
| | /linux/slab.h | kzalloc | 1
| | /linux/slab.h | kfree | 1
| | /linux/slab.h | kvfree | 1
| | /linux/slab.h | kvmalloc | 1
| | /linux/slab.h | kvmalloc_array | 1
| | /linux/uaccess.h | copy_from_user | 1
| | /linux/uaccess.h | copy_to_user | 1
| | /linux/uaccess.h | memdup_user | 1
| | /linux/nospec.h | array_index_nospec | 1
| | /linux/io_uring.h | io_ring_submit_lock | 1
| | /linux/io_uring.h | io_ring_submit_unlock | 1
| | /linux/io_uring.h | io_req_set_res | 1
| | /linux/io_uring.h | io_is_uring_fops | 1
| | /linux/io_uring.h | io_post_aux_cqe | 1
| | /linux/io_uring.h | io_put_rsrc_node | 1
| | /linux/io_uring.h | io_reset_rsrc_node | 1
| | /linux/io_uring.h | io_file_bitmap_set | 1
| | /linux/io_uring.h | io_file_bitmap_clear | 1
| | /linux/io_uring.h | io_fixed_file_set | 1
| | /linux/io_uring.h | io_alloc_cache_init | 1
| | /linux/io_uring.h | io_alloc_cache_free | 1
| | /linux/io_uring.h | io_cache_alloc | 1
| | /linux/io_uring.h | io_cache_free | 1
| | /linux/io_uring.h | io_sqe_files_register | 1
| | /linux/io_uring.h | io_sqe_files_unregister | 1
| | /linux/io_uring.h | io_sqe_buffers_register | 1
| | /linux/io_uring.h | io_sqe_buffers_unregister | 1
| | /linux/io_uring.h | io_register_rsrc | 1
| | /linux/io_uring.h | io_register_rsrc_update | 1
| | /linux/io_uring.h | io_register_files_update | 1
| | /linux/io_uring.h | io_import_fixed | 1
| | /linux/io_uring.h | io_import_reg_buf | 1
| | /linux/io_uring.h | io_import_reg_vec | 1
| | /linux/io_uring.h | io_prep_reg_iovec | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
rsrc.h | /linux/io_uring_types.h | io_rsrc_node_alloc | 1
| | /linux/io_uring_types.h | io_free_rsrc_node | 1
| | /linux/io_uring_types.h | io_rsrc_data_free | 1
| | /linux/io_uring_types.h | io_rsrc_data_alloc | 1
| | /linux/io_uring_types.h | io_find_buf_node | 1
| | /linux/io_uring_types.h | io_import_reg_buf | 1
| | /linux/io_uring_types.h | io_import_reg_vec | 1
| | /linux/io_uring_types.h | io_prep_reg_iovec | 1
| | /linux/io_uring_types.h | io_register_clone_buffers | 1
| | /linux/io_uring_types.h | io_sqe_buffers_unregister | 1
| | /linux/io_uring_types.h | io_sqe_buffers_register | 1
| | /linux/io_uring_types.h | io_sqe_files_unregister | 1
| | /linux/io_uring_types.h | io_sqe_files_register | 1
| | /linux/io_uring_types.h | io_register_files_update | 1
| | /linux/io_uring_types.h | io_register_rsrc_update | 1
| | /linux/io_uring_types.h | io_register_rsrc | 1
| | /linux/io_uring_types.h | io_buffer_validate | 1
| | /linux/io_uring_types.h | io_check_coalesce_buffer | 1
| | /linux/io_uring_types.h | io_files_update | 1
| | /linux/io_uring_types.h | io_files_update_prep | 1
| | /linux/io_uring_types.h | __io_account_mem | 1
| | /linux/io_uring_types.h | io_vec_free | 1
| | /linux/io_uring_types.h | io_vec_realloc | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
rw.c | /linux/kernel.h | WARN_ON_ONCE | 1
| | /linux/kernel.h | READ_ONCE | 1
| | /linux/kernel.h | WRITE_ONCE | 1
| | /linux/errno.h | -EINVAL | 1
| | /linux/errno.h | -EFAULT | 1
| | /linux/errno.h | -ENOMEM | 1
| | /linux/errno.h | -EAGAIN | 1
| | /linux/errno.h | -EOPNOTSUPP | 1
| | /linux/errno.h | -EBADF | 1
| | /linux/fs.h | vfs_poll | 1
| | /linux/fs.h | rw_verify_area | 1
| | /linux/fs.h | file_start_write | 1
| | /linux/fs.h | file_end_write | 1
| | /linux/fs.h | file_inode | 1
| | /linux/fs.h | file_update_time | 1
| | /linux/slab.h | kzalloc | 1
| | /linux/slab.h | kfree | 1
| | /linux/uaccess.h | copy_from_user | 1
| | /linux/uaccess.h | copy_to_user | 1
| | /linux/uaccess.h | u64_to_user_ptr | 1
| | /linux/io_uring.h | io_req_set_res | 1
| | /linux/io_uring.h | io_req_task_complete | 1
| | /linux/io_uring.h | io_req_rw_cleanup | 1
| | /linux/io_uring.h | io_req_io_end | 1
| | /linux/io_uring.h | io_req_end_write | 1
| | /linux/io_uring.h | io_file_can_poll | 1
| | /linux/io_uring.h | io_file_supports_nowait | 1
| | /linux/io_uring.h | io_rw_should_retry | 1
| | /linux/io_uring.h | io_rw_should_reissue | 1
| | /linux/io_uring.h | io_rw_import_reg_vec | 1
| | /linux/io_uring.h | io_rw_prep_reg_vec | 1
| | /linux/io_uring.h | io_rw_init_file | 1
| | /linux/io_uring.h | io_rw_done | 1
| | /linux/io_uring.h | io_rw_fail | 1
| | /linux/io_uring.h | io_rw_cache_free | 1
| | /linux/io_uring.h | io_rw_recycle | 1
| | /linux/io_uring.h | io_complete_rw | 1
| | /linux/io_uring.h | io_complete_rw_iopoll | 1
| | /linux/io_uring.h | io_prep_rw | 1
| | /linux/io_uring.h | io_prep_read | 1
| | /linux/io_uring.h | io_prep_write | 1
| | /linux/io_uring.h | io_prep_readv | 1
| | /linux/io_uring.h | io_prep_writev | 1
| | /linux/io_uring.h | io_prep_read_fixed | 1
| | /linux/io_uring.h | io_prep_write_fixed | 1
| | /linux/io_uring.h | io_read | 1
| | /linux/io_uring.h | io_write | 1
| | /linux/io_uring.h | io_read_fixed | 1
| | /linux/io_uring.h | io_write_fixed | 1
| | /linux/io_uring.h | io_read_mshot | 1
| | /linux/io_uring.h | io_readv_writev_cleanup | 1
| | /linux/io_uring.h | io_rw_import_reg_vec | 1
| | /linux/io_uring.h | io_rw_prep_reg_vec | 1
| | /linux/io_uring.h | io_rw_init_file | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
rw.h | /linux/io_uring_types.h | io_prep_read_fixed | 1
| | /linux/io_uring_types.h | io_prep_write_fixed | 1
| | /linux/io_uring_types.h | io_prep_readv_fixed | 1
| | /linux/io_uring_types.h | io_prep_writev_fixed | 1
| | /linux/io_uring_types.h | io_prep_readv | 1
| | /linux/io_uring_types.h | io_prep_writev | 1
| | /linux/io_uring_types.h | io_prep_read | 1
| | /linux/io_uring_types.h | io_prep_write | 1
| | /linux/io_uring_types.h | io_read | 1
| | /linux/io_uring_types.h | io_write | 1
| | /linux/io_uring_types.h | io_read_fixed | 1
| | /linux/io_uring_types.h | io_write_fixed | 1
| | /linux/io_uring_types.h | io_readv_writev_cleanup | 1
| | /linux/io_uring_types.h | io_rw_fail | 1
| | /linux/io_uring_types.h | io_req_rw_complete | 1
| | /linux/io_uring_types.h | io_read_mshot_prep | 1
| | /linux/io_uring_types.h | io_read_mshot | 1
| | /linux/io_uring_types.h | io_rw_cache_free | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
splice.c | /linux/kernel.h | WARN_ON_ONCE | 1
| | /linux/kernel.h | READ_ONCE | 1
| | /linux/kernel.h | WRITE_ONCE | 1
| | /linux/errno.h | -EINVAL | 1
| | /linux/errno.h | -EBADF | 1
| | /linux/fs.h | fput | 1
| | /linux/fs.h | file_start_write | 1
| | /linux/fs.h | file_end_write | 1
| | /linux/slab.h | kzalloc | 1
| | /linux/slab.h | kfree | 1
| | /linux/uaccess.h | copy_from_user | 1
| | /linux/uaccess.h | copy_to_user | 1
| | /linux/io_uring.h | io_req_set_res | 1
| | /linux/io_uring.h | io_req_task_complete | 1
| | /linux/io_uring.h | io_ring_submit_lock | 1
| | /linux/io_uring.h | io_ring_submit_unlock | 1
| | /linux/io_uring.h | io_file_get_normal | 1
| | /linux/io_uring.h | io_put_rsrc_node | 1
| | /linux/io_uring.h | io_rsrc_node_lookup | 1
| | /linux/io_uring.h | io_slot_file | 1
| | /linux/splice.h | do_splice | 1
| | /linux/splice.h | do_tee | 1
| | /linux/splice.h | splice_direct_to_actor | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
splice.h | /io_uring/splice.h | io_tee_prep | 1
| | /io_uring/splice.h | io_tee | 1
| | /io_uring/splice.h | io_splice_cleanup | 1
| | /io_uring/splice.h | io_splice_prep | 1
| | /io_uring/splice.h | io_splice | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
sqpoll.c | /linux/kernel.h | WARN_ON_ONCE | 1
| | /linux/kernel.h | READ_ONCE | 1
| | /linux/kernel.h | WRITE_ONCE | 1
| | /linux/errno.h | -EINVAL | 1
| | /linux/errno.h | -ENOMEM | 1
| | /linux/errno.h | -ENXIO | 1
| | /linux/errno.h | -EPERM | 1
| | /linux/slab.h | kzalloc | 1
| | /linux/slab.h | kfree | 1
| | /linux/io_uring.h | io_ring_submit_lock | 1
| | /linux/io_uring.h | io_ring_submit_unlock | 1
| | /linux/io_uring.h | io_req_set_res | 1
| | /linux/io_uring.h | io_req_task_complete | 1
| | /linux/io_uring.h | io_sq_thread_park | 1
| | /linux/io_uring.h | io_sq_thread_unpark | 1
| | /linux/io_uring.h | io_sq_thread_stop | 1
| | /linux/io_uring.h | io_put_sq_data | 1
| | /linux/io_uring.h | io_sqd_update_thread_idle | 1
| | /linux/io_uring.h | io_sq_thread_finish | 1
| | /linux/io_uring.h | io_attach_sq_data | 1
| | /linux/io_uring.h | io_get_sq_data | 1
| | /linux/io_uring.h | io_sqd_events_pending | 1
| | /linux/io_uring.h | io_sq_tw | 1
| | /linux/io_uring.h | io_sq_tw_pending | 1
| | /linux/io_uring.h | io_sq_update_worktime | 1
| | /linux/io_uring.h | io_sq_thread | 1
| | /linux/io_uring.h | io_sqpoll_wait_sq | 1
| | /linux/io_uring.h | io_sq_offload_create | 1
| | /linux/io_uring.h | io_sqpoll_wq_cpu_affinity | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
sqpoll.h | /io_uring/sqpoll.h | io_sq_offload_create | 1
| | /io_uring/sqpoll.h | io_sq_thread_finish | 1
| | /io_uring/sqpoll.h | io_sq_thread_stop | 1
| | /io_uring/sqpoll.h | io_sq_thread_park | 1
| | /io_uring/sqpoll.h | io_sq_thread_unpark | 1
| | /io_uring/sqpoll.h | io_put_sq_data | 1
| | /io_uring/sqpoll.h | io_sqpoll_wait_sq | 1
| | /io_uring/sqpoll.h | io_sqpoll_wq_cpu_affinity | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
statx.c | /linux/kernel.h | WARN_ON_ONCE | 1
| | /linux/kernel.h | READ_ONCE | 1
| | /linux/kernel.h | WRITE_ONCE | 1
| | /linux/errno.h | -EINVAL | 1
| | /linux/errno.h | -EBADF | 1
| | /linux/file.h | getname_uflags | 1
| | /linux/file.h | putname | 1
| | /linux/io_uring.h | io_req_set_res | 1
| | /linux/io_uring.h | io_kiocb_to_cmd | 1
| | /linux/io_uring.h | io_statx_prep | 1
| | /linux/io_uring.h | io_statx | 1
| | /linux/io_uring.h | io_statx_cleanup | 1
| | /linux/io_uring.h | do_statx | 1
| | /linux/uaccess.h | u64_to_user_ptr | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
statx.h | /io_uring/statx.h | io_statx_prep | 1
| | /io_uring/statx.h | io_statx | 1
| | /io_uring/statx.h | io_statx_cleanup | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
sync.c | /linux/kernel.h | WARN_ON_ONCE | 1
| | /linux/kernel.h | READ_ONCE | 1
| | /linux/kernel.h | WRITE_ONCE | 1
| | /linux/errno.h | -EINVAL | 1
| | /linux/errno.h | -EFAULT | 1
| | /linux/fs.h | sync_file_range | 1
| | /linux/fs.h | vfs_fsync_range | 1
| | /linux/fs.h | vfs_fallocate | 1
| | /linux/fsnotify.h | fsnotify_modify | 1
| | /linux/io_uring.h | io_req_set_res | 1
| | /linux/io_uring.h | io_kiocb_to_cmd | 1
| | /linux/io_uring.h | io_sfr_prep | 1
| | /linux/io_uring.h | io_sync_file_range | 1
| | /linux/io_uring.h | io_fsync_prep | 1
| | /linux/io_uring.h | io_fsync | 1
| | /linux/io_uring.h | io_fallocate_prep | 1
| | /linux/io_uring.h | io_fallocate | 1

Source | Library | Function utilized | Time Used
-------|--------|-------------------|------------------
sync.h | /io_uring/sync.h | io_sfr_prep | 1
| | /io_uring/sync.h | io_sync_file_range | 1
| | /io_uring/sync.h | io_fsync_prep | 1
| | /io_uring/sync.h | io_fsync | 1
| | /io_uring/sync.h | io_fallocate_prep | 1
| | /io_uring/sync.h | io_fallocate | 1
