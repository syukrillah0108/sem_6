# Narasi

![Line](./sketch.svg)

Bus ini bernama **Travelo Tralala**, sebuah armada yang setia melayani penumpang setiap hari. Setiap pagi, tepat pukul 06:00, bus ini sudah siap menunggu di Halte-A. Para penumpang mulai berdatangan, ada yang berangkat kerja, sekolah, maupun sekadar bepergian. Setelah semua penumpang naik, bus berangkat pada pukul 06:10, perlahan meninggalkan Halte-A dan melaju menuju Halte-B.

Perjalanan menuju Halte-B tidak selalu mulus. Bus harus melewati persimpangan jalan yang dilengkapi lampu lalu lintas. Kadang, bus harus berhenti sejenak menunggu lampu hijau, memberi kesempatan kendaraan lain melintas. Namun, suasana di dalam bus tetap hangat, penumpang saling bercengkerama atau menikmati pemandangan pagi kota.

Setibanya di Halte-B, bus berhenti selama 10 menit. Waktu ini dimanfaatkan penumpang untuk turun, naik, atau sekadar beristirahat sejenak. Setelah itu, bus kembali melanjutkan perjalanan ke Halte-A, melewati rute yang sama dan kembali menghadapi persimpangan lampu lalu lintas. Siklus ini terus berulang sepanjang hari, dari pagi hingga malam, memastikan setiap penumpang dapat sampai ke tujuan dengan aman dan nyaman.

Operasional bus **Travelo Tralala** berlangsung hingga pukul 20:00. Setelah perjalanan terakhir, bus kembali ke garasi untuk perawatan dan persiapan melayani penumpang keesokan harinya. Dengan jadwal yang teratur dan pelayanan yang ramah, bus ini menjadi pilihan utama masyarakat di sekitar Halte-A dan Halte-B.

# Konsep

* **Line Follower** : Kendaraan akan mengikuti jalur yang telah diprogram, meniru trayek bus pada umumnya.
* **Deteksi Rambu dan Lampu Lalu Lintas** : Modul sensor akan mengenali lampu merah untuk berhenti, mendukung kepatuhan pada peraturan lalu lintas, Rambu ini akan Hijau 10 menit dan merah 5 menit.
* **Halte Otomatis** : Ketika mencapai titik halte, sistem akan memperlambat kecepatan dan berhenti sejenak, mensimulasikan proses menaik-turunkan penumpang.
* **Monitoring dan Kontrol Manual** : Data posisi, kecepatan, dan status lampu akan dikirim ke dashboard IoT berbasis web atau aplikasi mobile. Operator juga dapat mengambil alih kendali secara manual jika diperlukan.

# Lampu Lalulintas

![Line](./lampu-3.svg)

# Halte

![Line](./Halte.svg)

# Bus

![Line](./Bus.svg)
