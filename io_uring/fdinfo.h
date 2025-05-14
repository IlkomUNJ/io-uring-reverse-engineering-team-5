// SPDX-License-Identifier: GPL-2.0

/**
 * Menampilkan informasi file descriptor io_uring ke seq_file (untuk /proc).
 */
void io_uring_show_fdinfo(struct seq_file *m, struct file *f);
