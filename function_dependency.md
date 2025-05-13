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

### advice.c
Source | Library | Function utilized | Time Used
-------|--------|--------------------|-----------
io_uring/advise.c | linux/mm.h | mmap | 1
| | linux/fs.h | fput | 1
| | io_uring/io_uring.c | io_uring_cmd | 2
| | linux/slab.h | kmalloc | 1
| | linux/uaccess.h | copy_to_user | 1

### advice.h
Source            | Library                          | Function utilized               | Time Used
------------------|----------------------------------|----------------------------------|----------
io_uring/advise.h | linux/mm.h                       | mmap                            | 1
                  | linux/fs.h                       | fput                            | 1
                  | io_uring/io_uring.c              | io_uring_cmd                    | 2
                  | linux/slab.h                     | kmalloc                         | 1
                  | linux/uaccess.h                  | copy_to_user                    | 1

### alloc_cache.c
Source              | Library                          | Function utilized               | Time Used
--------------------|----------------------------------|----------------------------------|----------
io_uring/alloc_cache.c | /include/linux/kasan.h        | kasan_mempool_unpoison_object   | 1
                    | arch/x86/include/asm/string_64.h | memset                          | 1
                    | io_uring/alloc_cache.h          | io_alloc_cache_get              | 1
                    | io_uring/alloc_cache.h          | io_cache_alloc_new              | 1
                    | io_uring/alloc_cache.h          | io_alloc_cache_put              | 1
                    | linux/mm/slub.c                 | kfree                           | 1

### alloc_cache.h
Source                | Library                              | Function utilized               | Time Used
----------------------|--------------------------------------|----------------------------------|----------
io_uring/alloc_cache.h | /include/linux/kasan.h              | kasan_mempool_unpoison_object   | 1
                      | arch/x86/include/asm/string_64.h     | memset                          | 1
                      | io_uring/alloc_cache.h               | io_alloc_cache_get              | 1
                      | io_uring/alloc_cache.h               | io_cache_alloc_new              | 1
                      | io_uring/alloc_cache.h               | io_alloc_cache_put              | 1
                      | linux/mm/slub.c                      | kfree                           | 1


### cancel.c
Source           | Library                          | Function utilized               | Time Used
-----------------|----------------------------------|----------------------------------|----------
io_uring/cancel.c | linux/sched.h                   | schedule                        | 1
                 | linux/errno.h                    | errno                           | 1
                 | linux/slab.h                     | kmalloc                         | 1
                 | linux/uaccess.h                  | copy_from_user                  | 1
                 | linux/fs.h                       | fput                            | 1

### cancel.h
Source           | Library                          | Function utilized               | Time Used
-----------------|----------------------------------|----------------------------------|----------
io_uring/cancel.h | linux/sched.h                   | schedule                        | 1
                 | linux/errno.h                    | errno                           | 1
                 | linux/slab.h                     | kmalloc                         | 1
                 | linux/uaccess.h                  | copy_from_user                  | 1
                 | linux/fs.h                       | fput                            | 1

### epoll.c
Source         | Library                          | Function utilized               | Time Used
---------------|----------------------------------|----------------------------------|----------
io_uring/epoll.c | linux/poll.h                   | poll_wait                       | 1
               | linux/fs.h                       | vfs_poll                        | 1
               | linux/slab.h                     | kmalloc                         | 1
               | linux/uaccess.h                  | copy_to_user                    | 1
               | linux/sched.h                    | schedule                        | 1

### epoll.h
Source         | Library                          | Function utilized               | Time Used
---------------|----------------------------------|----------------------------------|----------
io_uring/epoll.h | linux/poll.h                   | poll_wait                       | 1
               | linux/fs.h                       | vfs_poll                        | 1
               | linux/slab.h                     | kmalloc                         | 1
               | linux/uaccess.h                  | copy_to_user                    | 1
               | linux/sched.h                    | schedule                        | 1
               
### eventfd.c
Source              | Library                          | Function utilized               | Time Used
--------------------|----------------------------------|----------------------------------|----------
io_uring/eventfd.c  | linux/eventfd.h                  | eventfd_signal                  | 1
                    | linux/eventfd.h                  | eventfd_ctx_fileget             | 1
                    | linux/fs.h                       | fput                            | 1
                    | linux/slab.h                     | kmalloc                         | 1
                    | linux/uaccess.h                  | copy_to_user                    | 1

### eventfd.h
Source              | Library                          | Function utilized               | Time Used
--------------------|----------------------------------|----------------------------------|----------
io_uring/eventfd.h  | linux/eventfd.h                  | eventfd_signal                  | 1
                    | linux/eventfd.h                  | eventfd_ctx_fileget             | 1
                    | linux/fs.h                       | fput                            | 1

### fdinfo.c
Source                | Library                          | Function utilized               | Time Used
----------------------|----------------------------------|----------------------------------|----------
io_uring/fdinfo.c     | linux/fs.h                       | seq_printf                      | 1
                      | linux/fs.h                       | seq_file                        | 1
                      | linux/slab.h                     | kmalloc                         | 1
                      | linux/slab.h                     | kfree                           | 1
### fdinfo.h
Source                | Library                          | Function utilized               | Time Used
----------------------|----------------------------------|----------------------------------|----------
io_uring/fdinfo.h     | linux/fs.h                       | seq_printf                      | 1
                      | linux/fs.h                       | seq_file                        | 1

### filetable.c
Source                  | Library                          | Function utilized               | Time Used
------------------------|----------------------------------|----------------------------------|----------
io_uring/filetable.c    | linux/fs.h                       | fget                            | 1
                        | linux/fs.h                       | fput                            | 1
                        | linux/slab.h                     | kmalloc                         | 1
                        | linux/slab.h                     | kfree                           | 1
                        | linux/uaccess.h                  | copy_from_user                  | 1

### filetable.h
Source                  | Library                          | Function utilized               | Time Used
------------------------|----------------------------------|----------------------------------|----------
io_uring/filetable.h    | linux/fs.h                       | fget                            | 1
                        | linux/fs.h                       | fput                            | 1
                        | linux/slab.h                     | kmalloc                         | 1
                        | linux/slab.h                     | kfree                           | 1

### fs.c
Source             | Library                          | Function utilized               | Time Used
-------------------|----------------------------------|----------------------------------|----------
io_uring/fs.c      | linux/fs.h                       | fget                            | 1
                   | linux/fs.h                       | fput                            | 1
                   | linux/slab.h                     | kmalloc                         | 1
                   | linux/slab.h                     | kfree                           | 1
                   | linux/uaccess.h                  | copy_from_user                  | 1

### fs.h
Source             | Library                          | Function utilized               | Time Used
-------------------|----------------------------------|----------------------------------|----------
io_uring/fs.h      | linux/fs.h                       | fget                            | 1
                   | linux/fs.h                       | fput                            | 1

### futex.c
Source               | Library                          | Function utilized               | Time Used
---------------------|----------------------------------|----------------------------------|----------
io_uring/futex.c     | linux/futex.h                    | futex_wait                      | 1
                     | linux/futex.h                    | futex_wake                      | 1
                     | linux/slab.h                     | kmalloc                         | 1
                     | linux/slab.h                     | kfree                           | 1              

### futex.h
Source               | Library                          | Function utilized               | Time Used
---------------------|----------------------------------|----------------------------------|----------
io_uring/futex.h     | linux/futex.h                    | futex_wait                      | 1
                     | linux/futex.h                    | futex_wake                      | 1