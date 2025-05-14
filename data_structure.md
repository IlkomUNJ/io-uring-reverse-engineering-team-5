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

Structure name      | Defined in              | Attributes                        | Caller Functions Source   | source caller         | usage
--------------------|------------------------|-----------------------------------|--------------------------|-----------------------|-------------------
io_uring_advise_ctx | io_uring/advise.c      | file, addr, len, advice           | io_uring_advise_prep     | io_uring/advise.c     | local variable
|                   |                        |                                   | io_uring_advise          | io_uring/advise.c     | function parameter
io_alloc_cache      | io_uring/alloc_cache.h | cache, size, count                | io_alloc_cache_get       | io_uring/alloc_cache.c| function parameter
|                   |                        |                                   | io_alloc_cache_put       | io_uring/alloc_cache.c| function parameter
|                   |                        |                                   | io_cache_alloc_new       | io_uring/alloc_cache.c| local variable
io_cancel_ctx       | io_uring/cancel.h      | ctx, sqe, flags                   | io_uring_cancel_req      | io_uring/cancel.c     | local variable
|                   |                        |                                   | io_uring_cancel_fd       | io_uring/cancel.c     | function parameter
io_epoll_ctx        | io_uring/epoll.h       | epoll_fd, events, user_data       | io_epoll_add             | io_uring/epoll.c      | local variable
|                   |                        |                                   | io_epoll_remove          | io_uring/epoll.c      | function parameter
io_ev_fd            | io_uring/eventfd.c     | eventfd_ctx, uint, refcount_t     | io_eventfd_free          | io_uring/eventfd.c    | local variable
|                   |                        |                                   | io_eventfd_put           | io_uring/eventfd.c    | function parameter
io_fdinfo_ctx       | io_uring/fdinfo.h      | fd, info, flags                   | io_fdinfo_show           | io_uring/fdinfo.c     | local variable
io_filetable        | io_uring/filetable.h   | files, count, table               | io_filetable_alloc       | io_uring/filetable.c  | return value
|                   |                        |                                   | io_filetable_free        | io_uring/filetable.c  | function parameter
io_fs_ctx           | io_uring/fs.h          | fs, flags, root                   | io_fs_prep               | io_uring/fs.c         | local variable
|                   |                        |                                   | io_fs_commit             | io_uring/fs.c         | function parameter
io_futex_ctx        | io_uring/futex.h       | futex, val, flags                 | io_futex_wait            | io_uring/futex.c      | local variable
|                   |                        |                                   | io_futex_wake            | io_uring/futex.c      | function parameter