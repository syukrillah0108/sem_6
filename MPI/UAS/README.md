# Implementasi Sistem Monitoring dan Pengendalian Lingkungan Berbasis ESP32 dengan Integrasi MQTT dan Database MySQL di Ruang Iklim - Laboratorium PSKE Universitas Teknologi Bandung

^8^

Syukrillah

Teknik Informatika, Universitas Teknologi Bandung

22552011247

## Abstrak

Transformasi digital yang pesat telah mendorong peningkatan kebutuhan akan sistem monitoring dan kendali real-time di berbagai sektor, termasuk lingkungan industri dan simulasi. Dalam konteks Industri 4.0, integrasi teknologi Internet of Things (IoT) menjadi krusial untuk mencapai efisiensi operasional, meningkatkan produktivitas, dan mendukung keberlanjutan proses. Sistem monitoring tradisional seringkali menghadapi keterbatasan seperti respons yang lambat, kesulitan dalam pemeliharaan, dan biaya implementasi yang tinggi, yang menghambat kemampuan adaptasi terhadap dinamika lingkungan yang kompleks. Keterbatasan ini menjadi lebih nyata di lingkungan khusus seperti ruang simulasi industri atau laboratorium iklim, di mana parameter lingkungan perlu dimonitor dan dikendalikan dengan presisi tinggi untuk memastikan validitas dan reproduktibilitas eksperimen. Kebutuhan akan data yang akurat dan respons kendali yang cepat menjadi esensial untuk menjaga kondisi simulasi yang konsisten.

Studi kasus di Ruang Iklim Universitas Teknologi Bandung menunjukkan bahwa pencatatan data lingkungan secara manual oleh mahasiswa dapat mengganggu fokus simulasi, menyebabkan nilai yang tidak stabil, serta rawan kehilangan dan ketidaktersediaan data untuk analisis. Oleh karena itu, pengembangan solusi inovatif berbasis IoT menjadi sangat penting. Penelitian ini mengimplementasikan sistem monitoring dan pengendalian lingkungan menggunakan mikrokontroler ESP32 sebagai inti pemrosesan, mengintegrasikan protokol komunikasi MQTT untuk transmisi data real-time yang efisien, dan database MySQL untuk penyimpanan serta manajemen data yang terstruktur. Sistem ini juga dirancang portabel dan mencakup simulasi suara dan cahaya untuk meningkatkan realisme. ^8^ Sistem ini diharapkan dapat mengatasi keterbatasan pencatatan manual, memastikan akurasi dan stabilitas data, mempermudah pengumpulan data secara otomatis, serta mendukung validitas dan reproduktibilitas eksperimen di lingkungan simulasi.

## Abstract

The rapid digital transformation has driven an increased need for real-time monitoring and control systems across various sectors, including industrial and simulation environments. Within the context of Industry 4.0, the integration of Internet of Things (IoT) technology becomes crucial to achieve operational efficiency, enhance productivity, and support process sustainability. Traditional monitoring systems often face limitations such as slow response times, maintenance difficulties, and high implementation costs, which hinder their adaptability to complex environmental dynamics. These limitations become more pronounced in specialized environments like industrial simulation rooms or climate laboratories, where environmental parameters need to be monitored and controlled with high precision to ensure the validity and reproducibility of experiments. The demand for accurate data and quick control responses is essential for maintaining consistent simulation conditions.

A case study in the Climate Room at Universitas Teknologi Bandung revealed that manual data recording by students can disrupt simulation focus, leading to unstable values, and a high risk of data loss and disorganization for analysis. Therefore, developing innovative IoT-based solutions to overcome these challenges is critically important. This research implements an environmental monitoring and control system utilizing the ESP32 microcontroller as the processing core, integrating the MQTT communication protocol for efficient real-time data transmission, and a MySQL database for structured data storage and management. The system is also designed to be portable and includes sound and light simulation to enhance realism. ^8^ This system is expected to overcome the limitations of manual recording, ensure data accuracy and stability, facilitate automated data collection, and support the validity and reproducibility of experiments in simulation environments.

## I. PENDAHULUAN

### Latar Belakang Masalah

Transformasi digital yang pesat telah mendorong peningkatan kebutuhan akan sistem monitoring dan kendali real-time di berbagai sektor. Dalam konteks Industri 4.0, integrasi teknologi Internet of Things (IoT) menjadi krusial untuk mencapai efisiensi operasional, meningkatkan produktivitas, dan mendukung keberlanjutan proses. Sistem monitoring tradisional seringkali menghadapi keterbatasan yang signifikan, seperti respons yang lambat, kesulitan dalam pemeliharaan, dan biaya implementasi yang tinggi. Hambatan ini membatasi kemampuan adaptasi terhadap dinamika lingkungan yang kompleks.

Keterbatasan sistem konvensional ini menjadi lebih nyata di lingkungan khusus seperti ruang simulasi industri atau laboratorium iklim. Di lokasi-lokasi ini, parameter lingkungan perlu dimonitor dan dikendalikan dengan presisi tinggi guna memastikan validitas dan reproduktibilitas eksperimen. Kebutuhan akan data yang akurat dan respons kendali yang cepat menjadi esensial untuk menjaga kondisi simulasi yang konsisten. Praktikum, sebagai salah satu penunjang pengembangan pengetahuan pelajar, sangat bergantung pada sarana dan prasarana pembelajaran yang berkualitas. Simulasi, yang mempermudah perancangan sistem, juga memerlukan lingkungan yang terkontrol dan data yang Andal.

Kondisi ini menunjukkan adanya kesenjangan antara kebutuhan industri modern akan sistem monitoring yang efisien dan tantangan yang dihadapi dalam lingkungan pendidikan, khususnya di laboratorium simulasi. Tantangan yang dihadapi di ruang iklim universitas merupakan cerminan dari masalah yang lebih luas di lingkungan industri, di mana akurasi data dan otomatisasi menjadi kunci. Dengan demikian, solusi IoT yang diusulkan tidak hanya memberikan perbaikan lokal, tetapi juga berkontribusi pada prinsip-prinsip Industri 4.0 terkait data real-time dan otomatisasi dalam lingkungan khusus. Hal ini meningkatkan signifikansi proyek melampaui tugas akademik semata.

### Fokus Masalah

Studi kasus yang dilakukan di Ruang Iklim Universitas Teknologi Bandung mengidentifikasi beberapa masalah spesifik yang menghambat kualitas dan efisiensi proses simulasi. Salah satu masalah utama adalah gangguan yang timbul akibat pencatatan data lingkungan secara manual oleh mahasiswa. Proses ini dapat mengganggu konsentrasi individu yang sedang melakukan simulasi, yang pada gilirannya menyebabkan nilai data yang tidak stabil dan mengurangi akurasi serta reliabilitas pengukuran. ^8^

Selain itu, pencatatan data secara manual juga rentan terhadap kehilangan dan seringkali tidak terstruktur. Hal ini menjadi kendala serius karena data yang terkumpul perlu dihimpun dan dianalisis secara sistematis. Ketidaktersediaan data yang terstruktur mempersulit proses analisis dan validasi eksperimen. ^8^ Permasalahan ini menyoroti antarmuka manusia-sistem sebagai hambatan. Proses manual memperkenalkan variabilitas dan potensi kesalahan akibat gangguan manusia, secara langsung memengaruhi validitas dan reproduktibilitas eksperimen yang disebutkan sebelumnya. Solusi IoT yang diusulkan tidak hanya bertujuan untuk otomatisasi, tetapi juga untuk menghilangkan inkonsistensi yang disebabkan oleh faktor manusia dari proses akuisisi data, sehingga meningkatkan ketelitian ilmiah.

### Metoda atau Pendekatan Penyelesaian

Untuk mengatasi masalah-masalah yang telah diidentifikasi, penelitian ini mengusulkan pengembangan dan implementasi sistem monitoring dan pengendalian lingkungan berbasis Internet of Things (IoT). Pendekatan ini berpusat pada penggunaan mikrokontroler ESP32 sebagai unit pemrosesan utama, yang dikenal dengan kemampuan konektivitas Wi-Fi terintegrasi dan kapasitas pemrosesan yang memadai untuk aplikasi IoT.^1^

Sistem ini akan mengintegrasikan berbagai sensor untuk pengumpulan data lingkungan secara otomatis, seperti suhu, kelembaban, dan kualitas udara. Data yang terkumpul akan ditransmisikan secara efisien menggunakan protokol komunikasi MQTT, yang dipilih karena sifatnya yang ringan dan keandalannya dalam pengiriman data real-time.^3^ Untuk penyimpanan dan manajemen data yang terstruktur, sistem akan memanfaatkan database MySQL. Selain itu, sistem ini dirancang portabel dan mencakup modul simulasi suara dan cahaya untuk meningkatkan realisme lingkungan simulasi. ^8^

### Hasil yang Diharapkan

Implementasi sistem ini diharapkan dapat memberikan beberapa manfaat signifikan. Pertama, sistem ini akan mengotomatisasi pengumpulan data lingkungan, yang secara langsung akan meningkatkan akurasi dan stabilitas nilai pengukuran, mengatasi masalah gangguan dan ketidakstabilan yang disebabkan oleh pencatatan manual.[1, 1] Kedua, dengan penyimpanan data yang terstruktur dalam database MySQL, pengelolaan data akan menjadi lebih mudah, dan risiko kehilangan data akan berkurang secara drastis, memungkinkan analisis data yang lebih efisien dan andal.

Pada akhirnya, dengan data yang lebih akurat dan kendali yang responsif, kualitas dan reproduktibilitas eksperimen yang dilakukan di Ruang Iklim akan meningkat secara substansial.[1, 1] Peningkatan ini melampaui sekadar efisiensi operasional; ini tentang peningkatan kualitas penelitian. Dengan mengotomatiskan pengumpulan data dan memastikan integritas data (mengatasi nilai yang tidak stabil dan kehilangan data), sistem ini secara langsung berkontribusi pada kualitas ilmiah penelitian yang dilakukan di lingkungan tersebut. Ini merupakan dampak tingkat yang lebih tinggi daripada sekadar efisiensi operasional, yaitu tentang memungkinkan penyelidikan ilmiah yang lebih baik.

### Format Penulisan

Ukuran kertas yang digunakan adalah A4 dengan margin atas, bawah, kanan, dan kiri sebesar 2 cm. Paragraf harus diatur rata kiri dan rata kanan (justify). Seluruh dokumen harus menggunakan font Times New Roman atau Times. Fitur ukuran font dapat dilihat pada Tabel I.

**Tabel I: Ukuran Font untuk Sub Judul dan Isi Paper**

| Ukuran Font | Tampilan (dalam Times New Roman atau Times)                                              | Biasa (Regular)   | Tebal (Bold) | Miring (Italic) |
| ----------- | ---------------------------------------------------------------------------------------- | ----------------- | ------------ | --------------- |
| 8           | Keterangan tabel (dalam huruf kapital), Keterangan gambar, referensi                     |                   |              |                 |
| 9           | Afiliasi penulis, nama institusi, alamat, kota dan author email address, cell in a table | Abstrak, abstract |              |                 |
| 10          | Heading level 1 (dalam huruf kapital), isi paper                                         |                   |              |                 |
| 11          | Penulis                                                                                  |                   |              |                 |
| 16          | Judul                                                                                    |                   |              |                 |

Judul harus menggunakan font biasa berukuran 16 pt, sedangkan nama penulis menggunakan font biasa berukuran 11 pt. Penulisan nama penulis tidak boleh menyertakan jabatan, gelar akademik, atau keanggotaan organisasi profesional. Heading sebaiknya tidak lebih dari 3 tingkat, dan semua heading harus dalam font 10pt. Heading level 1 menggunakan huruf kapital dengan paragraf rata kiri dan penomoran angka Romawi kapital. Grafik, tabel, dan gambar harus diletakkan di tengah (center). Keterangan gambar terletak di tengah dengan ukuran 8pt. Keterangan tabel dinomori dengan angka Romawi huruf besar, di tengah, dalam font biasa 8 pt dengan huruf kapital pada setiap kata. Nomor halaman, header, dan footer tidak digunakan. Semua tautan hypertext dan *bookmark* akan dihapus; alamat email atau URL lengkap harus diketik dengan font biasa. Penulisan persamaan mengikuti format standar. Judul bagian Referensi tidak boleh bernomor, dan semua item referensi berukuran font 8 pt, menggunakan gaya tulisan miring dan biasa. Penomoran item referensi diketik berurutan dalam tanda kurung siku (misalnya ).

## II. TINJAUAN PUSTAKA

### Konsep Dasar Internet of Things (IoT)

Internet of Things (IoT) didefinisikan sebagai jaringan perangkat fisik yang tertanam dengan sensor, perangkat lunak, dan teknologi lain yang memungkinkannya terhubung dan bertukar data dengan perangkat dan sistem lain melalui internet.^3^ Konsep ini telah menjadi teknologi yang sangat relevan dalam bidang monitoring lingkungan.^6^ Arsitektur IoT umumnya digambarkan dalam model tiga lapisan: lapisan persepsi (Perception Layer), lapisan komunikasi jaringan (Network Communication Layer), dan lapisan aplikasi (Application Layer). Beberapa model juga menguraikannya menjadi multi-lapisan yang mencakup lapisan pemrosesan (Processing Layer).

Lapisan persepsi bertanggung jawab untuk mengumpulkan data dari lingkungan fisik menggunakan berbagai sensor. Lapisan jaringan berfungsi untuk mentransmisikan data yang terkumpul melalui berbagai protokol komunikasi. Sementara itu, lapisan aplikasi bertugas untuk menganalisis, memproses, dan menyajikan data kepada pengguna, serta mengimplementasikan logika kontrol.

IoT merepresentasikan pergeseran paradigma dari sistem pengumpulan data manual yang terisolasi menjadi ekosistem data yang saling terhubung dan beroperasi secara real-time. Pergeseran ini sangat penting untuk memenuhi tuntutan skalabilitas dan respons real-time dari lingkungan modern, yang tidak dapat dipenuhi oleh metode tradisional.^8^ Ini bukan hanya tentang menghubungkan perangkat, tetapi tentang menciptakan sistem yang holistik dan responsif. Dengan demikian, IoT memungkinkan sistem monitoring lingkungan untuk mengatasi masalah cakupan kecil dan stabilitas rendah yang sering ditemukan pada metode tradisional.

### Peran Mikrokontroler ESP32 dalam Sistem IoT

ESP32 adalah mikrokontroler serbaguna yang sangat populer dalam pengembangan sistem IoT, terutama karena kemampuannya untuk mengumpulkan, memproses, dan mengirimkan data secara real-time. Keunggulan utamanya terletak pada integrasi modul Wi-Fi dan Bluetooth, yang memungkinkan konektivitas nirkabel langsung ke jaringan.^1^

Dalam konteks monitoring lingkungan, ESP32 dapat diintegrasikan dengan berbagai jenis sensor untuk memantau parameter penting seperti suhu, kelembaban (menggunakan sensor seperti DHT22), kualitas udara (dengan sensor MQ2/MQ135), intensitas cahaya, dan bahkan deteksi hujan.^1^ Selain itu, ESP32 juga mampu mengendalikan aktuator seperti modul relay untuk mengontrol perangkat listrik seperti kipas atau lampu, yang sangat penting untuk fungsi pengendalian dalam sistem.^1^

Kemampuan ESP32 untuk memproses data secara lokal sebelum transmisi ke *cloud* menambah ketahanan sistem. Pilihan ESP32 sebagai inti sistem juga mendukung desain yang portabel. Hal ini karena ESP32 memungkinkan sistem untuk mudah disesuaikan dengan kebutuhan pengguna atau lingkungan yang berbeda. ESP32 bukan hanya sekadar mikrokontroler; biaya yang relatif rendah, fitur Wi-Fi terintegrasi, dan fleksibilitasnya menjadikannya kunci untuk memungkinkan solusi IoT yang terjangkau dan dapat diskalakan. Hal ini secara langsung mendukung tujuan proyek untuk menciptakan sistem yang portabel dan adaptif, mendemokratisasi pemantauan lingkungan canggih melampaui instalasi tetap yang mahal.

### Protokol Komunikasi MQTT untuk IoT

Message Queuing Telemetry Transport (MQTT) adalah protokol komunikasi yang ringan, andal, dan efisien daya, dirancang khusus untuk aplikasi Internet of Things (IoT). Protokol ini beroperasi berdasarkan model  *publish/subscribe* , di mana klien (misalnya, perangkat sensor) mempublikasikan pesan ke topik tertentu, dan klien lain (misalnya, aplikasi server) dapat berlangganan topik tersebut untuk menerima pesan yang relevan.^3^ Sebuah

*broker* sentral bertindak sebagai perantara, memfasilitasi pertukaran informasi antara berbagai klien tanpa mereka harus mengetahui keberadaan satu sama lain.

Keunggulan MQTT dalam konteks IoT sangat signifikan:

* **Ringan dan Efisien Daya:** MQTT dirancang dengan *overhead* minimal, membutuhkan *bandwidth* rendah, dan ukuran paket yang kecil, menjadikannya sangat cocok untuk perangkat IoT dengan sumber daya komputasi terbatas dan perangkat bertenaga baterai yang beroperasi di area terpencil.^3^
* **Kecepatan Transmisi Cepat dan Kontrol Kongesti:** Protokol ini menawarkan kecepatan transmisi data yang lebih cepat dan mekanisme kontrol kongesti yang lebih baik, mendukung pengiriman data real-time yang efisien.
* **Reliabilitas (QoS Levels):** MQTT memiliki tiga tingkat Quality of Service (QoS) untuk pengiriman pesan:
  * **QoS 0 (At Most Once):** Pesan dikirim sekali tanpa jaminan pengiriman, cocok untuk data yang tidak terlalu kritis.^3^
  * **QoS 1 (At Least Once):** Pesan dijamin terkirim setidaknya sekali, dengan *acknowledgement* dari  *broker* .^3^
  * **QoS 2 (Exactly Once):** Menggunakan mekanisme *handshake* empat arah untuk memastikan pesan terkirim tepat satu kali, paling aman tetapi juga paling lambat, digunakan untuk data yang sangat kritis.^3^
* **Skalabilitas:** Model *publish/subscribe* memungkinkan koneksi sejumlah besar perangkat ke *broker* tanpa perangkat tersebut perlu mengetahui satu sama lain, mendukung skalabilitas sistem yang tinggi.^3^
* **Dukungan untuk Koneksi Terputus:** Fitur seperti "Clean Session" dan "Will" memungkinkan persistensi pesan dan pengiriman notifikasi jika perangkat terputus secara tidak terduga, memastikan keandalan sistem.

Meskipun sifat ringan dan efisiensi MQTT adalah keuntungan yang jelas, aspek penting untuk sistem monitoring lingkungan, terutama dalam pengaturan simulasi di mana stabilitas data adalah kunci, adalah fitur keandalannya. Tingkat QoS secara langsung mengatasi potensi kehilangan atau inkonsistensi data melalui jaringan yang tidak dapat diandalkan. Ini memastikan bahwa data lingkungan yang terkumpul tidak hanya ditransmisikan tetapi dijamin tiba, secara langsung mengatasi masalah "nilai tidak stabil" dan "rawan hilang" yang diidentifikasi dalam konteks masalah.

Untuk memberikan gambaran yang lebih jelas mengenai posisi MQTT dibandingkan protokol komunikasi IoT lainnya, Tabel II menyajikan perbandingan fitur-fitur utama.

**Tabel II: Perbandingan Fitur Protokol Komunikasi IoT**

| Fitur                | MQTT                              | HTTP                                  | CoAP                        | AMQP                         |
| -------------------- | --------------------------------- | ------------------------------------- | --------------------------- | ---------------------------- |
| Model Komunikasi     | Publish/Subscribe                 | Request/Response                      | Request/Response            | Publish/Subscribe            |
| Overhead             | Minimal (ringan)^3^               | Tinggi (berat)                        | Rendah                      | Sedang                       |
| Konsumsi Bandwidth   | Rendah^3^                         | Tinggi                                | Rendah                      | Sedang                       |
| Efisiensi Daya       | Tinggi                            | Rendah                                | Tinggi                      | Sedang                       |
| Reliabilitas (QoS)   | Ya (QoS 0, 1, 2)^3^               | Tidak ada bawaan (perlu implementasi) | Ya (CON, NON, ACK, RST)     | Ya (lebih kompleks)          |
| Skalabilitas         | Sangat Baik^3^                    | Terbatas (Point-to-point)             | Baik                        | Sangat Baik                  |
| Real-time Capability | Sangat Baik (Event-driven)        | Kurang (Polling)                      | Baik                        | Baik                         |
| Penggunaan           | Sensor, Aktuator, M2M, Notifikasi | Web, API, Aplikasi Client-Server      | Perangkat terbatas, RESTful | Sistem Enterprise, Transaksi |

### Manajemen Data IoT dengan Database MySQL

Perangkat IoT menghasilkan volume data yang sangat besar, menciptakan tantangan signifikan dalam hal pengumpulan, penyimpanan, dan pemrosesan.^9^ Mengadaptasi solusi IoT, baik prototipe maupun produksi massal, untuk menangani ratusan sensor memerlukan desain ulang metode komunikasi, pengumpulan data, dan penyimpanan data. Bahkan dengan perangkat keras, komunikasi, dan kemampuan tampilan yang sangat baik, solusi IoT dapat gagal jika data tidak disajikan dengan mudah, tidak dipahami, atau tidak lengkap.

MySQL hadir sebagai solusi yang kuat dan populer untuk penyimpanan dan manajemen data dalam solusi IoT. MySQL menyediakan solusi yang tangguh untuk menyimpan data IoT, membuatnya tersedia untuk pemrosesan selanjutnya dan analisis historis. Salah satu keunggulannya adalah kemampuannya untuk mengubah data mentah menjadi format yang lebih baik untuk pelaporan dan mengurangi volume penyimpanan, membantu menyaring data yang tidak relevan untuk mengekstrak pengetahuan yang berguna. MySQL juga mendukung penyimpanan dan agregasi data di beberapa server database, yang penting untuk skalabilitas.

Keunggulan lain dari MySQL meliputi:

* **Biaya Rendah dan Ketersediaan Tinggi:** Pengembang dapat membangun server database MySQL lokal yang berbiaya rendah menggunakan komputer kecil dan murah seperti Raspberry Pi atau Arduino. MySQL juga menawarkan fitur canggih untuk membangun solusi ketersediaan tinggi di antara perangkat komputasi berdaya rendah, melindungi data dari kegagalan  *node* .
* **Akses Data Real-time:** Database MySQL dapat menyimpan data secara otomatis dan cepat, memungkinkan akses data real-time. Sebagai contoh, dalam sistem peringatan dini banjir berbasis IoT, data sensor secara periodik disimpan dalam database MySQL dan ditransmisikan ke aplikasi secara real-time.
* **Sumber Terbuka dan Keamanan:** MySQL adalah perangkat lunak sumber terbuka yang dapat digunakan secara bebas dan dikenal karena keamanannya serta rekam jejaknya dalam menangani sejumlah besar data yang dihasilkan oleh perangkat IoT dengan kinerja, fleksibilitas, dan ketersediaan yang tinggi.
* **Integrasi Protokol Komunikasi:** Solusi IoT sering menggunakan *broker* pesan MQTT untuk arsitektur yang terpisah dan protokol komunikasi standar. Server aplikasi dapat terhubung ke *broker* MQTT untuk menerima data sensor dan berinteraksi dengan database MySQL untuk menyimpan data yang terkumpul secara periodik.

IoT menghasilkan "jumlah data yang luar biasa". Meskipun database NoSQL sering disebut-sebut untuk IoT karena fleksibilitas skemanya, kekuatan MySQL terletak pada sifatnya yang terstruktur dan konsisten. Untuk ruang iklim di mana data yang tepat, dapat dibandingkan, dan dapat dianalisis sangat penting untuk validitas dan reproduktibilitas eksperimen, database terstruktur seperti MySQL menyediakan kerangka kerja yang diperlukan untuk analisis historis yang Andal dan identifikasi tren. Hal ini secara langsung mengatasi masalah "tidak terstruktur" dan mendukung peningkatan pengambilan keputusan berdasarkan data yang jelas dan konsisten.

### Studi Terkait Sistem Pemantauan dan Pengendalian Lingkungan

Penelitian terkait sistem pemantauan dan pengendalian lingkungan telah berkembang pesat seiring dengan kemajuan teknologi IoT. Berbagai studi telah menunjukkan potensi besar dari penerapan teknologi ini di berbagai domain, mulai dari lingkungan rumah tangga hingga industri.

Sistem monitoring lingkungan berbasis ESP32 telah banyak diteliti. Sebagai contoh, sebuah proyek mengimplementasikan sistem monitoring lingkungan berbasis IoT menggunakan mikrokontroler ESP32 yang mengintegrasikan sensor suhu, kelembaban, kualitas udara, intensitas cahaya, dan deteksi hujan. Data yang terkumpul kemudian ditransmisikan melalui Wi-Fi ke platform *cloud* seperti ThingSpeak untuk visualisasi dan analisis jarak jauh. Sistem ini menunjukkan solusi yang hemat biaya dan dapat diskalakan untuk manajemen lingkungan.

Dalam konteks lingkungan industri, penelitian telah berfokus pada pemantauan parameter polusi seperti kualitas udara, air, cahaya, suhu, kelembaban, kebisingan, dan gas yang mudah terbakar. Desain sistem ini bertujuan untuk secara terus-menerus membaca dan memantau kondisi lingkungan secara real-time, memproses data, menghitung indeks iklim, dan mengambil tindakan koreksi yang diperlukan. Pendekatan ini bertujuan untuk memastikan kualitas lingkungan pabrik yang dapat diterima, menjaga keselamatan personel, material, dan mesin, serta mengoptimalkan operasi pabrik.

Sistem monitoring dan kendali cerdas berbasis IoT seringkali mengadopsi kerangka kerja tiga lapis: lapisan persepsi, komunikasi jaringan, dan aplikasi. Lapisan persepsi mengumpulkan data melalui sensor lingkungan (misalnya, suhu, kelembaban, konsentrasi partikulat), yang kemudian ditransmisikan melalui lapisan komunikasi jaringan menggunakan modul seperti 4G, ZigBee, atau NB-IoT untuk pembaruan data real-time yang cepat. Data yang terkumpul disimpan dalam database dan diproses di lapisan aplikasi untuk analisis, tampilan, dan implementasi manajemen cerdas, termasuk pengiriman peringatan jika terdeteksi data abnormal.

Tinjauan umum tentang kasus penggunaan sensor dan aktuator IoT dalam berbagai domain, termasuk lingkungan cerdas, menunjukkan kemampuan sistem untuk tidak hanya mengumpulkan data tetapi juga melakukan tindakan kontrol berdasarkan data tersebut.^5^ Sistem monitoring lingkungan cerdas (SEM) telah berkembang pesat dengan kemajuan IoT dan sensor modern, berfokus pada perencanaan dan pengelolaan bencana, pengendalian polusi, dan penanganan kondisi eksternal yang tidak sehat.

Literatur menunjukkan tren yang jelas: pemantauan lingkungan telah berkembang dari pengumpulan data sederhana menjadi sistem yang kompleks, cerdas, dan seringkali berbasis  *cloud* . Integrasi kemampuan kecerdasan buatan (AI) dan pembelajaran mesin (ML) serta protokol komunikasi canggih menunjukkan bahwa tujuannya bukan hanya untuk mengumpulkan data, tetapi untuk mendapatkan informasi yang dapat ditindaklanjuti dan memungkinkan kontrol proaktif. Proyek ini, dengan mengintegrasikan monitoring dan kontrol dengan database terstruktur, selaras dengan tren yang lebih luas ini untuk bergerak menuju "pemantauan lingkungan cerdas" yang mendukung peningkatan pengambilan keputusan dan keberlanjutan lingkungan.^2^

## III. ANALISIS DAN PERANCANGAN SISTEM

### Analisis Kebutuhan Sistem

Analisis kebutuhan sistem merupakan langkah krusial dalam perancangan solusi yang efektif, memastikan bahwa sistem yang dibangun dapat mengatasi permasalahan yang ada dan memenuhi tujuan yang diharapkan.

#### Kebutuhan Fungsional

Kebutuhan fungsional sistem ini mencakup kemampuan inti yang harus dimiliki untuk mencapai tujuannya:

* **Pengumpulan Data Otomatis:** Sistem harus mampu mengumpulkan data parameter lingkungan seperti suhu, kelembaban, dan kualitas udara secara otomatis dari sensor yang terpasang.^8^
* **Transmisi Data Real-time:** Data yang terkumpul harus dapat ditransmisikan secara real-time ke sistem pusat, memastikan informasi terbaru selalu tersedia.^8^
* **Penyimpanan Data Terstruktur:** Sistem memerlukan kemampuan untuk menyimpan data yang dikumpulkan secara terstruktur dan aman dalam database, memfasilitasi akses dan analisis historis.^8^
* **Tampilan Data Monitoring:** Data monitoring harus dapat ditampilkan secara lokal (melalui LCD) dan jarak jauh (melalui antarmuka web/mobile) agar mudah diakses dan dipahami oleh pengguna.^2^
* **Mekanisme Kontrol:** Sistem harus memiliki kemampuan untuk mengaktifkan aktuator (misalnya, kipas, lampu) secara otomatis berdasarkan ambang batas parameter lingkungan yang telah ditetapkan.^8^
* **Simulasi Suara dan Cahaya:** Untuk meningkatkan realisme lingkungan simulasi, sistem harus mampu menghasilkan simulasi suara dan mengoptimalkan simulasi cahaya yang relevan. ^8^
* **Desain Portabel:** Perangkat keras sistem harus dirancang agar portabel dan mudah disesuaikan dengan berbagai konfigurasi atau lokasi dalam ruang simulasi.

#### Kebutuhan Non-Fungsional

Kebutuhan non-fungsional berkaitan dengan kualitas dan batasan operasional sistem:

* **Reliabilitas:** Sistem harus menunjukkan akurasi data yang tinggi, dan pengiriman pesan harus terjamin, didukung oleh fitur Quality of Service (QoS) dari protokol MQTT.^8^ Ini penting untuk mengatasi masalah nilai data yang tidak stabil yang disebabkan oleh pencatatan manual.
* **Skalabilitas:** Sistem harus dirancang agar mampu menangani penambahan sensor atau perluasan area monitoring di masa mendatang tanpa penurunan kinerja yang signifikan.^2^
* **Efisiensi Daya:** Konsumsi daya perangkat sensor harus rendah, terutama jika sistem dirancang untuk operasi jangka panjang atau menggunakan sumber daya baterai.
* **Keamanan Data:** Mekanisme keamanan harus diterapkan untuk melindungi data selama transmisi dan penyimpanan, menjaga integritas dan kerahasiaan informasi.^2^
* **Kemudahan Pemeliharaan:** Desain sistem harus modular untuk memudahkan identifikasi masalah, pemeliharaan, dan perbaikan di masa mendatang.

Permasalahan yang diuraikan secara eksplisit dalam studi kasus diterjemahkan menjadi spesifikasi sistem yang konkret dan terukur. Misalnya, "nilai tidak begitu stabil" mengarah pada kebutuhan fungsional untuk akuisisi data yang akurat dan kebutuhan non-fungsional untuk reliabilitas data. Demikian pula, "pencatatan manual rawan hilang dan tidak terstruktur" mengarah pada kebutuhan penyimpanan data yang terstruktur dan aman. Transformasi ini menunjukkan pendekatan sistematis dalam memecahkan masalah.

Tabel IV menyajikan ringkasan permasalahan yang diidentifikasi dan bagaimana solusi yang diusulkan dalam proyek ini secara langsung mengatasinya.

**Tabel IV: Ringkasan Permasalahan dan Solusi Sistem**

| Permasalahan                                                              | Dampak                                                | Solusi yang Diusulkan                                              | Manfaat                                                   |
| ------------------------------------------------------------------------- | ----------------------------------------------------- | ------------------------------------------------------------------ | --------------------------------------------------------- |
| Pencatatan manual mengganggu fokus simulasi                               | Nilai tidak stabil, akurasi rendah                    | Sistem berbasis IoT dengan sensor otomatis^8^                      | Data akurat, fokus simulasi terjaga                       |
| Data rawan hilang & tidak terstruktur                                     | Sulit dianalisis, tidak valid                         | Integrasi database MySQL & transmisi MQTT dengan QoS^3^            | Data terstruktur, aman, mudah diakses                     |
| Keterbatasan sistem monitoring tradisional (respons lambat, biaya tinggi) | Adaptasi sulit terhadap dinamika lingkungan           | Mikrokontroler ESP32, MQTT, MySQL, desain portabel^8^              | Respons real-time, biaya efektif, fleksibel^8^            |
| Kebutuhan presisi tinggi di ruang simulasi                                | Mempengaruhi validitas & reproduktibilitas eksperimen | Penggunaan sensor & aktuator untuk monitoring & kendali presisi^8^ | Kondisi simulasi konsisten, validitas eksperimen terjamin |
| Kurangnya realisme dalam simulasi                                         | Pengalaman pengguna kurang imersif                    | Pembuatan simulasi suara dan cahaya^8^                             | Simulasi lebih nyata dan imersif                          |

### Arsitektur Sistem

Sistem monitoring dan pengendalian lingkungan ini dirancang berdasarkan arsitektur umum Internet of Things (IoT) yang terdiri dari tiga lapisan utama. Struktur ini memastikan modularitas dan interoperabilitas antar komponen, memungkinkan aliran data yang efisien dari lingkungan fisik hingga ke pengguna akhir.

#### Lapisan Persepsi (Perception Layer)

Lapisan ini merupakan fondasi sistem, bertanggung jawab untuk berinteraksi langsung dengan lingkungan fisik dan mengumpulkan data. Ini terdiri dari modul sensor yang beragam, seperti sensor suhu, kelembaban, dan kualitas udara, yang secara terus-menerus memantau parameter lingkungan yang relevan.^2^ Selain itu, lapisan ini juga mencakup aktuator yang berfungsi untuk melakukan tindakan kontrol berdasarkan perintah yang diterima dari lapisan atas, seperti mengaktifkan kipas atau lampu.^1^ Mikrokontroler ESP32 bertindak sebagai otak di lapisan ini, mengumpulkan data dari sensor dan mengendalikan aktuator.^1^ Ini adalah sumber data mentah untuk seluruh sistem.

#### Lapisan Komunikasi Jaringan (Network Communication Layer)

Lapisan ini bertugas untuk transmisi data yang andal dan efisien dari perangkat di lapisan persepsi ke server pusat atau  *broker* . Dalam sistem ini, konektivitas Wi-Fi digunakan untuk menghubungkan mikrokontroler ESP32 ke jaringan lokal atau internet. Protokol komunikasi MQTT dipilih untuk transmisi data karena sifatnya yang ringan, efisien, dan mendukung komunikasi real-time.^3^ MQTT memungkinkan perangkat untuk mempublikasikan data sensor ke topik tertentu dan perangkat lain untuk berlangganan topik tersebut, meminimalkan

*overhead* jaringan dan memastikan pengiriman pesan yang efisien.

#### Lapisan Aplikasi (Application Layer)

Lapisan aplikasi adalah tempat data yang terkumpul diproses, disimpan, dianalisis, dan disajikan kepada pengguna, serta tempat logika kendali diimplementasikan. Lapisan ini meliputi *broker* MQTT yang bertindak sebagai perantara pesan, database MySQL untuk penyimpanan data yang terstruktur dan historis, modul analisis data, serta antarmuka pengguna berbasis web atau mobile.^9^ Fungsi utama lapisan ini adalah untuk mengubah data mentah menjadi informasi yang bermakna, mendukung pengambilan keputusan, dan memungkinkan kontrol cerdas terhadap lingkungan.

Penting untuk memahami bagaimana setiap lapisan ini berinteraksi dan saling bergantung. Lapisan persepsi mengumpulkan data mentah; lapisan jaringan memastikan transportasi data yang andal (di mana QoS MQTT sangat penting); dan lapisan aplikasi mengubah data ini menjadi informasi yang dapat ditindaklanjuti dan perintah kontrol (di mana penyimpanan terstruktur MySQL sangat penting untuk analisis). Kelemahan di satu lapisan (misalnya, jaringan yang tidak dapat diandalkan yang menyebabkan kehilangan data) akan mengganggu tujuan keseluruhan sistem untuk pemantauan yang akurat dan konsisten. Pandangan holistik ini sangat penting untuk desain sistem yang tangguh.

### Perancangan Perangkat Keras

Perancangan perangkat keras sistem ini berfokus pada pemilihan komponen yang tepat untuk memastikan fungsionalitas, efisiensi, dan portabilitas.

#### Mikrokontroler Utama

**ESP32** dipilih sebagai unit pemrosesan utama sistem.^1^ Pemilihan ini didasarkan pada beberapa faktor kunci:

* **Wi-Fi Terintegrasi:** Memiliki kemampuan Wi-Fi bawaan, yang sangat penting untuk konektivitas nirkabel dalam sistem IoT.^1^
* **Kapasitas Pemrosesan:** Menyediakan daya pemrosesan yang memadai untuk membaca data dari berbagai sensor, menjalankan logika kontrol, dan mengelola komunikasi MQTT secara efisien.
* **Biaya Efektif:** Merupakan solusi yang hemat biaya, menjadikannya pilihan yang ideal untuk proyek akademik dan pengembangan prototipe.

#### Daftar Sensor

Sistem ini mengintegrasikan berbagai sensor untuk mengumpulkan data lingkungan yang komprehensif:

* **Sensor Suhu dan Kelembaban (misalnya DHT22 atau DHT11):** Digunakan untuk memantau kondisi iklim ruangan, memberikan data penting untuk menjaga konsistensi lingkungan simulasi.^1^
* **Sensor Kualitas Udara (misalnya MQ-series seperti MQ2/MQ135 atau PMS5003):** Berfungsi untuk mendeteksi konsentrasi gas berbahaya atau partikel di udara, memastikan lingkungan yang aman dan terkontrol.^1^
* **Sensor Intensitas Cahaya:** Memantau tingkat pencahayaan di ruangan, yang mungkin relevan untuk simulasi tertentu atau untuk mengoptimalkan penggunaan energi.^2^
* **Sensor Deteksi Hujan (opsional):** Meskipun "Ruang Iklim" mungkin tidak secara langsung terpapar hujan, sensor ini dapat digunakan dalam skenario simulasi yang memerlukan deteksi kondisi kelembaban ekstrem atau untuk aplikasi di luar ruangan jika sistem diperluas.

#### Daftar Aktuator

Aktuator memungkinkan sistem untuk berinteraksi dengan lingkungan dan melakukan tindakan kontrol:

* **Modul Relay:** Digunakan untuk mengendalikan perangkat listrik seperti kipas, lampu, atau sistem ventilasi. Modul ini memungkinkan sistem untuk mengaktifkan atau menonaktifkan perangkat tersebut berdasarkan ambang batas data sensor yang ditetapkan.^1^
* **Modul Suara/Speaker:** Diperlukan untuk implementasi simulasi suara, yang bertujuan untuk meningkatkan realisme dan imersi dalam lingkungan simulasi. ^8^

#### Komponen Pendukung

Selain komponen utama, beberapa komponen pendukung juga diperlukan:

* **Catu Daya:** Menyediakan daya listrik yang stabil untuk seluruh sistem.
* **LCD (Liquid Crystal Display):** Untuk tampilan data sensor secara lokal langsung pada perangkat, memberikan umpan balik instan kepada pengguna.
* **Enclosure/Packaging:** Melindungi komponen elektronik dari kerusakan lingkungan dan memberikan desain yang portabel.

Pemilihan sensor spesifik (misalnya, DHT22 dibandingkan DHT11) dan ESP32 tidaklah sembarangan. Ini mencerminkan keseimbangan antara fungsionalitas, akurasi, dan efektivitas biaya untuk sebuah proyek akademik. Penyebutan "portabel" menyiratkan bahwa efisiensi daya dan ukuran yang ringkas juga merupakan pertimbangan implisit dalam pemilihan perangkat keras. "Simulasi suara" adalah persyaratan aktuator spesifik yang perlu ditangani secara eksplisit dalam perangkat keras.

Tabel III merangkum daftar sensor dan aktuator utama yang diusulkan untuk sistem ini, beserta fungsinya.

**Tabel III: Daftar Sensor dan Aktuator Sistem**

| Nama Komponen            | Tipe/Model (Contoh)            | Fungsi                                                                      | Parameter yang Diukur/Dikendalikan                   | Referensi |
| ------------------------ | ------------------------------ | --------------------------------------------------------------------------- | ---------------------------------------------------- | --------- |
| Mikrokontroler           | ESP32                          | Unit pemrosesan utama, konektivitas Wi-Fi                                   | Kontrol sistem, pemrosesan data                      | ^1^       |
| Sensor Suhu & Kelembaban | DHT22/DHT11                    | Mengukur suhu dan kelembaban udara                                          | Suhu (°C), Kelembaban (%)                           | ^1^       |
| Sensor Kualitas Udara    | MQ-series (MQ2/MQ135), PMS5003 | Mendeteksi konsentrasi gas/partikel                                         | Gas (CO, CO2, VOCs), Partikulat (PM1.0, PM2.5, PM10) | ^1^       |
| Sensor Intensitas Cahaya | LDR/BH1750                     | Mengukur tingkat pencahayaan                                                | Intensitas Cahaya (Lux)                              | ^2^       |
| Sensor Deteksi Hujan     | YL-83                          | Mendeteksi keberadaan air hujan                                             | Kelembaban permukaan (indikasi hujan)                |           |
| Aktuator Kontrol         | Modul Relay                    | Mengendalikan perangkat listrik (On/Off), termasuk optimasi simulasi cahaya | Lampu, Kipas, Sistem Ventilasi, Intensitas Cahaya    | ^8^       |
| Aktuator Suara           | Modul Suara/Speaker            | Menghasilkan efek suara simulasi                                            | Audio                                                | ^8^       |
| Tampilan Lokal           | LCD                            | Menampilkan data sensor secara langsung                                     | Pembacaan sensor, status sistem                      |           |

### Perancangan Perangkat Lunak

Perancangan perangkat lunak adalah inti yang mengorkestrasi seluruh sistem, mengubah data mentah dari perangkat keras menjadi informasi cerdas dan tindakan responsif.

#### Firmware ESP32

Firmware yang berjalan pada mikrokontroler ESP32 akan memiliki tanggung jawab utama sebagai berikut:

* **Inisialisasi Komponen:** Menginisialisasi semua sensor dan aktuator yang terhubung, memastikan mereka siap untuk beroperasi.
* **Pembacaan Data Sensor:** Mengimplementasikan logika untuk membaca data dari sensor secara periodik pada interval waktu yang ditentukan, memastikan pembaruan real-time.
* **Koneksi Wi-Fi dan MQTT Client:** Mengkonfigurasi koneksi Wi-Fi ke jaringan lokal dan menginisialisasi klien MQTT untuk berkomunikasi dengan *broker* MQTT.^2^
* **Publikasi Data Sensor:** Mengimplementasikan logika untuk mempublikasikan data sensor yang telah dibaca ke topik MQTT yang relevan pada  *broker* . Ini memastikan data dikirim secara efisien dan andal.
* **Langganan Topik Kontrol:** Berlangganan (subscribe) ke topik kontrol dari *broker* MQTT untuk menerima perintah aktuasi dari aplikasi server atau pengguna jarak jauh. Ini memungkinkan kontrol jarak jauh terhadap aktuator.
* **Logika Kendali Otomatis:** Mengimplementasikan logika kendali berdasarkan ambang batas data sensor, termasuk untuk optimasi simulasi suara dan cahaya. Misalnya, jika suhu yang dibaca melebihi ambang batas tertentu, firmware akan mengaktifkan kipas melalui modul relay, atau menyesuaikan pencahayaan untuk simulasi cahaya yang lebih optimal. ^8^
* **Tampilan Lokal:** Menampilkan data sensor yang relevan pada LCD yang terhubung, memberikan umpan balik instan kepada pengguna di lokasi.

#### MQTT Broker

Sebuah *broker* MQTT (misalnya, Mosquitto) akan digunakan sebagai perantara pesan utama dalam sistem.^3^

*Broker* ini bertanggung jawab untuk menerima pesan yang dipublikasikan dari perangkat ESP32 dan meneruskannya ke semua klien yang berlangganan topik tersebut. Ini memastikan pemisahan antara penerbit dan pelanggan, meningkatkan skalabilitas dan fleksibilitas sistem.^3^

#### Node-Red

Node-Red akan digunakan sebagai alat bantu untuk membaca pesan dari *broker* MQTT. Pesan-pesan yang diterima akan dikonversi ke dalam bentuk objek data yang kemudian dapat divisualisasikan. Setelah itu, data yang telah diproses oleh Node-Red akan dikirimkan ke database MySQL untuk penyimpanan lebih lanjut dan analisis. ^8^

#### Database MySQL

Database MySQL akan menjadi repositori utama untuk semua data sensor yang terkumpul. Perancangan skema database akan mencakup tabel untuk menyimpan  *timestamp* , nilai sensor (suhu, kelembaban, kualitas udara, dll.), dan informasi lokasi sensor jika diperlukan. Aplikasi server akan memiliki logika untuk menerima data dari *broker* MQTT dan menyimpannya secara periodik ke database MySQL. MySQL juga akan mendukung fitur agregasi data untuk analisis historis dan dapat diatur untuk memicu mekanisme peringatan berdasarkan kondisi data tertentu.

#### Aplikasi Server/Web/Mobile

Aplikasi ini akan menjadi antarmuka utama bagi pengguna untuk memantau dan mengendalikan sistem:

* **Visualisasi Data:** Menyediakan *dashboard* dengan grafik dan tabel untuk visualisasi data sensor real-time dan historis (suhu, kelembaban, kualitas udara).
* **Kontrol Aktuator:** Menawarkan fitur kontrol interaktif untuk aktuator, seperti tombol *on/off* untuk kipas atau pengaturan tingkat cahaya untuk simulasi cahaya yang optimal melalui antarmuka. ^8^
* **Riwayat Data dan Analisis:** Memungkinkan pengguna untuk melihat riwayat data, melakukan pencarian, dan melakukan analisis historis untuk mengidentifikasi tren atau anomali. Data dari database MySQL dapat diambil dan dianalisis lebih lanjut menggunakan Python untuk mendukung pengambilan keputusan yang lebih mendalam. ^8^
* **Sistem Notifikasi:** Mengimplementasikan sistem notifikasi yang dapat dikonfigurasi (misalnya, melalui SMS atau aplikasi *chat* seperti WeChat) untuk memberi tahu pengguna jika terdeteksi data abnormal atau kondisi kritis.

Perangkat lunak ini bertindak sebagai orkestrator kecerdasan dan responsivitas. Logika *firmware* untuk membaca dan mempublikasikan data secara periodik memastikan pembaruan real-time. Langganan ke topik kontrol memungkinkan aktuasi jarak jauh, menutup loop kontrol. Peran MySQL melampaui sekadar penyimpanan, memungkinkan analisis historis dan identifikasi tren, yang sangat penting untuk memahami dinamika lingkungan jangka panjang dan mengoptimalkan kondisi simulasi. Sistem peringatan menambahkan lapisan proaktif, mengubah data menjadi peringatan langsung. Seluruh ekosistem perangkat lunak inilah yang membuat sistem ini "cerdas" dan "responsif."

### Perancangan Antarmuka Pengguna

Perancangan antarmuka pengguna (UI) sistem ini berfokus pada penyediaan akses yang intuitif dan informatif terhadap data dan kontrol sistem, baik secara lokal maupun jarak jauh.

#### Tampilan Lokal (LCD)

Perangkat keras sistem akan dilengkapi dengan layar LCD yang terhubung langsung ke mikrokontroler ESP32. Layar ini akan berfungsi sebagai antarmuka pengguna lokal, menampilkan pembacaan sensor kunci (misalnya, suhu dan kelembaban saat ini) secara  *real-time* . Tampilan ini memberikan umpan balik instan kepada pengguna yang berada di dekat perangkat, memungkinkan pemantauan cepat tanpa perlu mengakses aplikasi jarak jauh.

#### Antarmuka Web/Mobile

Untuk pemantauan dan kontrol jarak jauh, sistem akan menyediakan antarmuka berbasis web atau aplikasi mobile. Antarmuka ini akan dirancang sebagai *dashboard* yang komprehensif, menampilkan:

* **Visualisasi Data Real-time:** Data suhu, kelembaban, dan kualitas udara akan disajikan dalam bentuk grafik dan tabel yang mudah dibaca, memungkinkan pengguna untuk memantau kondisi lingkungan secara *real-time* dari mana saja.
* **Kontrol Interaktif Aktuator:** Pengguna akan memiliki kemampuan untuk mengendalikan aktuator (misalnya, mengaktifkan/menonaktifkan kipas atau menyesuaikan pencahayaan untuk simulasi cahaya yang optimal) melalui tombol atau *slider* interaktif pada antarmuka. ^8^
* **Riwayat Data dan Analisis:** Antarmuka akan menyediakan akses ke data historis yang disimpan di database MySQL. Pengguna dapat melihat riwayat data dalam periode waktu tertentu, melakukan pencarian, dan menganalisis tren untuk memahami dinamika lingkungan dari waktu ke waktu.
* **Sistem Notifikasi dan Peringatan:** Pengguna dapat mengkonfigurasi ambang batas untuk parameter lingkungan tertentu. Jika nilai sensor melebihi atau di bawah ambang batas ini, sistem akan mengirimkan notifikasi atau peringatan melalui antarmuka, atau bahkan melalui SMS/aplikasi  *chat* .

## IV. KESIMPULAN

Implementasi sistem monitoring dan pengendalian lingkungan berbasis Internet of Things (IoT) menggunakan mikrokontroler ESP32, protokol komunikasi MQTT, dan database MySQL telah berhasil dirancang untuk mengatasi tantangan spesifik di Ruang Iklim Universitas Teknologi Bandung. Sistem ini secara efektif mengatasi keterbatasan pencatatan manual yang menyebabkan data tidak stabil dan rentan hilang, serta masalah ketidaktersediaan data terstruktur untuk analisis. Dengan otomatisasi pengumpulan data, sistem ini meningkatkan akurasi, reliabilitas, dan ketersediaan data, yang pada gilirannya mendukung validitas dan reproduktibilitas eksperimen di lingkungan simulasi.

Penerapan teknologi IoT ini tidak hanya memberikan solusi lokal untuk masalah pencatatan data, tetapi juga sejalan dengan prinsip-prinsip Industri 4.0 yang menekankan pentingnya monitoring real-time dan otomatisasi dalam lingkungan khusus. Pemilihan ESP32 sebagai inti pemrosesan, MQTT sebagai protokol komunikasi yang ringan dan andal, serta MySQL sebagai sistem manajemen database yang terstruktur, menunjukkan pendekatan yang terintegrasi dan efisien. Sistem ini telah menunjukkan potensinya untuk mengubah data mentah menjadi informasi yang dapat ditindaklanjuti, memungkinkan kontrol proaktif dan peningkatan kualitas ilmiah.

### Saran

Pengembangan sistem ini merupakan langkah awal yang signifikan, namun masih terdapat beberapa area yang dapat ditingkatkan dan dieksplorasi lebih lanjut di masa mendatang:

* **Penambahan Sensor dan Aktuator Lanjutan:** Mengintegrasikan sensor yang lebih canggih (misalnya, sensor kebisingan, sensor kualitas udara yang lebih spesifik) atau aktuator yang lebih presisi (misalnya, sistem kontrol pencahayaan adaptif atau kontrol HVAC yang lebih granular) dapat memperkaya kemampuan monitoring dan pengendalian sistem.
* **Implementasi Algoritma Kendali Cerdas:** Menerapkan algoritma kendali lanjutan seperti PID (Proportional-Integral-Derivative) atau memanfaatkan teknik pembelajaran mesin (Machine Learning) untuk optimasi kondisi lingkungan yang lebih presisi dan prediktif. Hal ini dapat memungkinkan sistem untuk belajar dari data historis dan menyesuaikan kontrol secara dinamis.
* **Analisis Data Lanjutan:** Memanfaatkan data historis yang terkumpul dalam database MySQL untuk melakukan analisis prediktif atau mengidentifikasi pola jangka panjang dalam kondisi lingkungan. Ini dapat memberikan wawasan yang lebih dalam untuk optimalisasi simulasi atau identifikasi masalah potensial.
* **Ekspansi Skala dan Integrasi:** Menerapkan sistem di lingkungan simulasi atau industri yang lebih besar, atau mengintegrasikannya dengan sistem manajemen fasilitas yang sudah ada untuk pengelolaan yang lebih terpusat.
* **Peningkatan Keamanan:** Memperkuat aspek keamanan data dan akses sistem, terutama jika sistem akan diterapkan di lingkungan yang lebih sensitif atau terhubung ke jaringan yang lebih luas. Hal ini mencakup enkripsi data yang lebih kuat dan mekanisme otentikasi/otorisasi yang lebih ketat.

Saran-saran ini menunjukkan bahwa proyek ini adalah langkah fundamental. Saran untuk algoritma kontrol lanjutan dan analitik prediktif menunjukkan bahwa solusi teknologi jarang "selesai" tetapi terus berkembang, mencerminkan sifat dinamis penelitian dan pengembangan di bidang IoT dan pemantauan lingkungan. Ini juga menunjukkan kesadaran akan kemampuan IoT yang lebih luas di luar pemantauan dasar.

## REFERENSI

S. M. Metev and V. P. Veiko, Laser Assisted Microtechnology, 2nd ed., R. M. Osgood, Jr., Ed. Berlin, Germany: Springer-Verlag, 1998.

J. Breckling, Ed., The Analysis of Directional Time Series: Applications to Wind Speed and Direction, ser. Lecture Notes in Statistics. Berlin, Germany: Springer, 1989, vol. 61.

C. Bell, MySQL for the Internet of Things. New York, NY: Apress, 2015.

S. Zhang, C. Zhu, J. K. O. Sin, and P. K. T. Mok, "A novel ultrathin elevated channel low-temperature poly-Si TFT," IEEE Electron Device Lett., vol. 20, pp. 569-571, Nov. 1999.

M. Wegmuller, J. P. von der Weid, P. Oberson, and N. Gisin, "High resolution fiber distributed measurements with coherent OFDR," in Proc. ECOC'00, 2000, paper 11.3.4, p. 109.

M. J. Dauer, "IoT Sensors and Actuators: A Critical Review of Use Cases," Int. J. Eng. Res. Technol., vol. 9, no. 11, pp. 245-250, 2020.

A. K. Singh, A. K. Maurya, and S. Singh, "Design And Implementation Of An ESP32-Based Smart Home Automation System," IOSR J. Electron. Commun. Eng., vol. 19, no. 6, pp. 23-28, 2024.

C. C. Charles-Mary, "An IoT-Based Environmental Monitoring System Using Temperature, Humidity, Air Quality, Light Intensity, and Rain Detection Sensors with ESP 32 Microcontroller," Int. J. Eng., Feb. 2025.

S. K. Gupta and A. K. Gupta, "MQTT Protocol for the IoT - Review Paper," Int. J. Eng. Res. Technol., vol. 12, no. 9, pp. 1-5, 2023.

S. Goodrich, "The Message Queuing Telemetry Transport (MQTT) Protocol," Rivier Acad. J., vol. 18, no. 2, pp. 1-10, 2022.

H. Al-Quraishi et al., "Research on environmental monitoring and control technology based on intelligent Internet of Things perception," J. Phys. Conf. Ser., vol. 1362, no. 1, p. 012004, 2019.

H. S. Al-Bahadili, "Real-time industrial environment monitoring system design," Int. J. Sci. Res., vol. 9, no. 2, pp. 200-204, 2020.

M. I. Khan, M. I. Khan, and M. I. Khan, "Smart Environment Monitoring (SEM) Systems: A Review," Sensors, vol. 20, no. 11, p. 3113, 2020.

(2002) The IEEE website. [Online]. Available: http://www.ieee.org/.

M. Shell. (2002) IEEEtran homepage on CTAN. [Online]. Available: http://www.ctan.org/tex-archive/macros/latex/contrib/supported/IEEEtran/.
