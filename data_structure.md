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
