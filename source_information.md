# Task 1: Information about io_uring source
List in this section source and headers of io_uring. For each of the C source/header, you must put description what's the prime responsibily of the source. Take notes, description of the source should be slightly technical like the example given. 

## Source
### advice.c
Store io_madvice & io_fadvice structures, both have the same exact attributes. Which make them basically the same thing. Except function body treat them as separate. Codes which make use of io_madvice are guarded by compilation macro, which make its relevant functions only active if the build flag is set. But functions that make use of io_fadvice are active all the time. The exact difference between io_madvice & io_fadvice will only known after exploring do_madvise function for io_madvice & vfs_fadvise function for io_fadvice. 

### io_wq.c
Mengelola work queue untuk io_uring. Mengimplementasikan eksekusi tugas asinkron dan manajemen thread pekerja. Bertanggung jawab untuk penjadwalan dan eksekusi tugas secara paralel.

### io_uring.c
Titik masuk utama untuk operasi io_uring. Berisi rutinitas inisialisasi, penanganan submission queue, dan penanganan completion queue. File ini adalah inti dari fungsionalitas io_uring.

### kbuf.c
Mengelola buffer kernel untuk io_uring. Menyediakan fungsi untuk alokasi, dealokasi, dan manajemen buffer memori yang digunakan dalam operasi I/O.

### memmap.c
Menangani operasi pemetaan memori untuk io_uring. Mengimplementasikan fungsi untuk memetakan memori pengguna ke ruang kernel untuk mendukung I/O tanpa salinan (zero-copy).

### msg_ring.c
Mengimplementasikan fungsi message ring untuk io_uring. Memungkinkan komunikasi antara instance io_uring yang berbeda menggunakan ring buffer.

### napi.c
Mengintegrasikan io_uring dengan subsistem NAPI (New API) untuk jaringan. Mendukung pemrosesan paket yang efisien dalam operasi I/O terkait jaringan.

### net.c
Menangani operasi I/O terkait jaringan untuk io_uring. Mengimplementasikan fungsi untuk manajemen socket, transmisi data, dan penerimaan data.

### nop.c
Mengimplementasikan perintah no-operation (NOP) untuk io_uring. Digunakan untuk tujuan pengujian dan debugging, serta untuk sinkronisasi.

### notif.c
Mengelola notifikasi untuk io_uring. Mengimplementasikan mekanisme untuk memberi sinyal kejadian dan memberi tahu ruang pengguna tentang penyelesaian I/O.

### opdef.c
Mendefinisikan kode operasi dan handler yang sesuai untuk io_uring. Berfungsi sebagai pemetaan antara operasi yang dikirimkan pengguna dan implementasi kernel-nya.

## Headers
### advice.h
Just declare the function specification.

### io_wq.h
Mendeklarasikan fungsi dan struktur yang terkait dengan manajemen work queue di io_uring.

### io_uring.h
Mendefinisikan struktur inti dan prototipe fungsi untuk io_uring. Termasuk definisi untuk submission dan completion queue entries.

### kbuf.h
Mendeklarasikan fungsi dan struktur untuk manajemen buffer kernel di io_uring.

### memmap.h
Mendeklarasikan fungsi dan struktur untuk operasi pemetaan memori di io_uring.

### msg_ring.h
Mendeklarasikan fungsi dan struktur untuk mengimplementasikan fungsi message ring di io_uring.

### napi.h
Mendeklarasikan fungsi dan struktur untuk mengintegrasikan io_uring dengan subsistem NAPI.

### net.h
Mendeklarasikan fungsi dan struktur untuk operasi I/O terkait jaringan di io_uring.

### nop.h
Mendeklarasikan fungsi dan struktur untuk mengimplementasikan perintah no-operation (NOP) di io_uring.

### notif.h
Mendeklarasikan fungsi dan struktur untuk mengelola notifikasi di io_uring.

### opdef.h
Mendeklarasikan kode operasi dan handler yang sesuai untuk io_uring.

