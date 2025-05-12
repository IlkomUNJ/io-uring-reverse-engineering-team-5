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

### openclose.c
Mengimplementasikan operasi openat2 dan close dalam konteks io_uring. File ini menangani pembukaan dan penutupan file secara asinkron. Fungsi seperti io_openat2_prep() dan io_close_prep() digunakan untuk parsing SQE (submission queue entry), sedangkan io_openat2() dan io_close() menjalankan sistem call yang sesuai dan menyelesaikan permintaan melalui completion queue. Mendukung penggunaan fixed file dan flags seperti O_TMPFILE.

### poll.c
Mengatur operasi polling file descriptor untuk readiness I/O (misalnya POLLIN, POLLOUT). Fungsi io_poll_prep() menyiapkan struktur polling, sementara io_poll() memasang event ke wait queue dan menyelesaikannya saat event terjadi. Dilengkapi juga dengan mekanisme pembatalan melalui io_poll_cancel(). Berguna untuk aplikasi event-driven yang membutuhkan I/O readiness tanpa blocking.

### register.c
Mengelola registrasi berbagai resource seperti file, buffer, dan eventfd ke dalam io_uring. Fungsi seperti io_register_files(), io_register_buffers(), dan io_register_eventfd() memungkinkan pre-registration resource untuk mengurangi overhead syscall dan meningkatkan efisiensi. Registrasi ini mendukung fixed resources agar I/O dapat dijalankan lebih cepat dan deterministik.

### rsrc.c
Back-end dari manajemen resource io_uring. Menyediakan alokasi, penggantian, dan pembersihan resource yang telah diregistrasi. Struktur seperti io_rsrc_node dan io_rsrc_data digunakan untuk menyimpan informasi file dan buffer. Fungsi seperti io_rsrc_data_alloc() dan io_rsrc_node_switch() penting dalam menjaga konsistensi dan efisiensi akses resource.

### rw.c
Mengimplementasikan operasi baca dan tulis (read, write, readv, writev) untuk io_uring. Fungsi io_read_prep() dan io_write_prep() mempersiapkan permintaan, sementara io_read() dan io_write() menanganinya. Mendukung vektor I/O dan mekanisme pembatalan melalui io_rw_cancel(). Merupakan inti dari operasionalisasi I/O sinkron dan asinkron.

### splice.c
Mendukung operasi splice dan tee, yang memungkinkan pemindahan data antar file descriptor tanpa penyalinan ke ruang pengguna (zero-copy). Fungsi io_splice() dan io_tee() menjalankan operasi ini terutama antara pipe atau soket, cocok untuk relay data atau aplikasi streaming efisien.

### sqpoll.c
Menangani submission queue polling (SQPOLL), yaitu mode di mana kernel thread khusus mengambil entri dari SQ tanpa melibatkan syscall dari user. Fungsi io_sq_thread() dan io_sq_offload_create() menangani lifecycle thread polling ini. Berguna untuk mengurangi latensi dan meningkatkan performa melalui pengurangan konteks switch.

### statx.c
Mengimplementasikan syscall statx() secara asinkron untuk mengambil metadata file. Fungsi io_statx_prep() dan io_statx() digunakan untuk parsing parameter dan menjalankan sistem call. Mendukung pengambilan informasi seperti ukuran file, waktu akses, dan mode dengan cara non-blocking.

### sync.c
Mengelola operasi sinkronisasi dan alokasi file seperti sync_file_range, fsync, dan fallocate. Fungsi io_sync_file_range() dan io_fsync() menangani penyimpanan data ke disk, sementara io_fallocate() memesan ruang pada file. File ini penting untuk mendukung konsistensi data dan efisiensi penulisan, terutama pada aplikasi database atau log writer.

### tctx.c
Mengimplementasikan fungsi terkait task context (konteks tugas) dalam io_uring, yang mengatur bagaimana operasi I/O dikaitkan dengan tugas (task/process) tertentu di kernel Linux.

### timeout.c
Menangani operasi timeout (batas waktu) dalam io_uring, memastikan bahwa operasi I/O dapat dibatalkan atau diselesaikan setelah jangka waktu tertentu.

### truncate.c
Mengimplementasikan operasi truncate (pemotongan file) dalam io_uring, memungkinkan pengubahan ukuran file secara asinkron.

### ⁠uring_cmd.c
Menyediakan implementasi perintah khusus (uring_cmd) untuk io_uring, yang memungkinkan eksekusi operasi I/O yang lebih spesifik.

### ⁠waitid.c
Mengimplementasikan operasi waitid dalam io_uring, yang memungkinkan menunggu proses anak (child process) secara asinkron.

### xattr.c
Menangani operasi extended attributes (atribut tambahan file) secara asinkron melalui io_uring.

### ⁠zcrx.c
Mengimplementasikan optimasi penerimaan data zero-copy dalam io_uring untuk kinerja jaringan yang lebih baik.


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

### openclose.h
Mendeklarasikan fungsi untuk operasi pembukaan dan penutupan file secara asinkron, termasuk prototipe io_openat2_* dan io_close_*.

### poll.h
Mendeklarasikan prototipe fungsi polling seperti io_poll_prep(), io_poll(), serta struktur pendukungnya untuk event I/O readiness.

### register.h
Berisi deklarasi fungsi dan struktur untuk registrasi resource. Mencakup file, buffer, eventfd, dan affinity setting untuk worker queue.

### rsrc.h
Mendeklarasikan struktur dan fungsi internal manajemen resource. Digunakan oleh register.c untuk mengatur alokasi, update, dan pembersihan resource.

### rw.h
Berisi deklarasi fungsi operasi read/write dan vektor I/O. Mendukung I/O sinkron dan asinkron serta pembatalan operasi.

### splice.h
Mendeklarasikan fungsi untuk splice dan tee, termasuk fungsi persiapan dan eksekusi transfer data antar file descriptors.

### sqpoll.h
Mendefinisikan fungsi dan struktur untuk submission queue polling, termasuk lifecycle thread dan konfigurasi mode SQPOLL.

### statx.h
Berisi deklarasi fungsi untuk statx(), termasuk parsing dan eksekusi syscall metadata file secara non-blocking.

### sync.h
Mendeklarasikan fungsi untuk operasi sinkronisasi file seperti fsync, sync_file_range, dan fallocate, yang digunakan oleh sync.c.

tctx.h
Mendeklarasikan struktur data dan fungsi yang berkaitan dengan task context untuk io_uring.

timeout.h
Mendefinisikan struktur dan prototipe fungsi yang diperlukan untuk mengelola timeout di io_uring.

truncate.h
Berisi deklarasi fungsi dan struktur untuk operasi truncate di io_uring.

⁠uring_cmd.h
Mendeklarasikan antarmuka dan struktur data untuk perintah khusus (uring_cmd) di io_uring.

⁠waitid.h
Mendefinisikan fungsi dan struktur untuk operasi waitid di io_uring.

xattr.h
Mendeklarasikan fungsi dan struktur yang diperlukan untuk operasi extended attributes di io_uring.

⁠zcrx.h
Berisi deklarasi fungsi dan struktur terkait zero-copy RX di io_uring.

refs.h
Berisi definisi dan utilitas untuk manajemen reference counting (penghitungan referensi) dalam io_uring, memastikan alokasi dan dealokasi memori yang aman.

slist.h
Mendefinisikan struktur singly-linked list (daftar tertaut tunggal) yang digunakan dalam io_uring untuk manajemen daftar operasi atau entri lainnya.