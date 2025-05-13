# Task 1: Information about io_uring source
List in this section source and headers of io_uring. For each of the C source/header, you must put description what's the prime responsibily of the source. Take notes, description of the source should be slightly technical like the example given. 

## Source
### advice.c
Store io_madvice & io_fadvice structures, both have the same exact attributes. Which make them basically the same thing. Except function body treat them as separate. Codes which make use of io_madvice are guarded by compilation macro, which make its relevant functions only active if the build flag is set. But functions that make use of io_fadvice are active all the time. The exact difference between io_madvice & io_fadvice will only known after exploring do_madvise function for io_madvice & vfs_fadvise function for io_fadvice. 

## another source

## Headers
### advice.h
Just declare the function specification. 

### advice.c
Mengelola struktur `io_madvice` dan `io_fadvice`, yang memiliki atribut serupa tetapi digunakan dalam konteks berbeda. Fungsi terkait `io_madvice` diaktifkan berdasarkan makro kompilasi, sedangkan `io_fadvice` selalu aktif.

### alloc_cache.c
Mengimplementasikan cache alokasi memori untuk struktur internal io_uring. Berisi fungsi untuk mengalokasikan dan mendaur ulang objek dari cache.

### cancel.c
Mengimplementasikan mekanisme pembatalan operasi io_uring yang sedang berlangsung. Berisi logika untuk membatalkan operasi berdasarkan ID atau kondisi tertentu.

### epoll.c
Mengintegrasikan epoll dengan io_uring untuk menangani event-driven I/O. Berisi fungsi untuk mendaftarkan dan memproses event epoll.

### eventfd.c
Mengelola eventfd dalam konteks io_uring. Digunakan untuk sinkronisasi antar thread atau proses melalui event notification.

### fdinfo.c
Berisi fungsi untuk mengelola informasi terkait file descriptor (fd) yang digunakan dalam operasi io_uring.

### filetable.c
Mengimplementasikan tabel file internal untuk melacak file descriptor yang digunakan dalam operasi io_uring.

### fs.c
Berisi implementasi operasi file system (seperti read, write, dan sync) yang dilakukan melalui io_uring.

### futex.c
Mengelola operasi futex (fast user-space mutex) dalam konteks io_uring untuk sinkronisasi antar thread.

## Headers
### advice.h
Mendeklarasikan fungsi dan struktur terkait `io_madvice` dan `io_fadvice`.

### alloc_cache.h
Mendeklarasikan fungsi dan struktur untuk cache alokasi memori.

### cancel.h
Mendeklarasikan fungsi untuk pembatalan operasi io_uring.

### epoll.h
Mendeklarasikan fungsi untuk integrasi epoll dengan io_uring.

### eventfd.h
Mendeklarasikan fungsi untuk pengelolaan eventfd.

### fdinfo.h
Mendeklarasikan fungsi dan struktur untuk informasi file descriptor.

### filetable.h
Mendeklarasikan fungsi dan struktur untuk tabel file internal.

### fs.h
Mendeklarasikan fungsi untuk operasi file system melalui io_uring.

### futex.h
Mendeklarasikan fungsi untuk operasi futex dalam io_uring.