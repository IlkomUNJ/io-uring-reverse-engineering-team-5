# Task 3: Data Structure Investigation
The objective of this task is to document all internal data structures defined in io_uring. 

Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_ev_fd       | io_uring/eventfd.c | eventfd_ctx, uint, uint, refcount_t, atomic_t, rcu_head | io_eventfd_free | io_uring/eventfd.c | local variable
| | | | io_eventfd_put | io_uring/eventfd.c | function parameter
| | | | io_eventfd_do_signal | io_uring/eventfd.c | local variable, function parameter
| | | | __io_eventfd_signal | io_uring/eventfd.c | function parameter
| | | | io_eventfd_grab | io_uring/eventfd.c | return value, local variable
| | | | io_eventfd_signal | io_uring/eventfd.c | local variable 
| | | | io_eventfd_flush_signal | io_uring/eventfd.c | local variable
| | | | io_eventfd_register | io_uring/eventfd.c | local variable
| | | | io_eventfd_unregister | io_uring/eventfd.c | function parameter

If the following row value in a column is missing, assume the value is the same with the previous row in the same column. 
Continue until all data structures documented properly.

Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_ev_fd       | io_uring/eventfd.c | eventfd_ctx, uint, uint, refcount_t, atomic_t, rcu_head | io_eventfd_free | io_uring/eventfd.c | local variable
| | | | io_eventfd_put | io_uring/eventfd.c | function parameter
| | | | io_eventfd_do_signal | io_uring/eventfd.c | local variable, function parameter
| | | | __io_eventfd_signal | io_uring/eventfd.c | function parameter
| | | | io_eventfd_grab | io_uring/eventfd.c | return value, local variable
| | | | io_eventfd_signal | io_uring/eventfd.c | local variable
| | | | io_eventfd_flush_signal | io_uring/eventfd.c | local variable
| | | | io_eventfd_register | io_uring/eventfd.c | local variable
| | | | io_eventfd_unregister | io_uring/eventfd.c | function parameter
io_ring_ctx    | io_uring/io_uring.h | refs, sq_ring, cq_ring, sqo_mm, cq_mm | io_ring_ctx_alloc | io_uring/io_uring.c | return value
| | | | io_ring_ctx_free | io_uring/io_uring.c | function parameter
| | | | io_ring_submit | io_uring/io_uring.c | local variable
| | | | io_ring_cq_advance | io_uring/io_uring.c | function parameter
| | | | io_ring_ctx_wait_and_kill | io_uring/io_uring.c | local variable
| | | | io_ring_ctx_get | io_uring/io_uring.c | return value
| | | | io_ring_ctx_put | io_uring/io_uring.c | function parameter
io_kiocb       | io_uring/io_uring.h | file, opcode, flags, user_data, result | io_req_task_complete | io_uring/io_uring.c | function parameter
| | | | io_req_set_res | io_uring/io_uring.c | function parameter
| | | | io_req_task_work_add | io_uring/io_uring.c | function parameter
| | | | io_req_cqe_overflow | io_uring/io_uring.c | local variable
| | | | io_req_defer | io_uring/io_uring.c | local variable
| | | | io_req_complete_post | io_uring/io_uring.c | local variable
io_cqring_offsets | io_uring/io_uring.h | head, tail, ring_mask, ring_entries, overflow | io_ring_cq_advance | io_uring/io_uring.c | local variable
| | | | io_ring_submit | io_uring/io_uring.c | local variable
| | | | io_req_cqe_overflow | io_uring/io_uring.c | local variable
io_sqring_offsets | io_uring/io_uring.h | head, tail, ring_mask, ring_entries, flags | io_ring_submit | io_uring/io_uring.c | local variable
| | | | io_ring_ctx_alloc | io_uring/io_uring.c | local variable
io_wq          | io_uring/io_wq.h | work_list, hash, unbound_list | io_wq_create | io_uring/io_wq.c | return value
| | | | io_wq_destroy | io_uring/io_wq.c | function parameter
| | | | io_wq_enqueue | io_uring/io_wq.c | function parameter
| | | | io_wq_worker | io_uring/io_wq.c | local variable
kbuf           | io_uring/kbuf.h | buf, len, offset | kbuf_alloc | io_uring/kbuf.c | return value
| | | | kbuf_free | io_uring/kbuf.c | function parameter
| | | | kbuf_copy_from_user | io_uring/kbuf.c | function parameter
| | | | kbuf_copy_to_user | io_uring/kbuf.c | function parameter
memmap         | io_uring/memmap.h | pages, size, flags | memmap_alloc | io_uring/memmap.c | return value
| | | | memmap_free | io_uring/memmap.c | function parameter
| | | | memmap_map_page | io_uring/memmap.c | function parameter
| | | | memmap_unmap_page | io_uring/memmap.c | function parameter
msg_ring       | io_uring/msg_ring.h | ring, size, flags | msg_ring_alloc | io_uring/msg_ring.c | return value
| | | | msg_ring_free | io_uring/msg_ring.c | function parameter
| | | | msg_ring_send | io_uring/msg_ring.c | function parameter
| | | | msg_ring_receive | io_uring/msg_ring.c | function parameter
napi           | io_uring/napi.h | napi_struct, poll_list | napi_alloc | io_uring/napi.c | return value
| | | | napi_free | io_uring/napi.c | function parameter
| | | | napi_poll | io_uring/napi.c | function parameter
net            | io_uring/net.h | net_device, flags | net_alloc | io_uring/net.c | return value
| | | | net_free | io_uring/net.c | function parameter
| | | | net_send | io_uring/net.c | function parameter
| | | | net_receive | io_uring/net.c | function parameter
io_nop         | io_uring/nop.h | file, result, fd, flags | io_nop_prep | io_uring/nop.c | function parameter
| | | | io_nop | io_uring/nop.c | function parameter
io_notif_data  | io_uring/notif.h | file, uarg, next, head, account_pages, zc_report, zc_used, zc_copied | io_alloc_notif | io_uring/notif.c | return value
| | | | io_tx_ubuf_complete | io_uring/notif.c | function parameter
| | | | io_notif_to_data | io_uring/notif.c | function parameter
| | | | io_notif_flush | io_uring/notif.c | function parameter
| | | | io_notif_account_mem | io_uring/notif.c | function parameter
io_issue_def   | io_uring/opdef.h | needs_file, plug, ioprio, iopoll, buffer_select, hash_reg_file, unbound_nonreg_file, pollin, pollout, poll_exclusive, audit_skip, iopoll_queue, vectored, async_size | io_issue_defs | io_uring/opdef.c | local variable
| | | | io_cold_defs | io_uring/opdef.c | local variable
| | | | io_uring_op_supported | io_uring/opdef.c | function parameter
| | | | io_uring_optable_init | io_uring/opdef.c | local variable

Structure name | Defined in | Attributes | Caller Functions Source | source caller | usage
---------------|------------|------------|-------------------------|---------------|-------------------
io_issue_def   | io_uring/opdef.h | Various op-specific attributes (e.g., needs_file, pollin, pollout, etc.), prep and issue function pointers | io_uring/opdef.c | io_issue_defs[] | Defines behavior for each IORING_OP_* operation
| | | | io_uring_get_opcode | io_uring/opdef.c | Used to validate and describe supported operations
| | | | io_uring_op_supported | io_uring/opdef.c | Check if operation is supported
| | | | io_uring_optable_init | io_uring/opdef.c | Initialization and validation
io_cold_def    | io_uring/opdef.h | name, cleanup, fail handlers | io_uring/opdef.c | io_cold_defs[] | Defines cold path handlers for each IORING_OP_* operation
| | | | io_uring_get_opcode | io_uring/opdef.c | Returns operation name string
| | | | io_uring_optable_init | io_uring/opdef.c | Initialization and validation
io_open         | io_uring/openclose.c | file, dfd, file_slot, filename, how, nofile | io_openat_prep | io_uring/openclose.c | File opening operations and preparation
| | | | io_openat2_prep | io_uring/openclose.c | File opening operations and preparation
| | | | io_openat | io_uring/openclose.c | File opening operations and preparation
| | | | io_open_cleanup | io_uring/openclose.c | File opening operations and preparation
io_close        | io_uring/openclose.c | file, fd, file_slot | io_close_prep | io_uring/openclose.c | File closing and fixed descriptor handling
| | | | io_close | io_uring/openclose.c | File closing and fixed descriptor handling
| | | | io_close_fixed | io_uring/openclose.c | File closing and fixed descriptor handling
| | | | io_install_fixed_fd_prep | io_uring/openclose.c | File closing and fixed descriptor handling
| | | | io_install_fixed_fd | io_uring/openclose.c | File closing and fixed descriptor handling
io_fixed_install | io_uring/openclose.c | file, o_flags | io_install_fixed_fd_prep | io_uring/openclose.c | Install fixed file descriptors
| | | | io_install_fixed_fd | io_uring/openclose.c | Install fixed file descriptors
io_kiocb        | io_uring/openclose.h | req, sqe | io_openat_prep | io_uring/openclose.h | I/O control block for requests
| | | | io_openat | io_uring/openclose.h | I/O control block for requests
| | | | io_open_cleanup | io_uring/openclose.h | I/O control block for requests
io_ring_ctx     | io_uring/openclose.h | ctx, issue_flags, offset | __io_close_fixed | io_uring/openclose.h | Context structure for io_uring ring handling
| | | | io_openat | io_uring/openclose.h | Context structure for io_uring ring handling
| | | | io_open_cleanup | io_uring/openclose.h | Context structure for io_uring ring handling
io_poll_update  | io_uring/poll.c | file, old_user_data, new_user_data, events, update_events, update_user_data | N/A | N/A | Local variable for poll event updates
io_poll_table   | io_uring/poll.c | pt, req, nr_entries, error, owning, result_mask | io_poll_queue_proc | io_uring/poll.c | Poll table operations and management
io_poll         | io_uring/poll.c | head, events, wait | io_poll_remove_entries | io_uring/poll.c | Handling poll events
| | | | __io_poll_execute | io_uring/poll.c | Handling poll events
| | | | io_pollfree_wake | io_uring/poll.c | Handling poll events
io_poll_wake    | io_uring/poll.c | wait, mode, sync, key | io_pollfree_wake | io_uring/poll.c | Polling wake functions for event handling
io_poll_mark_cancelled | io_uring/poll.c | N/A | io_poll_cancel_req | io_uring/poll.c | Mark poll events as cancelled
io_poll_get_ownership | io_uring/poll.c | N/A | io_poll_get_ownership_slowpath | io_uring/poll.c | Get ownership of a poll entry
io_poll_req_insert | io_uring/poll.c | hash_node | io_poll_add_hash | io_uring/poll.c | Insert poll request into hash
io_poll_execute | io_uring/poll.c | mask, res | __io_poll_execute | io_uring/poll.c | Execute poll events and actions
io_poll_remove_entry | io_uring/poll.c | head | io_poll_remove_entries | io_uring/poll.c | Remove poll event entry from the queue
io_poll_check_events | io_uring/poll.c | tw, poll_refs, events, cqe.res | io_poll_execute | io_uring/poll.c | Check for completed poll events
io_poll_add_hash | io_uring/poll.c | N/A | io_poll_req_insert | io_uring/poll.c | Poll request insertion into hash
io_sync        | io_uring/sync.c | file, len, off, flags, mode | io_sfr_prep | io_uring/sync.c | local variable
| | | | io_sync_file_range | io_uring/sync.c | local variable
| | | | io_fsync_prep | io_uring/sync.c | local variable
| | | | io_fsync | io_uring/sync.c | local variable
| | | | io_fallocate_prep | io_uring/sync.c | local variable
| | | | io_fallocate | io_uring/sync.c | local variable
io_sync        | io_uring/sync.h | file, len, off, flags, mode | io_sfr_prep | io_uring/sync.c | function parameter
| | | | io_sync_file_range | io_uring/sync.c | function parameter
| | | | io_fsync_prep | io_uring/sync.c | function parameter
| | | | io_fsync | io_uring/sync.c | function parameter
| | | | io_fallocate_prep | io_uring/sync.c | function parameter
| | | | io_fallocate | io_uring/sync.c | function parameter
io_uring_task  | io_uring/tctx.c | io_wq, percpu_counter, xa, waitqueue_head, atomic_t, task_struct, llist_head, task_work | io_uring_alloc_task_context | io_uring/tctx.c | local variable, function parameter, return value
| | | | __io_uring_free | io_uring/tctx.c | local variable
| | | | io_uring_clean_tctx | io_uring/tctx.c | function parameter
| | | | io_ring_add_registered_file | io_uring/tctx.c | function parameter
| | | | io_ring_add_registered_fd | io_uring/tctx.c | function parameter
| | | | io_ringfd_register | io_uring/tctx.c | local variable
| | | | io_ringfd_unregister | io_uring/tctx.c | local variable
io_tctx_node   | io_uring/tctx.c | io_ring_ctx, task_struct, list_head | __io_uring_add_tctx_node | io_uring/tctx.c | local variable
| | | | __io_uring_add_tctx_node_from_submit | io_uring/tctx.c | local variable
| | | | io_uring_del_tctx_node | io_uring/tctx.c | local variable
io_wq_hash     | io_uring/tctx.c | refs, waitqueue_head | io_init_wq_offload | io_uring/tctx.c | local variable
io_wq_data     | io_uring/tctx.c | hash, task_struct, free_work, do_work | io_init_wq_offload | io_uring/tctx.c | local variable
io_tctx_node   | io_uring/tctx.h | list_head, task_struct, io_ring_ctx | io_uring_alloc_task_context | io_uring/tctx.c | local variable
| | | | io_uring_del_tctx_node | io_uring/tctx.c | function parameter
| | | | __io_uring_add_tctx_node | io_uring/tctx.c | local variable
| | | | __io_uring_add_tctx_node_from_submit | io_uring/tctx.c | local variable
| | | | io_uring_clean_tctx | io_uring/tctx.c | function parameter
io_uring_task  | io_uring/tctx.h | task_struct, io_ring_ctx, list_head | io_uring_add_tctx_node | io_uring/tctx.c | local variable
| | | | io_ringfd_register | io_uring/tctx.c | function parameter
| | | | io_ringfd_unregister | io_uring/tctx.c | function parameter
io_timeout      | io_uring/timeout.c | file, off, target_seq, repeats, list, head, prev | io_timeout_prep | io_uring/timeout.c | local variable
| | | | io_timeout | io_uring/timeout.c | local variable
| | | | io_timeout_cancel | io_uring/timeout.c | local variable
| | | | io_timeout_remove | io_uring/timeout.c | local variable
| | | | io_timeout_update | io_uring/timeout.c | local variable
| | | | io_queue_linked_timeout | io_uring/timeout.c | local variable
io_timeout_rem  | io_uring/timeout.c | file, addr, ts, flags, ltimeout | io_timeout_remove_prep | io_uring/timeout.c | local variable
| | | | io_timeout_remove | io_uring/timeout.c | local variable
io_timeout_data | io_uring/timeout.h | req, timer, ts, mode, flags | io_timeout_prep | io_uring/timeout.c | local variable
| | | | io_timeout | io_uring/timeout.c | local variable
| | | | io_timeout_cancel | io_uring/timeout.c | local variable
| | | | io_kill_timeouts | io_uring/timeout.c | function parameter
| | | | io_queue_linked_timeout | io_uring/timeout.c | function parameter
io_ftrunc      | io_uring/truncate.c | file, len | io_ftruncate_prep | io_uring/truncate.c | local variable
| | | | io_ftruncate | io_uring/truncate.c | local variable
io_ftrunc      | io_uring/truncate.h | file, len | io_ftruncate_prep | io_uring/truncate.c | function parameter
| | | | io_ftruncate | io_uring/truncate.c | function parameter
io_uring_cmd   | io_uring/uring_cmd.c | sqe, flags, cmd_op, task_work_cb | io_uring_cmd_prep | io_uring/uring_cmd.c | local variable
| | | | io_uring_cmd | io_uring/uring_cmd.c | local variable
| | | | io_uring_cmd_done | io_uring/uring_cmd.c | function parameter
| | | | io_uring_cmd_mark_cancelable | io_uring/uring_cmd.c | function parameter
| | | | io_uring_cmd_sock | io_uring/uring_cmd.c | function parameter
io_async_cmd   | io_uring/uring_cmd.c | vec, data | io_req_uring_cleanup | io_uring/uring_cmd.c | local variable
| | | | io_uring_cmd_prep_setup | io_uring/uring_cmd.c | local variable
| | | | io_uring_cmd_import_fixed_vec | io_uring/uring_cmd.c | local variable
io_uring_cmd_data | io_uring/uring_cmd.c | op_data | io_req_uring_cleanup | io_uring/uring_cmd.c | local variable
io_async_cmd   | io_uring/uring_cmd.h | data, vec, sqes | io_uring_cmd | io_uring/uring_cmd.c | function parameter
| | | | io_uring_cmd_prep | io_uring/uring_cmd.c | local variable
| | | | io_uring_cmd_cleanup | io_uring/uring_cmd.c | function parameter
io_uring_cmd   | io_uring/uring_cmd.h | sqe, flags, cmd_op, task_work_cb | io_uring_cmd_import_fixed_vec | io_uring/uring_cmd.c | function parameter
io_uring_cmd_data | io_uring/uring_cmd.h | op_data | io_cmd_cache_free | io_uring/uring_cmd.c | local variable
io_waitid      | io_uring/waitid.c | file, which, upid, options, refs, head, infop, info | io_waitid_prep | io_uring/waitid.c | local variable
| | | | io_waitid | io_uring/waitid.c | local variable
| | | | io_waitid_free | io_uring/waitid.c | function parameter
| | | | io_waitid_copy_si | io_uring/waitid.c | local variable
| | | | io_waitid_finish | io_uring/waitid.c | function parameter
| | | | io_waitid_complete | io_uring/waitid.c | local variable
| | | | __io_waitid_cancel | io_uring/waitid.c | function parameter
| | | | io_waitid_remove_all | io_uring/waitid.c | function parameter
io_waitid_async | io_uring/waitid.c | wo, req | io_waitid_prep | io_uring/waitid.c | local variable
| | | | io_waitid_free | io_uring/waitid.c | function parameter
| | | | io_waitid_cb | io_uring/waitid.c | local variable
| | | | io_waitid_wait | io_uring/waitid.c | local variable
io_waitid_async | io_uring/waitid.h | req, wo | io_waitid_prep | io_uring/waitid.c | function parameter
| | | | io_waitid | io_uring/waitid.c | local variable
| | | | io_waitid_cancel | io_uring/waitid.c | function parameter
| | | | io_waitid_remove_all | io_uring/waitid.c | function parameter
io_xattr       | io_uring/xattr.c | file, ctx, filename | io_xattr_cleanup | io_uring/xattr.c | function parameter
| | | | io_xattr_finish | io_uring/xattr.c | local variable
| | | | __io_getxattr_prep | io_uring/xattr.c | local variable
| | | | io_fgetxattr_prep | io_uring/xattr.c | local variable
| | | | io_getxattr_prep | io_uring/xattr.c | local variable
| | | | io_fgetxattr | io_uring/xattr.c | local variable
| | | | io_getxattr | io_uring/xattr.c | local variable
| | | | __io_setxattr_prep | io_uring/xattr.c | local variable
| | | | io_setxattr_prep | io_uring/xattr.c | local variable
| | | | io_fsetxattr_prep | io_uring/xattr.c | local variable
| | | | io_fsetxattr | io_uring/xattr.c | local variable
| | | | io_setxattr | io_uring/xattr.c | local variable
io_xattr       | io_uring/xattr.h | file, ctx, filename | io_xattr_cleanup | io_uring/xattr.c | function parameter
| | | | io_fsetxattr_prep | io_uring/xattr.c | function parameter
| | | | io_fsetxattr | io_uring/xattr.c | function parameter
| | | | io_setxattr_prep | io_uring/xattr.c | function parameter
| | | | io_setxattr | io_uring/xattr.c | function parameter
| | | | io_fgetxattr_prep | io_uring/xattr.c | function parameter
| | | | io_fgetxattr | io_uring/xattr.c | function parameter
| | | | io_getxattr_prep | io_uring/xattr.c | function parameter
| | | | io_getxattr | io_uring/xattr.c | function parameter
io_zcrx_area   | io_uring/zcrx.c | nia, pages, freelist, user_refs, free_count, is_mapped, ifq, area_id | io_zcrx_create_area | io_uring/zcrx.c | return value, local variable
| | | | io_zcrx_free_area | io_uring/zcrx.c | function parameter
| | | | io_zcrx_map_area | io_uring/zcrx.c | function parameter
| | | | io_zcrx_unmap_area | io_uring/zcrx.c | function parameter
| | | | io_zcrx_scrub | io_uring/zcrx.c | local variable
| | | | io_zcrx_alloc_fallback | io_uring/zcrx.c | return value
| | | | io_zcrx_recv_frag | io_uring/zcrx.c | local variable
io_zcrx_ifq    | io_uring/zcrx.c | dev, netdev, ctx, area, rq_ring, rqes, rq_entries, cached_rq_head, lock, rq_lock | io_zcrx_ifq_alloc | io_uring/zcrx.c | return value
| | | | io_zcrx_ifq_free | io_uring/zcrx.c | function parameter
| | | | io_register_zcrx_ifq | io_uring/zcrx.c | local variable
| | | | io_unregister_zcrx_ifqs | io_uring/zcrx.c | local variable
| | | | io_zcrx_tcp_recvmsg | io_uring/zcrx.c | function parameter
io_zcrx_args   | io_uring/zcrx.c | req, ifq, sock, nr_skbs | io_zcrx_recv_skb | io_uring/zcrx.c | local variable
| | | | io_zcrx_tcp_recvmsg | io_uring/zcrx.c | local variable
io_zcrx_area   | io_uring/zcrx.h | nia, ifq, user_refs, is_mapped, area_id, pages, freelist_lock, free_count, freelist | io_register_zcrx_ifq | io_uring/zcrx.c | function parameter
| | | | io_unregister_zcrx_ifqs | io_uring/zcrx.c | function parameter
| | | | io_zcrx_recv | io_uring/zcrx.c | function parameter
io_zcrx_ifq    | io_uring/zcrx.h | ctx, area, rq_ring, rqes, rq_entries, cached_rq_head, rq_lock, if_rxq, dev, netdev, netdev_tracker, lock | io_register_zcrx_ifq | io_uring/zcrx.c | function parameter
| | | | io_unregister_zcrx_ifqs | io_uring/zcrx.c | function parameter
| | | | io_shutdown_zcrx_ifqs | io_uring/zcrx.c | function parameter
| | | | io_zcrx_recv | io_uring/zcrx.c | function parameter
io_kiocb       | io_uring/refs.h | refs, flags | req_ref_inc_not_zero | io_uring/refs.h | function parameter
| | | | req_ref_put_and_test_atomic | io_uring/refs.h | function parameter
| | | | req_ref_put_and_test | io_uring/refs.h | function parameter
| | | | req_ref_get | io_uring/refs.h | function parameter
| | | | req_ref_put | io_uring/refs.h | function parameter
| | | | __io_req_set_refcount | io_uring/refs.h | function parameter
| | | | io_req_set_refcount | io_uring/refs.h | function parameter
io_wq_work_node | io_uring/slist.h | next | wq_list_add_after | io_uring/slist.h | function parameter
| | | | wq_list_add_tail | io_uring/slist.h | function parameter
| | | | wq_list_add_head | io_uring/slist.h | function parameter
| | | | wq_list_cut | io_uring/slist.h | function parameter
| | | | wq_stack_add_head | io_uring/slist.h | function parameter
| | | | wq_list_del | io_uring/slist.h | function parameter
| | | | wq_stack_extract | io_uring/slist.h | return value
io_wq_work_list | io_uring/slist.h | first, last | wq_list_add_after | io_uring/slist.h | function parameter
| | | | wq_list_add_tail | io_uring/slist.h | function parameter
| | | | wq_list_add_head | io_uring/slist.h | function parameter
| | | | wq_list_cut | io_uring/slist.h | function parameter
| | | | __wq_list_splice | io_uring/slist.h | function parameter
| | | | wq_list_splice | io_uring/slist.h | function parameter
| | | | wq_list_del | io_uring/slist.h | function parameter
io_wq_work     | io_uring/slist.h | list | wq_next_work | io_uring/slist.h | return value