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
| `io_issue_def`           | `io_uring/opdef.h`     | Various op-specific attributes (e.g., needs\_file, pollin, pollout, etc.), prep and issue function pointers | `io_uring/opdef.c`                                                                               | `io_issue_defs[]`      | Defines behavior for each IORING\_OP\_\* operation           |
| `io_cold_def`            | `io_uring/opdef.h`     | name, cleanup, fail handlers                                                                                | `io_uring/opdef.c`                                                                               | `io_cold_defs[]`       | Defines cold path handlers for each IORING\_OP\_\* operation |
| `io_issue_defs[]`        | `io_uring/opdef.c`     | Array of `io_issue_def` structs                                                                             | `io_uring_get_opcode`                                                                            | `io_uring/opdef.c`     | Used to validate and describe supported operations           |
|                          |                        |                                                                                                             | `io_uring_op_supported`                                                                          | `io_uring/opdef.c`     | Check if operation is supported                              |
|                          |                        |                                                                                                             | `io_uring_optable_init`                                                                          | `io_uring/opdef.c`     | Initialization and validation                                |
| `io_cold_defs[]`         | `io_uring/opdef.c`     | Array of `io_cold_def` structs                                                                              | `io_uring_get_opcode`                                                                            | `io_uring/opdef.c`     | Returns operation name string                                |
|                          |                        |                                                                                                             | `io_uring_optable_init`                                                                          | `io_uring/opdef.c`     | Initialization and validation                                |
| `io_open`                | `io_uring/openclose.c` | file, dfd, file\_slot, filename, how, nofile                                                                | `io_openat_prep`, `io_openat2_prep`, `io_openat`, `io_open_cleanup`                              | `io_uring/openclose.c` | File opening operations and preparation                      |
| `io_close`               | `io_uring/openclose.c` | file, fd, file\_slot                                                                                        | `io_close_prep`, `io_close`, `io_close_fixed`, `io_install_fixed_fd_prep`, `io_install_fixed_fd` | `io_uring/openclose.c` | File closing and fixed descriptor handling                   |
| `io_fixed_install`       | `io_uring/openclose.c` | file, o\_flags                                                                                              | `io_install_fixed_fd_prep`, `io_install_fixed_fd`                                                | `io_uring/openclose.c` | Install fixed file descriptors                               |
| `io_kiocb`               | `io_uring/openclose.h` | req, sqe                                                                                                    | `io_openat_prep`, `io_openat`, `io_open_cleanup`                                                 | `io_uring/openclose.h` | I/O control block for requests                               |
| `io_ring_ctx`            | `io_uring/openclose.h` | ctx, issue\_flags, offset                                                                                   | `__io_close_fixed`, `io_openat`, `io_open_cleanup`                                               | `io_uring/openclose.h` | Context structure for io\_uring ring handling                |
| `io_poll_update`         | `io_uring/poll.c`      | file, old\_user\_data, new\_user\_data, events, update\_events, update\_user\_data                          | N/A                                                                                              | N/A                    | Local variable for poll event updates                        |
| `io_poll_table`          | `io_uring/poll.c`      | pt, req, nr\_entries, error, owning, result\_mask                                                           | `io_poll_queue_proc`                                                                             | `io_uring/poll.c`      | Poll table operations and management                         |
| `io_poll`                | `io_uring/poll.c`      | head, events, wait                                                                                          | `io_poll_remove_entries`, `__io_poll_execute`, `io_pollfree_wake`                                | `io_uring/poll.c`      | Handling poll events                                         |
| `io_poll_wake`           | `io_uring/poll.c`      | wait, mode, sync, key                                                                                       | `io_pollfree_wake`                                                                               | `io_uring/poll.c`      | Polling wake functions for event handling                    |
| `io_poll_mark_cancelled` | `io_uring/poll.c`      | N/A                                                                                                         | `io_poll_cancel_req`                                                                             | `io_uring/poll.c`      | Mark poll events as cancelled                                |
| `io_poll_get_ownership`  | `io_uring/poll.c`      | N/A                                                                                                         | `io_poll_get_ownership_slowpath`                                                                 | `io_uring/poll.c`      | Get ownership of a poll entry                                |
| `io_poll_req_insert`     | `io_uring/poll.c`      | hash\_node                                                                                                  | `io_poll_add_hash`                                                                               | `io_uring/poll.c`      | Insert poll request into hash                                |
| `io_poll_execute`        | `io_uring/poll.c`      | mask, res                                                                                                   | `__io_poll_execute`                                                                              | `io_uring/poll.c`      | Execute poll events and actions                              |
| `io_poll_remove_entry`   | `io_uring/poll.c`      | head                                                                                                        | `io_poll_remove_entries`                                                                         | `io_uring/poll.c`      | Remove poll event entry from the queue                       |
| `io_poll_check_events`   | `io_uring/poll.c`      | tw, poll\_refs, events, cqe.res                                                                             | `io_poll_execute`                                                                                | `io_uring/poll.c`      | Check for completed poll events                              |
| `io_poll_add_hash`       | `io_uring/poll.c`      |                                                                                                             |                                                                                                  |                        | Poll request insertion into hash                             |
