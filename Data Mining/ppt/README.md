## 1. Clustering DBSCAN

Clustering adalah teknik **unsupervised learning** untuk mengelompokkan data tanpa label berdasarkan kemiripan atau kedekatan antar-poin. DBSCAN (Density-Based Spatial Clustering of Applications with Noise) adalah salah satu algoritma clustering yang berbasis kepadatan, dengan keunggulan:

* **Tidak perlu menetapkan jumlah cluster** di awal.
* **Mampu menemukan cluster dengan bentuk arbitrer** (non-spherical).
* **Mengidentifikasi outlier secara eksplisit** sebagai noise .

---

## 2. Konsep Utama

DBSCAN menggunakan dua parameter:

* **ε (epsilon)** : radius maksimum untuk mendefinisikan “tetangga” dari sebuah titik.
* **MinPts** : jumlah minimum titik (termasuk titik itu sendiri) dalam radius ε agar dapat dianggap sebagai  **core point** .

Tiga jenis titik:

1. **Core point** : memiliki ≥ MinPts tetangga dalam radius ε.
2. **Border point** : bukan core, tetapi berada dalam ε dari core point.
3. **Noise point** : bukan core maupun border, dianggap outlier .

---

## 3. Algoritma DBSCAN (Langkah demi Langkah)

1. **Inisialisasi** : Tandai semua titik sebagai unvisited.
2. **Pilih titik acak** unvisited, beri tanda visited.
3. **Cari tetangga** dalam radius ε.
   * Jika jumlah tetangga < MinPts → tandai sebagai *noise* (sementara).
   * Jika ≥ MinPts → buat cluster baru, tandai sebagai core, dan tambahkan semua tetangganya ke cluster.
4. **Perluas cluster** :

* Untuk setiap tetangga yang belum visited, tandai visited.
* Jika tetangga tersebut core → tambahkan tetangganya juga (rekursif).
* Jika bukan core → itu adalah border point (hanya tambahkan ke cluster).

1. **Ulangi** sampai semua titik di-visited.
2. Revisi titik noise: jika ada noise yang ternyata berada dalam ε dari core point setelah seluruh iterasi, ubah menjadi border.

---

## 4. Memilih Parameter ε dan MinPts

* **MinPts** : aturan praktis → `MinPts ≈ 2 × (jumlah fitur)`. Untuk data 2-dimensi, mulai dari 4 atau 5.
* **ε** :

1. **Domain knowledge** : jika tahu skala jarak yang bermakna.
2. **K-distance graph** :
   * Hitung jarak ke k-th nearest neighbor (k = MinPts).
   * Urutkan jarak tersebut, dan carilah “elbow” (titik perubahan kemiringan) pada grafik.
   * Nilai ε yang sesuai terletak di posisi elbow .

---

## 5. Kapan Menggunakan DBSCAN?

* Data memiliki **bentuk cluster kompleks** (non-globular).
* Jumlah cluster **tidak diketahui** di awal.
* Data **mengandung noise** atau outlier.
* Cluster dengan **berbagai kepadatan** (padat dan renggang).
