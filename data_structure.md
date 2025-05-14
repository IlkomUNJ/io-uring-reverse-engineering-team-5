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
io_issue_def   | io_uring/opdef.h | Various op-specific attributes (needs_file, pollin, pollout, etc.), prep and issue function pointers | io_uring/opdef.c | io_issue_defs[] array | Defines behavior for each IORING_OP_* operation
io_cold_def    | io_uring/opdef.h | name, cleanup, fail handlers | io_uring/opdef.c | io_cold_defs[] array | Defines cold path handlers for each IORING_OP_* operation
io_issue_defs[]| io_uring/opdef.c | Array of io_issue_def structs | io_uring_get_opcode | io_uring/opdef.c | Used to validate and describe supported operations
| | | io_uring_op_supported | io_uring/opdef.c | Check if operation is supported
| | | io_uring_optable_init | io_uring/opdef.c | Initialization and validation
io_cold_defs[] | io_uring/opdef.c | Array of io_cold_def structs | io_uring_get_opcode | io_uring/opdef.c | Returns operation name string
| | | io_uring_optable_init | io_uring/opdef.c | Initialization and validation
io_issue_def   | io_uring/opdef.h | needs_file, plug, ioprio, iopoll, buffer_select, hash_reg_file, unbound_nonreg_file, pollin, pollout, poll_exclusive, audit_skip, iopoll_queue, vectored, async_size, issue function pointer, prep function pointer | io_uring/opdef.c | io_issue_defs[] array | Defines behavior for each IORING_OP_* operation
| | | | io_uring_get_opcode | io_uring/opdef.c | Operation name lookup
| | | | io_uring_op_supported | io_uring/opdef.c | Operation support check
| | | | io_uring_optable_init | io_uring/opdef.c | Initialization and validation
io_cold_def    | io_uring/opdef.h | name, cleanup function pointer, fail function pointer | io_uring/opdef.c | io_cold_defs[] array | Defines cold path handlers for operations
| | | | io_uring_get_opcode | io_uring/opdef.c | Operation name lookup
| | | | io_uring_optable_init | io_uring/opdef.c | Initialization and validation
io_issue_defs[]| io_uring/opdef.h | extern array declaration | io_uring/opdef.c | Actual array definition | Provides operation definitions to io_uring subsystem
io_cold_defs[] | io_uring/opdef.h | extern array declaration | io_uring/opdef.c | Actual array definition | Provides cold path handlers to io_uring subsystem
| io\_open           | io\_uring/openclose.c | file, dfd, file\_slot, filename, how, nofile | \_\_io\_openat\_prep         | io\_uring/openclose.c | function parameter |
|                    |                       |                                              | io\_openat\_prep             | io\_uring/openclose.c | function parameter |
|                    |                       |                                              | io\_openat2\_prep            | io\_uring/openclose.c | function parameter |
|                    |                       |                                              | io\_openat2                  | io\_uring/openclose.c | function parameter |
|                    |                       |                                              | io\_openat                   | io\_uring/openclose.c | function parameter |
|                    |                       |                                              | io\_open\_cleanup            | io\_uring/openclose.c | function parameter |
| io\_close          | io\_uring/openclose.c | file, fd, file\_slot                         | io\_close\_prep              | io\_uring/openclose.c | function parameter |
|                    |                       |                                              | io\_close                    | io\_uring/openclose.c | function parameter |
|                    |                       |                                              | io\_close\_fixed             | io\_uring/openclose.c | function parameter |
|                    |                       |                                              | io\_install\_fixed\_fd\_prep | io\_uring/openclose.c | function parameter |
|                    |                       |                                              | io\_install\_fixed\_fd       | io\_uring/openclose.c | function parameter |
| io\_fixed\_install | io\_uring/openclose.c | file, o\_flags                               | io\_install\_fixed\_fd\_prep | io\_uring/openclose.c | function parameter |
| io\_kiocb      | io\_uring/openclose.h | req, sqe                  | io\_openat\_prep             | io\_uring/openclose.h | function parameter |
| io\_ring\_ctx  | io\_uring/openclose.h | ctx, issue\_flags, offset | \_\_io\_close\_fixed         | io\_uring/openclose.h | function parameter |
| io\_kiocb      | io\_uring/openclose.h | req, sqe                  | io\_openat                   | io\_uring/openclose.h | function parameter |
|                |                       |                           | io\_open\_cleanup            | io\_uring/openclose.h | function parameter |
| io\_kiocb      | io\_uring/openclose.h | req, sqe                  | io\_openat2\_prep            | io\_uring/openclose.h | function parameter |
| io\_kiocb      | io\_uring/openclose.h | req, sqe                  | io\_openat2                  | io\_uring/openclose.h | function parameter |
| io\_kiocb      | io\_uring/openclose.h | req, sqe                  | io\_close\_prep              | io\_uring/openclose.h | function parameter |
| io\_kiocb      | io\_uring/openclose.h | req, sqe                  | io\_close                    | io\_uring/openclose.h | function parameter |
| io\_kiocb      | io\_uring/openclose.h | req, sqe                  | io\_install\_fixed\_fd\_prep | io\_uring/openclose.h | function parameter |
| io\_kiocb      | io\_uring/openclose.h | req, sqe                  | io\_install\_fixed\_fd       | io\_uring/openclose.h | function parameter |
| `io_poll_update`         | io\_uring/poll.c | `file`, `old_user_data`, `new_user_data`, `events`, `update_events`, `update_user_data` | N/A                                | N/A              | Local variable                     |
| `io_poll_table`          | io\_uring/poll.c | `pt`, `req`, `nr_entries`, `error`, `owning`, `result_mask`                             | io\_poll\_queue\_proc              | io\_uring/poll.c | Function parameter, local variable |
| `io_poll`                | io\_uring/poll.c | `head`, `events`, `wait`                                                                | io\_poll\_remove\_entries          | io\_uring/poll.c | Local variable, function parameter |
| `io_poll_table`          | io\_uring/poll.c | `pt` (nested within io\_poll\_table struct)                                             | \_\_io\_queue\_proc                | io\_uring/poll.c | Function parameter                 |
| `io_poll_wake`           | io\_uring/poll.c | `wait`, `mode`, `sync`, `key`                                                           | io\_pollfree\_wake                 | io\_uring/poll.c | Function parameter                 |
| `io_poll_mark_cancelled` | io\_uring/poll.c | N/A                                                                                     | io\_poll\_cancel\_req              | io\_uring/poll.c | Function parameter                 |
| `io_poll_get_ownership`  | io\_uring/poll.c | N/A                                                                                     | io\_poll\_get\_ownership\_slowpath | io\_uring/poll.c | Function return, local variable    |
| `io_poll_req_insert`     | io\_uring/poll.c | `hash_node`                                                                             | io\_poll\_add\_hash                | io\_uring/poll.c | Function call                      |
| `io_poll_execute`        | io\_uring/poll.c | `mask`, `res`                                                                           | \_\_io\_poll\_execute              | io\_uring/poll.c | Function call                      |
| `io_poll_remove_entry`   | io\_uring/poll.c | `head` (nested in `poll`)                                                               | io\_poll\_remove\_entries          | io\_uring/poll.c | Function call, local variable      |
| `io_poll_check_events`   | io\_uring/poll.c | `tw`, `poll_refs`, `events`, `cqe.res`                                                  | io\_poll\_execute                  | io\_uring/poll.c | Function call, local variable      |
| `io_poll_add_hash`       | io\_uring/poll.c | `hash_node`                                                                             | io\_poll\_req\_insert              | io\_uring/poll.c | Function call                      |
| io\_ring\_ctx  | io\_uring/poll.h | None                                                | \_\_io\_close\_fixed         | io\_uring/poll.h | function parameter |
| io\_kiocb      | io\_uring/poll.h | req (io\_kiocb), sqe (io\_uring\_sqe), issue\_flags | io\_openat\_prep             | io\_uring/poll.h | function parameter |
| io\_kiocb      | io\_uring/poll.h | req (io\_kiocb), issue\_flags                       | io\_openat                   | io\_uring/poll.h | function parameter |
| io\_kiocb      | io\_uring/poll.h | req (io\_kiocb)                                     | io\_open\_cleanup            | io\_uring/poll.h | function parameter |
| io\_kiocb      | io\_uring/poll.h | req (io\_kiocb), sqe (io\_uring\_sqe)               | io\_openat2\_prep            | io\_uring/poll.h | function parameter |
| io\_kiocb      | io\_uring/poll.h | req (io\_kiocb), issue\_flags                       | io\_openat2                  | io\_uring/poll.h | function parameter |
| io\_kiocb      | io\_uring/poll.h | req (io\_kiocb), sqe (io\_uring\_sqe)               | io\_close\_prep              | io\_uring/poll.h | function parameter |
| io\_kiocb      | io\_uring/poll.h | req (io\_kiocb), issue\_flags                       | io\_close                    | io\_uring/poll.h | function parameter |
| io\_kiocb      | io\_uring/poll.h | req (io\_kiocb), sqe (io\_uring\_sqe)               | io\_install\_fixed\_fd\_prep | io\_uring/poll.h | function parameter |
| io\_kiocb      | io\_uring/poll.h | req (io\_kiocb), issue\_flags                       | io\_install\_fixed\_fd       | io\_uring/poll.h | function parameter |
| io\_uring\_probe           | `<linux/io_uring.h>`       | `last_op`, `ops_len`, array of `struct io_uring_probe_op ops[]`            | `io_probe`                                             | `register.c`  | local variable, copied from/to user         |
| io\_uring\_probe\_op       | `<linux/io_uring.h>`       | `op`, `flags`                                                              | `io_probe`                                             | `register.c`  | array element in `io_uring_probe`           |
| io\_ring\_ctx              | `<linux/io_uring_types.h>` | many (e.g., `flags`, `restrictions`, `personalities`, `clockid`, etc.)     | multiple functions                                     | `register.c`  | function parameters, member access          |
| io\_restriction            | `io_uring_types.h`         | `register_op`, `sqe_op`, `sqe_flags_required`, `sqe_flags_allowed`         | `io_parse_restrictions`, others                        | `register.c`  | function parameter                          |
| io\_uring\_restriction     | `<linux/io_uring.h>`       | `opcode`, `register_op`, `sqe_op`, `sqe_flags`                             | `io_parse_restrictions`                                | `register.c`  | user space struct, copied via `memdup_user` |
| cred                       | `<linux/cred.h>`           | N/A                                                                        | `io_register_personality`, `io_unregister_personality` | `register.c`  | function local, return value                |
| cpumask\_var\_t            | `<linux/cpumask.h>`        | N/A (bitmask for CPUs)                                                     | `io_register_iowq_aff`                                 | `register.c`  | local variable                              |
| io\_tctx\_node             | `tctx.h`                   | `task`, `ctx_node`                                                         | `io_register_iowq_max_workers`                         | `register.c`  | local variable, list traversal              |
| io\_uring\_clock\_register | `<linux/io_uring.h>`       | `clockid`, `__resv[]`                                                      | `io_register_clock`                                    | `register.c`  | copied from user                            |
| io\_ring\_ctx\_rings       | `register.c`               | `rings`, `sq_sqes`, `sq_region`, `ring_region`                             | `io_register_resize_rings`, others                     | `register.c`  | local variable                              |
| io\_uring\_region\_desc    | `<linux/io_uring_types.h>` | `size`, `flags`, `user_addr`                                               | `io_register_resize_rings`                             | `register.c`  | local variable                              |
| io\_rings                  | `<linux/io_uring_types.h>` | `sq_ring_mask`, `cq_ring_mask`, `sq_ring_entries`, `cq_ring_entries`, etc. | `io_register_resize_rings`                             | `register.c`  | accessed through pointer in mmap region     |
| Structure name | Defined in            | Attributes                                                                                  | Caller Functions Source     | source caller         | usage              |
| io\_ring\_ctx  | `io_uring/io_uring.c` | berbagai field terkait submission/completion queue, file table, personalities, eventfd, dll | `io_eventfd_unregister`     | `io_uring/register.c` | function parameter |
|                |                       |                                                                                             | `io_unregister_personality` | `io_uring/register.c` | function parameter |
| **io\_rsrc\_node** | `io_uring/rsrc.c` | `int type`, `int refs`, `u64 tag`, `unsigned long file_ptr` | `io_rsrc_node_alloc`        | `io_uring/rsrc.c`                              | return value, local variable |
|                    |                   | `io_free_rsrc_node`                                         | `io_uring/rsrc.c`           | function parameter, local variable             |                              |
|                    |                   | `io_rsrc_data_free`                                         | `io_uring/rsrc.c`           | function parameter, used via array access      |                              |
|                    |                   | `__io_sqe_files_update`                                     | `io_uring/rsrc.c`           | local variable, array element assignment       |                              |
|                    |                   | `__io_sqe_buffers_update`                                   | `io_uring/rsrc.c`           | local variable, array element assignment       |                              |
|                    |                   | `io_register_rsrc_update`                                   | `io_uring/rsrc.c`           | indirectly used through internal function call |                              |
| `io_rsrc_node` | io\_uring/rsrc.h | type (unsigned char), refs (int), tag (u64), union { file\_ptr, buf } | io\_rsrc\_node\_alloc       | io\_uring/rsrc.c | return value                                  |
|                |                  |                                                                       | io\_put\_rsrc\_node         | io\_uring/rsrc.h | function parameter, local variable            |
|                |                  |                                                                       | io\_free\_rsrc\_node        | io\_uring/rsrc.c | function parameter                            |
|                |                  |                                                                       | io\_reset\_rsrc\_node       | io\_uring/rsrc.h | local variable, array element                 |
|                |                  |                                                                       | io\_req\_put\_rsrc\_nodes   | io\_uring/rsrc.h | accessed via req->file\_node / req->buf\_node |
|                |                  |                                                                       | io\_req\_assign\_rsrc\_node | io\_uring/rsrc.h | function parameter                            |
|                |                  |                                                                       | io\_req\_assign\_buf\_node  | io\_uring/rsrc.h | function parameter                            |
| `io_rw`            | `io_uring/rw.c` | `kiocb, u64 addr, u32 len, rwf_t flags` | `__io_import_rw_buffer`            | `io_uring/rw.c`   | local variable                               |
|                    |                 |                                         | `io_iov_compat_buffer_select_prep` | `io_uring/rw.c`   | function parameter                           |
|                    |                 |                                         | `io_rw_prep_reg_vec`               | `io_uring/rw.c`   | local variable (via macro `io_kiocb_to_cmd`) |
|                    |                 |                                         | `io_rw_import_reg_vec`             | `io_uring/rw.c`   | local variable                               |
|                    |                 |                                         | `io_init_rw_fixed`                 | `io_uring/rw.c`   | local variable                               |
|                    |                 |                                         | `io_prep_rw_pi`                    | `io_uring/rw.c`   | function parameter                           |
|                    |                 |                                         | `__io_prep_rw`                     | `io_uring/rw.c`   | local variable                               |
|                    |                 |                                         | `io_kiocb_update_pos`              | `io_uring/rw.c`   | local variable                               |
|                    |                 |                                         | `io_read_mshot_prep`               | `io_uring/rw.c`   | local variable                               |
| `io_meta_state` | io\_uring/rw\.h | `u32 seed`, `struct iov_iter_state iter_meta`                                                         | io\_read, io\_write\_fixed              | io\_uring/rw\.c | local variable                         |
|                 |                 |                                                                                                       | io\_read\_fixed, io\_write              | io\_uring/rw\.c | local variable                         |
| `io_async_rw`   | io\_uring/rw\.h | `struct iou_vec vec`, `size_t bytes_done`, `struct iov_iter iter`, `struct iov_iter_state iter_state` | io\_read, io\_write, io\_read\_fixed    | io\_uring/rw\.c | `req->async_data` (member dereference) |
|                 |                 | `struct iovec fast_iov`, `union` of `wait_page_queue wpq` or `{uio_meta, io_meta_state}`              | io\_write\_fixed, io\_req\_rw\_complete | io\_uring/rw\.c | `req->async_data`                      |
|                 |                 |                                                                                                       | io\_read\_mshot, io\_rw\_fail           | io\_uring/rw\.c | `req->async_data`, local variable      |
|                 |                 |                                                                                                       | io\_readv\_writev\_cleanup              | io\_uring/rw\.c | `req->async_data`                      |
| `io_splice`    | io\_uring/splice.c | `file *file_out`, `loff_t off_out`, `loff_t off_in`, `u64 len`, `int splice_fd_in`, | `__io_splice_prep`      | io\_uring/splice.c | local variable via `io_kiocb_to_cmd()` |
|                |                    | `unsigned int flags`, `io_rsrc_node *rsrc_node`                                     | `io_splice_prep`        | io\_uring/splice.c | local variable via `io_kiocb_to_cmd()` |
|                |                    |                                                                                     | `io_tee_prep`           | io\_uring/splice.c | local variable via `io_kiocb_to_cmd()` |
|                |                    |                                                                                     | `io_splice`             | io\_uring/splice.c | local variable via `io_kiocb_to_cmd()` |
|                |                    |                                                                                     | `io_tee`                | io\_uring/splice.c | local variable via `io_kiocb_to_cmd()` |
|                |                    |                                                                                     | `io_splice_cleanup`     | io\_uring/splice.c | local variable via `io_kiocb_to_cmd()` |
|                |                    |                                                                                     | `io_splice_get_file`    | io\_uring/splice.c | local variable via `io_kiocb_to_cmd()` |
| `io_splice`    | io\_uring/splice.c | file\_out, off\_out, off\_in, len, splice\_fd\_in, flags, rsrc\_node | io\_tee\_prep           | splice.h (declared) → splice.c (defined) | function parameter via `req → io_kiocb_to_cmd()` |
|                |                    |                                                                      | io\_tee                 | splice.h (declared) → splice.c (defined) | function parameter via `req → io_kiocb_to_cmd()` |
|                |                    |                                                                      | io\_splice\_prep        | splice.h (declared) → splice.c (defined) | function parameter via `req → io_kiocb_to_cmd()` |
|                |                    |                                                                      | io\_splice              | splice.h (declared) → splice.c (defined) | function parameter via `req → io_kiocb_to_cmd()` |
|                |                    |                                                                      | io\_splice\_cleanup     | splice.h (declared) → splice.c (defined) | function parameter via `req → io_kiocb_to_cmd()` |
| io\_sq\_data   | io\_uring/sqpoll.c | refcount\_t, atomic\_t, mutex, waitqueue\_head, list\_head             | io\_put\_sq\_data             | io\_uring/sqpoll.c | local variable, function parameter |
|                |                    | ctx\_list, sqd\_list, sq\_thread\_idle, sq\_cpu, task\_pid, task\_tgid | io\_sq\_thread\_park          | io\_uring/sqpoll.c | function parameter                 |
|                |                    | lock, sq\_thread\_idle, sq\_cpu, sq\_data, exited                      | io\_sq\_thread\_unpark        | io\_uring/sqpoll.c | local variable                     |
|                |                    | thread, task\_tgid, task\_pid, sq\_thread\_idle                        | io\_sq\_thread\_stop          | io\_uring/sqpoll.c | local variable                     |
|                |                    | ctx\_list, sq\_data, waitqueue\_head, sq\_thread\_idle                 | io\_sq\_thread\_finish        | io\_uring/sqpoll.c | function parameter                 |
|                |                    | sq\_data, ctx\_list, sq\_thread\_idle                                  | io\_sqd\_update\_thread\_idle | io\_uring/sqpoll.c | local variable                     |
|                |                    | sq\_data, sqd\_list, task\_pid, sq\_cpu                                | io\_sq\_offload\_create       | io\_uring/sqpoll.c | function parameter                 |
|                |                    | lock, sq\_thread\_idle                                                 | io\_sq\_thread                | io\_uring/sqpoll.c | local variable, function parameter |
|                |                    | task\_pid, task\_tgid, sq\_cpu, lock                                   | io\_sq\_update\_worktime      | io\_uring/sqpoll.c | local variable                     |
|                |                    | task\_pid, sq\_thread\_idle, ctx\_list                                 | io\_sq\_thread\_finish        | io\_uring/sqpoll.c | local variable                     |
|                |                    | sq\_thread\_idle, task\_pid, task\_tgid                                | io\_sq\_thread\_stop          | io\_uring/sqpoll.c | function parameter                 |
| io\_sq\_data   | io\_uring/sqpoll.h | refcount\_t, atomic\_t, mutex, list\_head, task\_struct, wait\_queue\_head, u64, unsigned long, pid\_t, completion | io\_sq\_offload\_create       | io\_uring/sqpoll.c | function parameter |
|                |                    |                                                                                                                    | io\_sq\_thread\_finish        | io\_uring/sqpoll.c | function parameter |
|                |                    |                                                                                                                    | io\_sq\_thread\_stop          | io\_uring/sqpoll.c | function parameter |
|                |                    |                                                                                                                    | io\_sq\_thread\_park          | io\_uring/sqpoll.c | function parameter |
|                |                    |                                                                                                                    | io\_sq\_thread\_unpark        | io\_uring/sqpoll.c | function parameter |
|                |                    |                                                                                                                    | io\_put\_sq\_data             | io\_uring/sqpoll.c | function parameter |
|                |                    |                                                                                                                    | io\_sqpoll\_wait\_sq          | io\_uring/sqpoll.c | function parameter |
|                |                    |                                                                                                                    | io\_sqpoll\_wq\_cpu\_affinity | io\_uring/sqpoll.c | function parameter |
| io\_statx      | io\_uring/statx.c | struct file, int, unsigned int, struct filename, struct statx \_\_user\* | io\_statx\_prep         | io\_uring/statx.c | function parameter |
|                |                   |                                                                          | io\_statx               | io\_uring/statx.c | function parameter |
|                |                   |                                                                          | io\_statx\_cleanup      | io\_uring/statx.c | local variable     |
|                | io\_uring/statx.h |            | io\_statx\_prep         | io\_uring/statx.c | function parameter |
|                |                   |            | io\_statx               | io\_uring/statx.c | function parameter |
|                |                   |            | io\_statx\_cleanup      | io\_uring/statx.c | function parameter |

