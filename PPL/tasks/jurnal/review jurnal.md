
**Jurnal 1: IMPLEMENTASI WHITE BOX TESTING BERBASIS PATH PADA APLIKASI BERBASIS WEB**

* **Judul:** IMPLEMENTASI WHITE BOX TESTING BERBASIS PATH PADA APLIKASI BERBASIS WEB
* **Jurnal:** Jurnal Siliwangi: Seri Sains dan Teknologi
* **Sumber:** https://jurnal.unsil.ac.id/index.php/jssainstek/article/download/4109/3152
* **Volume & Halaman:** Vol. 9 No. 1 (2023), hlm. 8–13
* **Tahun:** 2023
* **Penulis:** Muhammad Ghibran AL Khamaeni
* **Tujuan Penelitian:**

  1. Menjamin setiap jalur eksekusi pada modul login aplikasi web dijalankan minimal sekali.
  2. Mendeteksi bug logika sejak dini dan meningkatkan keandalan sebelum deployment.
* **Subjek Penelitian:** Modul login sederhana berbasis HTML/CSS/PHP/MySQL—meliputi validasi username/password, session handling, dan tampilan pesan gagal login.
* **Metode Penelitian:**

  * Membuat flowchart proses login.
  * Mengonversi flowchart ke flowgraph.
  * Menghitung Cyclomatic Complexity (CC).
  * Menentukan jalur independen dari flowgraph.
  * Menyusun dan menjalankan test case (positive, negative, boundary).
  * Menganalisis hasil dan memperbaiki kode bila ditemukan kesalahan.
* **Rumusan Masalah:**

  1. Apakah semua jalur logika modul login dapat terpanggil?
  2. Seberapa besar pengaruh nilai CC terhadap jumlah test case?
  3. Bagaimana efektivitas test case dalam menangani input invalid?
* **Hasil Penelitian:**

  * CC = 2 → dua jalur independen: valid login & gagal login.
  * Semua test case lulus tanpa exception.
  * Ditemukan bug validasi panjang password; diperbaiki dengan penambahan cek `strlen`.
* **Kekuatan Penelitian:**

  * Dokumentasi lengkap (flowchart & flowgraph) memudahkan reproduksi.
  * Test case mencakup boundary value pada panjang password.
* **Kelemahan Penelitian:**

  * Hanya satu modul diuji; tidak mencakup fungsi lain aplikasi.
  * Tanpa pengujian beban (load testing) untuk race condition.
  * Tidak membahas skenario rollback transaksi database.
* **Kesimpulan & Rekomendasi:**

  White‑box testing berbasis path efektif untuk modul login. Disarankan memperluas cakupan ke modul lain dan menambahkan load/security testing sebelum go‑live.

---

**Jurnal 2: ANALISIS WHITE BOX TESTING PADA APLIKASI WEB PEMESANAN SABLON KAOS**

* **Judul:** ANALISIS WHITE BOX TESTING PADA APLIKASI WEB PEMESANAN SABLON KAOS
* **Jurnal:** E‑Bisnis, Sistem Informasi, Teknologi Informasi (ESIT)
* **Sumber:** https://openjournal.unpam.ac.id/index.php/ESIT/article/download/14156/8058/32877
* **Volume & Halaman:** Vol. XVI No. 01 (April 2021), hlm. 1–5
* **Tahun:** 2021
* **Penulis:** Khoirunnisya
* **Tujuan Penelitian:**

  1. Mengidentifikasi kesalahan logika pada modul login dan pemesanan.
  2. Menilai kompleksitas kode dan menyusun rekomendasi perbaikan.
* **Subjek Penelitian:** Dua modul utama:

  * Halaman Login (validasi credential & session).
  * Halaman Pemesanan (input desain, ukuran, jumlah, metode pembayaran).
* **Metode Penelitian:**

  * Diagram alir untuk tiap modul → flowgraph → hitung CC (Login: 2; Pemesanan: 4).
  * Tentukan independent paths (total 6).
  * Terapkan graph metrics untuk analisis node & edge.
  * Buat 6 skenario uji (positive, negative, boundary).
  * Eksekusi dan dokumentasi hasil (termasuk waktu eksekusi rata‑rata 0,02 detik).
* **Rumusan Masalah:**

  1. Bagaimana struktur logika kedua modul?
  2. Apakah CC sebanding dengan jumlah test case?
  3. Apakah sistem menangani input invalid (misal jumlah negatif, file corrupt)?
* **Hasil Penelitian:**

  * Login: dua path diuji, validasi session lancar.
  * Pemesanan: empat path diuji, ditemukan dua bug minor pada validasi jumlah (tidak memeriksa `> 0`), diperbaiki.
  * Logging hasil uji lengkap, memudahkan debugging.
* **Kekuatan Penelitian:**

  * Pengujian dua modul krusial mencerminkan alur utama aplikasi.
  * Penerapan graph metrics menambah presisi.
  * Dokumentasi waktu eksekusi dan log sangat membantu.
* **Kelemahan Penelitian:**

  * Tanpa security testing (SQL injection/XSS).
  * Tidak ada load/concurrent user testing.
  * Fokus pada satu platform CMS & konfigurasi server tertentu.
* **Kesimpulan & Rekomendasi:**

  Metode white‑box efektif mendeteksi bug logika. Rekomendasi: buat automated test suite (mis. PHPUnit), tambahkan security & load testing sebelum go‑live.

---

**Jurnal 3: IMPLEMENTASI WHITE BOX PADA INFORMASI AKADEMIK SMP NEGERI 1 BUPON**

* **Judul:** IMPLEMENTASI WHITE BOX PADA INFORMASI AKADEMIK SMP NEGERI 1 BUPON
* **Jurnal:** PENA TEKNIK: Jurnal Ilmiah Ilmu‑Ilmu Teknik
* **Sumber:** https://ojs.unanda.ac.id/index.php/jiit/article/download/181/153
* **Volume & Halaman:** Vol. 3 No. 2 (Sept 2018), hlm. 177–184
* **Tahun:** 2018
* **Penulis:** Solmin Paembonan
* **Tujuan Penelitian:**

  1. Memastikan tidak ada kesalahan logika pada 12 modul form & laporan sistem informasi akademik.
  2. Meminimalkan human error sebelum implementasi di SMP Negeri 1 Bupon.
* **Subjek Penelitian:** 12 modul, meliputi:

  * Data Siswa, Kelas, Guru, Nilai, Mapel, Jadwal, Absensi, Cetak Laporan, Backup & Restore.
* **Metode Penelitian:**

  * Flowchart tiap modul → flowgraph → hitung CC per modul (total 71).
  * Analisis region & independent paths (total 71 paths).
  * Buat dan jalankan 71 test case (positive, negative, boundary).
  * Dokumentasi hasil uji, temukan bug, kemudian perbaiki kode.
* **Rumusan Masalah:**

  1. Berapa CC tiap modul & implikasinya pada jumlah test case?
  2. Apakah modul mampu menangani input invalid (format tanggal, nilai out‑of‑range)?
  3. Bagaimana stabilitas batch saat input data besar?
* **Hasil Penelitian:**

  * CC total = 71; semua jalur diuji.
  * Ditemukan 5 kesalahan format tanggal, 3 pengecekan range nilai, 2 potensi memory leak.
  * Perbaikan: regex validasi, limit iterator pada loop.
* **Kekuatan Penelitian:**

  * Cakupan uji sangat luas (12 modul).
  * Dokumentasi lengkap: flowchart, log error, metrik performa per test.
* **Kelemahan Penelitian:**

  * Tanpa load/concurrent input testing.
  * Tidak ada security testing (mis. SQL injection).
  * Belum diuji di lingkungan QA sekolah (user acceptance).
* **Kesimpulan & Rekomendasi:**

  White‑box testing berhasil mendeteksi kebanyakan bug logika. Disarankan menambahkan security & load testing serta uji penerimaan pengguna di sekolah sebelum rollout.
