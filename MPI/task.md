# Optimasi Sistem Monitoring dan Kendali Ruang Simulasi Industri Berbasis ESP32 dengan Metode Pub-Sub MQTT dan Desain Portabel: Tinjauan Pustaka

## I. Pendahuluan: Konteks Tesis dan Pentingnya Penelitian

### A. Latar Belakang dan Motivasi

Transformasi digital yang pesat telah mendorong peningkatan kebutuhan akan sistem monitoring dan kendali real-time di berbagai sektor, termasuk lingkungan industri dan simulasi.^1^ Dalam konteks Industri 4.0, integrasi teknologi Internet of Things (IoT) menjadi krusial untuk mencapai efisiensi operasional, meningkatkan produktivitas, dan mendukung keberlanjutan proses.^2^ Sistem monitoring tradisional seringkali menghadapi keterbatasan seperti respons yang lambat, kesulitan dalam pemeliharaan, dan biaya implementasi yang tinggi, yang menghambat kemampuan adaptasi terhadap dinamika lingkungan yang kompleks.^5^

Keterbatasan ini menjadi lebih nyata di lingkungan khusus seperti ruang simulasi industri atau laboratorium iklim, di mana parameter lingkungan perlu dimonitor dan dikendalikan dengan presisi tinggi untuk memastikan validitas dan reproduktibilitas eksperimen. Kebutuhan akan data yang akurat dan respons kendali yang cepat menjadi esensial untuk menjaga kondisi simulasi yang konsisten. Oleh karena itu, pengembangan solusi yang inovatif untuk mengatasi tantangan ini menjadi sangat penting.

### B. Tujuan Penelitian Tesis

Penelitian tesis ini bertujuan untuk mengoptimalkan sistem monitoring dan kendali ruang simulasi industri. Inti dari sistem yang diusulkan adalah penggunaan mikrokontroler ESP32, yang dikenal karena kapabilitas nirkabel dan kemampuannya dalam aplikasi IoT. Untuk komunikasi data, metode Pub-Sub MQTT (Message Queuing Telemetry Transport) akan diimplementasikan, dipilih karena sifatnya yang ringan dan efisien untuk perangkat terbatas.

Selain itu, fokus utama penelitian ini adalah pada pengembangan desain yang portabel. Aspek portabilitas ini akan memungkinkan fleksibilitas tinggi dalam penempatan dan penerapan sistem di berbagai lokasi dalam Laboratorium Iklim Universitas Teknologi Bandung, serta memfasilitasi adaptasi terhadap konfigurasi ruang simulasi yang berbeda. Pengoptimalan sistem akan mencakup peningkatan kinerja, efisiensi energi, dan pengurangan latensi komunikasi, memastikan sistem dapat beroperasi secara andal dan responsif dalam jangka panjang.

### C. Struktur Laporan Tinjauan Pustaka

Laporan tinjauan pustaka ini disusun untuk memberikan landasan komprehensif bagi penelitian tesis. Bagian selanjutnya akan membahas kriteria seleksi jurnal dan memberikan gambaran umum tentang sepuluh jurnal berbahasa Inggris yang relevan. Setelah itu, setiap jurnal akan ditinjau secara mendalam, mengidentifikasi tujuan, metodologi, kontribusi utama, dan hasil kunci. Bagian analisis komparatif akan menyintesis temuan dari seluruh jurnal, menyoroti persamaan dan perbedaan arsitektur sistem, strategi optimasi, serta relevansi aplikasi. Terakhir, laporan ini akan menyajikan kesimpulan dan rekomendasi yang dapat memandu pengembangan lebih lanjut dari penelitian tesis.

## II. Kriteria Seleksi dan Gambaran Umum Literatur yang Ditinjau

### A. Kriteria Seleksi Jurnal

Proses seleksi jurnal dilakukan dengan cermat untuk memastikan relevansi maksimal dengan topik tesis. Kriteria utama yang digunakan meliputi:

1. **Relevansi Tema:** Jurnal harus secara langsung membahas atau memiliki keterkaitan kuat dengan komponen-komponen kunci tesis, yaitu ESP32, protokol komunikasi MQTT (terutama model Pub-Sub), sistem monitoring dan kendali, aplikasi di lingkungan industri atau laboratorium, serta aspek desain portabel dan optimasi kinerja atau efisiensi energi.
2. **Bahasa Publikasi:** Hanya jurnal atau makalah konferensi berbahasa Inggris yang dipertimbangkan.
3. **Jenis Publikasi:** Prioritas diberikan pada artikel yang diterbitkan dalam jurnal ilmiah terkemuka atau prosiding konferensi yang direferensikan.
4. **Tahun Publikasi:** Publikasi yang lebih baru (dalam beberapa tahun terakhir) diutamakan untuk mencerminkan perkembangan teknologi terkini, meskipun beberapa studi fundamental yang lebih lama tetapi relevan juga dapat disertakan.

### B. Gambaran Umum Jurnal yang Terpilih

Berdasarkan kriteria di atas, sepuluh jurnal dan makalah konferensi berikut telah diidentifikasi dan ditinjau:

1. **Developing a Fire Monitoring System Based on MQTT, ESP-NOW, and a REM in Industrial Environments** oleh M. A. Navarrete-Sanchez et al. (2025).^5^
2. **Design and implementation of a low-cost, open source IoT-based SCADA system using ESP32 with OLED, ThingsBoard and MQTT protocol** oleh Lawrence O. Aghenta & M. Tariq Iqbal (2020).^6^
3. **IoT-Based Classroom Temperature Monitoring and Missing Data Prediction Using Raspberry Pi and ESP32** oleh M. A. Navarrete-Sanchez et al. (2025).^8^
4. **MQTT Protocol-Based ESP-32 Smarthome with Multi-sensor Recognition** oleh A. D. Putra et al. (2024).^1^
5. **Real-Time Data Acquisition with ESP32 for IoT Applications Using Open-Source MQTT Brokers** oleh Adrian-Iosif MAROȘAN et al. (2024).^2^
6. **Design and Implementation of ESP32-Based Edge Computing for Object Detection** oleh Q. Li et al. (2025).^10^
7. **Optimizing Data Transfer Speed and the Performance Evaluation of MQTT in IoT** oleh Y. Chen et al. (2025).^3^
8. **On/Off Temperature Monitoring and Control via the Internet of Things Using iTCLab Kit** oleh E. P. Wibowo et al. (2024).^11^
9. **Temperature and Humidity Control System with Air Conditioner Based on Fuzzy Logic and Internet of Things** oleh Furizal et al. (2023).^12^
10. **An Energy-Efficient E-Paper Sticky Note for Internet of Things (IoT) Applications** oleh A. M. El-Sayed et al. (2025).^13^

### C. Tabel 1: Gambaran Umum Jurnal yang Ditinjau

Tabel berikut menyajikan ringkasan singkat dari setiap jurnal yang ditinjau, memberikan gambaran cepat tentang fokus utama dan relevansinya dengan topik tesis. Tabel ini berfungsi sebagai referensi cepat bagi pembaca untuk memahami cakupan literatur yang disurvei.

| No. | Judul Jurnal                                                                                                                     | Penulis Utama           | Tahun Publikasi | Fokus Utama                                                                                                              | Relevansi dengan Topik Tesis                                                                                                              |
| --- | -------------------------------------------------------------------------------------------------------------------------------- | ----------------------- | --------------- | ------------------------------------------------------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------------------- |
| 1   | Developing a Fire Monitoring System Based on MQTT, ESP-NOW, and a REM in Industrial Environments                                 | M. A. Navarrete-Sanchez | 2025            | Sistem monitoring kebakaran real-time di lingkungan industri dengan komunikasi multi-hop dan optimasi penempatan node.   | Relevansi tinggi pada aspek monitoring industri, penggunaan ESP32, MQTT, dan strategi optimasi komunikasi di lingkungan kompleks.         |
| 2   | Design and implementation of a low-cost, open source IoT-based SCADA system using ESP32 with OLED, ThingsBoard and MQTT protocol | Lawrence O. Aghenta     | 2020            | Sistem SCADA IoT berbiaya rendah untuk monitoring dan kendali aset terdistribusi.                                        | Relevansi tinggi pada penggunaan ESP32, MQTT, monitoring & kendali, solusi*open-source* , dan visualisasi data.                         |
| 3   | IoT-Based Classroom Temperature Monitoring and Missing Data Prediction Using Raspberry Pi and ESP32                              | M. A. Navarrete-Sanchez | 2025            | Monitoring suhu kelas berbasis IoT dengan ESP32 dan Raspberry Pi, termasuk prediksi data hilang.                         | Relevansi tinggi pada monitoring lingkungan (suhu) di konteks laboratorium/ruangan, penggunaan ESP32, dan integrasi dengan platform lain. |
| 4   | MQTT Protocol-Based ESP-32 Smarthome with Multi-sensor Recognition                                                               | A. D. Putra             | 2024            | Sistem otomasi*smarthome*berbasis MQTT dan ESP32 dengan pengenalan multi-sensor.                                       | Relevansi tinggi pada penggunaan ESP32, MQTT, multi-sensor, kendali jarak jauh, dan validasi kinerja latensi.                             |
| 5   | Real-Time Data Acquisition with ESP32 for IoT Applications Using Open-Source MQTT Brokers                                        | Adrian-Iosif MAROȘAN   | 2024            | Akuisisi data real-time dan monitoring menggunakan ESP32 dan broker MQTT*open-source*untuk aplikasi IoT.               | Relevansi tinggi pada akuisisi data real-time, penggunaan ESP32, MQTT, dan relevansi dengan Industri 4.0.                                 |
| 6   | Design and Implementation of ESP32-Based Edge Computing for Object Detection                                                     | Q. Li                   | 2025            | Aplikasi ESP32 dalam*edge computing*untuk deteksi objek, mengurangi beban*cloud*dan latensi.                         | Relevansi sedang pada optimasi latensi dan*bandwidth*melalui*edge computing*pada ESP32, meskipun fokus aplikasi berbeda.              |
| 7   | Optimizing Data Transfer Speed and the Performance Evaluation of MQTT in IoT                                                     | Y. Chen                 | 2025            | Analisis kinerja MQTT dalam IoT, fokus pada kecepatan transfer data dan latensi untuk monitoring kondisi atmosfer.       | Relevansi tinggi pada optimasi kinerja MQTT, latensi, dan QoS, penting untuk sistem real-time.                                            |
| 8   | On/Off Temperature Monitoring and Control via the Internet of Things Using iTCLab Kit                                            | E. P. Wibowo            | 2024            | Demonstrasi sistem kendali suhu On/Off berbasis IoT menggunakan kit iTCLab (ESP32).                                      | Relevansi tinggi pada monitoring dan kendali suhu, penggunaan ESP32, dan kendali jarak jauh via aplikasi*smartphone* .                  |
| 9   | Temperature and Humidity Control System with Air Conditioner Based on Fuzzy Logic and Internet of Things                         | Furizal                 | 2023            | Sistem kendali AC berbasis Fuzzy Logic dan IoT untuk suhu dan kelembaban ruangan menggunakan ESP32.                      | Relevansi tinggi pada kendali iklim (suhu dan kelembaban), penggunaan ESP32, dan integrasi algoritma kendali canggih.                     |
| 10  | An Energy-Efficient E-Paper Sticky Note for Internet of Things (IoT) Applications                                                | A. M. El-Sayed          | 2025            | Perancangan perangkat IoT berdaya sangat rendah menggunakan ESP32 dengan tampilan e-paper dan strategi penghematan daya. | Relevansi tinggi pada aspek portabilitas dan efisiensi energi ESP32, termasuk mode*deep-sleep*dan pemilihan komponen.                   |

## III. Tinjauan Mendalam Jurnal-Jurnal Terpilih

Bagian ini menyajikan tinjauan mendalam dari setiap jurnal yang terpilih, menguraikan tujuan, metodologi, kontribusi utama, hasil kunci, dan implikasinya terhadap penelitian tesis.

### A. Jurnal 1: Developing a Fire Monitoring System Based on MQTT, ESP-NOW, and a REM in Industrial Environments

**Tujuan dan Metodologi:** Penelitian ini bertujuan untuk mengembangkan sistem monitoring kebakaran real-time yang tangguh di lingkungan industri yang berisiko tinggi. Sistem ini memanfaatkan mikrokontroler ESP32-CAM sebagai sensor utama, mengintegrasikan protokol komunikasi MQTT dan ESP-NOW, serta menggunakan Radio Environment Map (REM) untuk optimasi penempatan node.^5^ Metodologi yang digunakan melibatkan konfigurasi ESP32 sebagai node sumber, node relai, dan node

*gateway* dalam jaringan multi-hop, memastikan transmisi data yang efisien dan andal.

**Kontribusi Utama:** Kontribusi signifikan dari studi ini adalah demonstrasi keberhasilan integrasi MQTT dengan protokol nirkabel lain, yaitu ESP-NOW, untuk memfasilitasi komunikasi multi-hop dengan latensi rendah. Selain itu, penggunaan REM untuk mengoptimalkan penempatan node merupakan pendekatan inovatif untuk memastikan cakupan jaringan yang komprehensif dan meminimalkan kehilangan paket di lingkungan industri yang kompleks.^5^

**Hasil Kunci:** Hasil eksperimen menunjukkan kinerja sistem yang luar biasa, dengan tingkat keberhasilan deteksi kebakaran mencapai 100%. Latensi transmisi data berhasil dikurangi secara signifikan hingga 150 milidetik, dan tidak ada kehilangan paket yang terdeteksi di bawah konfigurasi yang dipandu REM.^5^ Temuan ini memvalidasi kesesuaian sistem untuk aplikasi monitoring real-time di lingkungan industri yang menuntut.

**Implikasi untuk Tesis:**

* **Integrasi Protokol:** Studi ini secara jelas menunjukkan bahwa MQTT dapat diintegrasikan secara efektif dengan protokol nirkabel lain seperti ESP-NOW untuk mengatasi tantangan komunikasi di lingkungan yang luas atau terhalang. Hal ini penting untuk ruang simulasi industri yang mungkin memerlukan jangkauan komunikasi yang diperluas atau memiliki potensi interferensi, yang berarti desain sistem dapat mempertimbangkan kombinasi protokol untuk mencapai keandalan dan latensi yang diinginkan.
* **Optimasi Penempatan Node:** Penggunaan Radio Environment Map (REM) untuk penempatan node secara optimal adalah pendekatan yang sangat relevan. Konsep ini dapat diadaptasi untuk memastikan cakupan sensor yang optimal dan komunikasi yang kuat di Laboratorium Iklim, terutama jika ruang simulasi memiliki ukuran yang besar atau banyak penghalang fisik. Ini memperluas pemahaman tentang "desain portabel" tidak hanya dari segi ukuran fisik perangkat, tetapi juga kemampuan untuk menempatkan perangkat secara cerdas demi kinerja jaringan yang superior.
* **Ketahanan di Lingkungan Industri:** Validasi sistem di lingkungan industri berisiko tinggi menunjukkan tingkat ketahanan dan keandalan yang tinggi. Keandalan semacam ini sangat dibutuhkan dalam laboratorium simulasi industri, di mana kegagalan sistem dapat mengganggu eksperimen atau menghasilkan data yang tidak valid.

### B. Jurnal 2: Design and implementation of a low-cost, open source IoT-based SCADA system using ESP32 with OLED, ThingsBoard and MQTT protocol

**Tujuan dan Metodologi:** Penelitian ini berfokus pada perancangan dan implementasi sistem SCADA (Supervisory Control and Data Acquisition) berbasis IoT yang berbiaya rendah dan  *open-source* . Sistem ini ditujukan untuk monitoring dan kendali aset terdistribusi, menggunakan mikrokontroler ESP32, platform IoT ThingsBoard, dan protokol MQTT untuk komunikasi data.^6^ Metodologi melibatkan penggunaan ESP32 sebagai klien MQTT untuk mengumpulkan data sensor dan mengirimkannya ke ThingsBoard yang berfungsi sebagai broker MQTT dan server data.

**Kontribusi Utama:** Kontribusi utama dari studi ini adalah penyediaan solusi SCADA berbasis IoT yang komprehensif, hemat biaya, dan  *open-source* . Ini menunjukkan bagaimana ESP32 dapat berfungsi sebagai klien MQTT yang efektif, dan bagaimana platform seperti ThingsBoard dapat digunakan untuk manajemen data historis, interaksi manusia-mesin (HMI), serta visualisasi melalui dasbor dan alarm.^6^

**Hasil Kunci:** Sistem yang diusulkan berhasil menunjukkan kemampuan akuisisi data real-time, monitoring jarak jauh, dan kendali terkoordinasi terhadap aset-aset terdistribusi. Hal ini membuktikan kelayakan pendekatan *open-source* untuk sistem kendali industri.

**Implikasi untuk Tesis:**

* **Solusi Hemat Biaya dan  *Open-Source* :** Penekanan pada solusi yang berbiaya rendah dan *open-source* sangat relevan untuk konteks laboratorium universitas, di mana anggaran seringkali menjadi pertimbangan penting. Penggunaan ThingsBoard sebagai platform IoT dan MQTT sebagai protokol komunikasi menawarkan kerangka kerja yang kuat dan dapat diakses untuk visualisasi data dan interaksi HMI, yang dapat mengurangi biaya pengembangan dan lisensi.
* **Integrasi HMI dan Visualisasi:** Kemampuan ThingsBoard untuk secara otomatis membuat dasbor dan alarm ^15^ sangat berharga untuk sistem monitoring dan kendali ruang simulasi. Ini menyederhanakan proses pengembangan antarmuka pengguna, memungkinkan visualisasi data real-time yang efektif, dan memfasilitasi pengambilan keputusan yang cepat berdasarkan kondisi lingkungan yang dimonitor.

### C. Jurnal 3: IoT-Based Classroom Temperature Monitoring and Missing Data Prediction Using Raspberry Pi and ESP32

**Tujuan dan Metodologi:** Studi ini berfokus pada monitoring suhu yang akurat di lingkungan kelas, dengan tujuan mengoptimalkan kondisi ruangan untuk kenyamanan dan kinerja siswa. Sistem ini memanfaatkan arsitektur perangkat IoT yang saling terhubung dengan komunikasi Wi-Fi, menggunakan mikrokontroler ESP32 dan sensor suhu DS18B20 yang ditempatkan secara strategis. Selain monitoring, penelitian ini juga membahas prediksi data yang hilang untuk memastikan keandalan data.^8^

**Kontribusi Utama:** Kontribusi utama adalah pengembangan arsitektur monitoring suhu berbasis IoT yang hemat biaya, mudah diintegrasikan, dan mampu memberikan data real-time untuk lingkungan pendidikan. Penggunaan ESP32 sebagai prosesor sentral untuk mengumpulkan dan mengirimkan data sensor melalui jaringan Wi-Fi lokal yang aman menjadi inti sistem ini.^8^

**Hasil Kunci:** Sistem yang diusulkan berhasil menunjukkan monitoring suhu yang akurat, serta keunggulan dalam hal efektivitas biaya, kemudahan integrasi, dan kemampuan monitoring real-time. Keamanan jaringan lokal yang digunakan juga memastikan transmisi data yang andal dan tanpa gangguan.^8^

**Implikasi untuk Tesis:**

* **Lingkungan Mirip Laboratorium:** Konteks "kelas" atau "laboratorium elektronik" yang dimonitor dalam studi ini sangat mirip dengan "Laboratorium Iklim" pada tesis. Ini menunjukkan kelayakan dan kesesuaian implementasi ESP32 untuk aplikasi monitoring lingkungan dalam skala tersebut, memberikan validasi awal untuk lingkungan target tesis.
* **Kombinasi ESP32 dan Raspberry Pi:** Penggunaan kombinasi ESP32 (untuk akuisisi data sensor) dan Raspberry Pi (untuk pemrosesan data yang lebih kompleks, berpotensi sebagai broker MQTT lokal atau  *gateway* ) dapat menjadi arsitektur yang kuat. Ini memungkinkan sistem portabel yang membutuhkan daya komputasi lebih tinggi di sisi *edge* atau untuk penyimpanan data lokal, yang dapat meningkatkan kinerja dan mengurangi ketergantungan pada layanan  *cloud* .

### D. Jurnal 4: MQTT Protocol-Based ESP-32 Smarthome with Multi-sensor Recognition

**Tujuan dan Metodologi:** Penelitian ini bertujuan untuk mengembangkan sistem otomasi *smarthome* yang memanfaatkan protokol MQTT dan mikrokontroler ESP32, dengan kemampuan pengenalan multi-sensor. Metodologi yang diterapkan meliputi perancangan, pengembangan, dan pengujian sistem untuk menilai efikasi dan efisiensi dibandingkan dengan penelitian sebelumnya.^1^

**Kontribusi Utama:** Studi ini berhasil memvalidasi akurasi sensor yang digunakan (misalnya, sensor suhu menunjukkan akurasi 98.12%) dan menunjukkan kinerja latensi rendah dari protokol MQTT. Latensi rata-rata yang dicapai adalah 0.725 detik untuk aplikasi MQTT Dashboard dan 0.67 detik untuk aplikasi Node-RED.^1^

**Hasil Kunci:** Sistem otomasi yang dirancang berfungsi sesuai harapan, memungkinkan kendali perangkat elektronik dari jarak jauh menggunakan aplikasi *smartphone* dengan waktu respons yang cepat. Hal ini menegaskan keandalan sensor dan protokol MQTT untuk regulasi sistem otomatis.^1^

**Implikasi untuk Tesis:**

* **Validasi Akurasi Sensor dan Latensi MQTT:** Hasil akurasi sensor yang tinggi dan latensi MQTT yang rendah sangat mendukung kelayakan penggunaan ESP32 dan MQTT untuk aplikasi monitoring dan kendali real-time di laboratorium iklim. Data latensi ini memberikan metrik kinerja yang konkret dan realistis untuk ekspektasi sistem yang akan dibangun, membantu dalam penetapan target kinerja.
* **Kendali Jarak Jauh via  *Smartphone* :** Kemampuan untuk mengendalikan perangkat elektronik dari jarak jauh melalui aplikasi *smartphone* secara langsung mendukung persyaratan "kendali" pada judul tesis. Untuk desain portabel, kemampuan ini sangat berharga karena memungkinkan pengguna untuk berinteraksi dengan sistem dari mana saja, meningkatkan fleksibilitas operasional di lingkungan laboratorium.

### E. Jurnal 5: Real-Time Data Acquisition with ESP32 for IoT Applications Using Open-Source MQTT Brokers

**Tujuan dan Metodologi:** Studi ini memperkenalkan pendekatan baru untuk akuisisi data real-time dan monitoring menggunakan mikrokontroler ESP32 yang serbaguna dan broker MQTT  *open-source* .^2^ Tujuannya adalah untuk menyediakan platform yang kuat untuk pemrosesan dan visualisasi informasi yang dikumpulkan, dengan penekanan pada skalabilitas untuk infrastruktur IoT modern.

**Kontribusi Utama:** Kontribusi utama adalah demonstrasi stabilitas tinggi dan waktu respons cepat dari solusi yang diusulkan, menjadikannya sangat cocok untuk integrasi dalam konteks Industri 4.0. Studi ini juga menjelaskan konfigurasi perangkat keras dan pengembangan perangkat lunak yang diperlukan untuk mengelola protokol komunikasi dan integrasi MQTT.^2^

**Hasil Kunci:** Hasil eksperimen menunjukkan bahwa solusi yang diusulkan menjamin stabilitas tinggi dan waktu respons yang cepat. Hal ini menjadikannya relevan untuk berbagai domain, termasuk monitoring dan kendali jarak jauh di  *smart homes* , otomasi proses industri, dan pengembangan lingkungan cerdas. Sistem ini juga menunjukkan potensi signifikan untuk integrasi dengan teknologi Industri 4.0 seperti *augmented reality* (AR).^2^

**Implikasi untuk Tesis:**

* **Relevansi Industri 4.0:** Jurnal ini secara eksplisit menghubungkan penggunaan ESP32 dan MQTT dengan konsep Industri 4.0, yang menggarisbawahi relevansi sistem monitoring dan kendali yang diusulkan dalam konteks simulasi industri. Ini memperkuat justifikasi penelitian tesis dan menunjukkan bagaimana sistem yang dibangun dapat berkontribusi pada tren industri yang lebih luas.
* **Skalabilitas Broker MQTT  *Open-Source* :** Adaptasi broker MQTT *open-source* untuk memenuhi persyaratan skalabilitas infrastruktur IoT modern menunjukkan bahwa solusi yang diimplementasikan tidak hanya berbiaya rendah tetapi juga dapat diperluas untuk menangani lebih banyak sensor atau ruang simulasi di masa depan. Ini memberikan keyakinan bahwa sistem dapat tumbuh seiring dengan kebutuhan laboratorium.

### F. Jurnal 6: Design and Implementation of ESP32-Based Edge Computing for Object Detection

**Tujuan dan Metodologi:** Makalah ini mengeksplorasi aplikasi mikrokontroler ESP32 dalam  *edge computing* , dengan fokus pada perancangan dan implementasi sistem *edge server* untuk mengevaluasi peningkatan kinerja yang dicapai melalui integrasi komputasi *edge* dan  *cloud* .^10^ Penelitian ini merespons kebutuhan yang berkembang untuk mengurangi beban

*cloud* dan latensi.

**Kontribusi Utama:** Kontribusi signifikan dari studi ini adalah demonstrasi bahwa *edge server* berbasis ESP32 dapat secara signifikan mengurangi penggunaan *bandwidth* dan latensi. Hal ini secara efektif meringankan beban pada *cloud server* dan meningkatkan efisiensi sistem secara keseluruhan.^10^

**Hasil Kunci:** Hasil eksperimen menunjukkan bahwa pemrosesan data di *edge* (lebih dekat ke sumber data) meminimalkan persyaratan *bandwidth* dan mengurangi latensi, yang sangat penting untuk aplikasi sensitif waktu. Integrasi AI dan IoT dalam desain *edge server* ini menunjukkan manfaat pemrosesan lokal dalam meningkatkan efisiensi dan mengurangi ketergantungan  *cloud* .^10^

**Implikasi untuk Tesis:**

* **Optimasi Latensi dan *Bandwidth* via  *Edge Computing* :** Meskipun fokus aplikasi jurnal ini adalah deteksi objek, prinsip *edge computing* yang diterapkan pada ESP32 untuk mengurangi latensi dan penggunaan *bandwidth* sangat relevan. Ini menunjukkan bahwa sebagian pemrosesan data (misalnya, filtering, agregasi awal, atau normalisasi) dapat dilakukan langsung di ESP32 pada sistem portabel. Pendekatan ini dapat mengoptimalkan kinerja sistem secara keseluruhan dan mengurangi beban pada jaringan komunikasi.
* **Pengurangan Ketergantungan  *Cloud* :** Kemampuan untuk mengurangi ketergantungan pada infrastruktur *cloud* eksternal dengan menjalankan broker MQTT lokal di ESP32 itu sendiri ^16^ atau melakukan pra-pemrosesan data di
  *edge* ^10^ adalah aspek penting dari desain portabel. Hal ini memungkinkan sistem berfungsi secara lebih otonom atau dengan konektivitas internet yang terbatas, yang bisa menjadi keuntungan besar di lingkungan laboratorium di mana konektivitas
  *cloud* mungkin tidak selalu stabil atau diinginkan untuk alasan privasi data.

### G. Jurnal 7: Optimizing Data Transfer Speed and the Performance Evaluation of MQTT in IoT

**Tujuan dan Metodologi:** Penelitian ini bertujuan untuk menganalisis kinerja protokol MQTT dalam aplikasi IoT, dengan fokus khusus pada kecepatan transfer data dan latensi, terutama untuk monitoring kondisi atmosfer.^3^ Metodologi melibatkan pengujian ekstensif di bawah berbagai kondisi jaringan untuk mengevaluasi latensi transmisi dan

*throughput* MQTT.

**Kontribusi Utama:** Kontribusi utama adalah validasi empiris efisiensi MQTT untuk pengiriman data real-time, menunjukkan latensi rata-rata di bawah 50 milidetik di berbagai skenario. Studi ini juga membandingkan MQTT dengan protokol lain seperti CoAP, menunjukkan bahwa MQTT secara konsisten mengungguli CoAP dalam hal latensi dan pemanfaatan  *bandwidth* , terutama di jaringan yang rentan terhadap kehilangan paket.^3^

**Hasil Kunci:** Hasil penelitian menegaskan kesesuaian MQTT untuk monitoring lingkungan real-time dan potensi penggunaannya dalam aplikasi IoT yang lebih luas yang memerlukan transfer data cepat dan andal. Diskusi tentang tingkat *Quality of Service* (QoS) MQTT juga memberikan pemahaman tentang *trade-off* antara kecepatan pengiriman dan keandalan.^3^

**Implikasi untuk Tesis:**

* **Konfirmasi Efisiensi MQTT:** Studi ini secara langsung mengkonfirmasi efisiensi MQTT untuk pengiriman data real-time dengan latensi rendah (rata-rata <50ms), yang sangat krusial untuk sistem kendali yang responsif di ruang simulasi industri. Ini memberikan dasar yang kuat untuk memilih MQTT sebagai protokol komunikasi utama.
* **Pilihan QoS MQTT:** Diskusi tentang *Quality of Service* (QoS) MQTT (QoS 0 untuk latensi terendah dengan potensi kehilangan pesan, QoS 2 untuk pengiriman terjamin dengan latensi lebih tinggi) memberikan panduan penting. Ini memungkinkan peneliti tesis untuk mengoptimalkan komunikasi data berdasarkan kebutuhan spesifik setiap sensor dan aktuator di laboratorium, menyeimbangkan kecepatan dan keandalan sesuai prioritas.

### H. Jurnal 8: On/Off Temperature Monitoring and Control via the Internet of Things Using iTCLab Kit

**Tujuan dan Metodologi:** Penelitian ini bertujuan untuk mendemonstrasikan implementasi sistem kendali suhu On/Off berbasis IoT menggunakan kit iTCLab, yang dilengkapi dengan mikrokontroler ESP32, serta aplikasi IoT MQTT Panel untuk monitoring dan kendali via  *smartphone* .^11^ Metodologi melibatkan pemrograman kit iTCLab dengan Arduino IDE untuk akuisisi data suhu dan konektivitas IoT.

**Kontribusi Utama:** Kontribusi utama adalah validasi sistem monitoring suhu yang berfungsi dengan baik dan kemampuan kendali suhu dari jarak jauh melalui aplikasi  *smartphone* . Ini menunjukkan bagaimana platform berbasis ESP32 dapat digunakan untuk aplikasi kendali dasar dengan interaksi pengguna yang intuitif.

**Hasil Kunci:** Hasil eksperimen menunjukkan bahwa sistem kendali On/Off suhu berhasil diimplementasikan dan berfungsi sesuai harapan, dengan monitoring dan kendali yang efektif melalui aplikasi seluler.^11^ Ini membuktikan kelayakan penggunaan ESP32 dan MQTT untuk kendali sederhana di lingkungan laboratorium.

**Implikasi untuk Tesis:**

* **Fondasi Kendali Jarak Jauh:** Meskipun menggunakan kendali On/Off yang sederhana, jurnal ini menunjukkan fondasi yang kuat untuk kendali jarak jauh melalui MQTT dan  *smartphone* . Ini dapat menjadi titik awal yang baik untuk mengimplementasikan strategi kendali yang lebih canggih (misalnya, PID atau Fuzzy Logic) pada sistem tesis, membangun di atas kemampuan dasar yang telah divalidasi.
* **Penggunaan Kit Pembelajaran:** Penggunaan kit iTCLab yang berbasis ESP32 menunjukkan bagaimana platform yang relatif sederhana dan berbiaya rendah dapat digunakan untuk eksperimen monitoring dan kendali IoT. Hal ini relevan untuk lingkungan laboratorium yang mungkin mencari solusi yang mudah diimplementasikan dan terjangkau untuk tujuan pendidikan atau penelitian awal.

### I. Jurnal 9: Temperature and Humidity Control System with Air Conditioner Based on Fuzzy Logic and Internet of Things

**Tujuan dan Metodologi:** Penelitian ini bertujuan untuk mengembangkan sistem kendali AC yang efektif dan efisien untuk mengelola suhu dan kelembaban ruangan. Sistem ini didasarkan pada pendekatan Fuzzy Logic (menggunakan metode Tsukamoto) dan diintegrasikan dengan Internet of Things (IoT), menggunakan sensor DHT22 dan mikrokontroler ESP32 sebagai pusat pemrosesan.^12^

**Kontribusi Utama:** Kontribusi utama adalah implementasi sistem kendali AC otomatis dan jarak jauh yang adaptif, yang mampu menyesuaikan suhu AC berdasarkan pembacaan suhu dan kelembaban ruangan secara real-time. Ini menunjukkan potensi ESP32 dalam mengintegrasikan algoritma kendali cerdas.

**Hasil Kunci:** Hasil studi menunjukkan bahwa kendali suhu ruangan dapat dilakukan secara efektif, dengan rata-rata perubahan suhu sekitar -1.67°C dan suhu rata-rata keseluruhan 25.95°C. Namun, kendali kelembaban tidak menunjukkan keberhasilan yang sama, dengan rata-rata kelembaban 80.16% yang masih tergolong "Basah", menunjukkan area untuk pengembangan lebih lanjut.^12^

**Implikasi untuk Tesis:**

* **Kendali Iklim Lanjutan:** Penggunaan Fuzzy Logic untuk kendali suhu dan kelembaban sangat relevan untuk "Laboratorium Iklim" pada tesis. Ini menunjukkan bagaimana ESP32 dapat diintegrasikan dengan algoritma kendali canggih untuk mencapai dan mempertahankan kondisi lingkungan yang spesifik dan stabil, yang merupakan persyaratan utama untuk ruang simulasi industri.
* **Tantangan Kendali Kelembaban:** Temuan bahwa kendali kelembaban kurang berhasil menyoroti potensi tantangan dalam mengelola beberapa parameter lingkungan secara simultan dengan presisi yang sama. Ini merupakan pertimbangan penting untuk ruang simulasi industri yang mungkin memerlukan kendali presisi terhadap berbagai variabel lingkungan, dan menunjukkan perlunya penelitian lebih lanjut atau strategi kendali yang lebih kompleks untuk kelembaban.

### J. Jurnal 10: An Energy-Efficient E-Paper Sticky Note for Internet of Things (IoT) Applications

**Tujuan dan Metodologi:** Penelitian ini bertujuan untuk merancang dan mengimplementasikan perangkat IoT berdaya sangat rendah, menyerupai catatan tempel digital, menggunakan mikrokontroler ESP32 (khususnya ESP32-S3) dengan tampilan e-paper. Metodologi melibatkan pemilihan komponen perangkat keras yang efisien, perancangan arsitektur sistem, dan pengembangan *firmware* yang mengintegrasikan strategi penghematan daya, seperti mode *deep-sleep* ESP32.^13^

**Kontribusi Utama:** Kontribusi signifikan dari studi ini adalah demonstrasi konsumsi daya yang sangat rendah (beberapa mikroampere dalam mode  *deep-sleep* ) dan optimasi masa pakai baterai yang substansial. Ini menunjukkan bagaimana ESP32 dapat dioptimalkan untuk aplikasi yang membutuhkan operasi jangka panjang dengan daya terbatas.^13^

**Hasil Kunci:** Perangkat yang dirancang mampu beroperasi selama berbulan-bulan hingga bertahun-tahun dengan daya baterai, terutama dengan memanfaatkan mode *deep-sleep* ESP32 dan meminimalkan aktivitas radio Wi-Fi saat tidak berkomunikasi.^13^ Hal ini membuktikan bahwa ESP32 adalah pilihan yang sangat baik untuk aplikasi IoT portabel yang membutuhkan efisiensi energi.

**Implikasi untuk Tesis:**

* **Optimasi Efisiensi Energi untuk Portabilitas:** Jurnal ini secara langsung membahas "desain portabel" dari perspektif efisiensi energi, yang merupakan aspek krusial dari tesis. Penggunaan mode *deep-sleep* pada ESP32 ^14^ dan strategi minimisasi komunikasi nirkabel ^14^ adalah kunci untuk memperpanjang masa pakai baterai sistem portabel. Ini sangat penting untuk perangkat yang mungkin dioperasikan di lokasi yang tidak selalu memiliki akses mudah ke sumber daya listrik.
* **Pilihan Komponen Hemat Daya:** Diskusi tentang komponen hemat daya (misalnya, tampilan e-paper yang tidak mengonsumsi daya setelah gambar diatur) dan mikrokontroler (ESP32-S3 yang menawarkan kemampuan *deep-sleep* yang kuat) memberikan panduan berharga untuk pemilihan perangkat keras. Pemilihan komponen yang tepat akan secara langsung mendukung tujuan portabilitas dan efisiensi energi dari sistem tesis.

## IV. Analisis Komparatif dan Sintesis Temuan

Analisis komparatif dari jurnal-jurnal yang ditinjau mengungkapkan beberapa pola dan strategi umum dalam pengembangan sistem monitoring dan kendali berbasis ESP32 dan MQTT, serta menyoroti area untuk pengoptimalan dalam konteks tesis.

### A. Perbandingan Arsitektur Sistem

Jurnal-jurnal yang ditinjau menunjukkan beragam arsitektur sistem yang memanfaatkan ESP32 dan MQTT. Secara umum, ESP32 berfungsi sebagai node sensor utama atau akuisitor data, yang bertanggung jawab untuk mengumpulkan pembacaan dari berbagai sensor dan bertindak sebagai klien MQTT untuk memublikasikan data tersebut.^1^ Beberapa studi juga menempatkan ESP32 sebagai

*edge processor* yang melakukan pra-pemrosesan data untuk mengurangi beban jaringan.^10^

Untuk broker MQTT, terdapat dua pendekatan utama: broker lokal dan broker  *cloud* . Broker lokal sering diimplementasikan pada perangkat seperti Raspberry Pi ^7^, atau bahkan pada ESP32 itu sendiri untuk jaringan privat.^16^ Pendekatan ini mengurangi latensi dan ketergantungan internet. Sebaliknya, broker

*cloud* seperti ThingsBoard ^6^, HiveMQ ^19^, atau EMQX Cloud ^27^ menawarkan skalabilitas dan aksesibilitas global, meskipun dengan potensi latensi yang lebih tinggi dan ketergantungan pada konektivitas internet.

Antarmuka pengguna dan visualisasi data bervariasi, mulai dari platform *open-source* seperti ThingsBoard dan Node-RED yang memungkinkan pembuatan dasbor interaktif ^1^, hingga aplikasi

*smartphone* kustom untuk kendali jarak jauh.^1^ Beberapa sistem juga mengintegrasikan protokol komunikasi tambahan seperti ESP-NOW untuk komunikasi multi-hop ^5^ atau LoRaWAN untuk jangkauan yang lebih jauh ^13^, serta antarmuka industri seperti RS232, RS485, dan CAN-Bus untuk konektivitas yang lebih luas.^18^

Fleksibilitas arsitektur yang ditemukan menunjukkan bahwa ESP32 sangat adaptif untuk berbagai kebutuhan sistem, mulai dari sistem sensor sederhana hingga solusi SCADA yang kompleks. Ini memberikan banyak opsi desain bagi penelitian tesis, memungkinkan penyesuaian arsitektur yang paling sesuai dengan persyaratan spesifik Laboratorium Iklim.

### B. Strategi Optimasi Kinerja dan Efisiensi

Optimasi dalam sistem IoT tidak hanya terbatas pada kecepatan, tetapi juga mencakup efisiensi energi dan keandalan. Jurnal-jurnal yang ditinjau mengidentifikasi beberapa strategi kunci:

1. **Efisiensi Energi:** Untuk desain portabel, efisiensi energi adalah prioritas utama. Mode *deep-sleep* ESP32 terbukti sangat efektif dalam mengurangi konsumsi daya hingga mikroampere, memungkinkan perangkat beroperasi selama berbulan-bulan atau bahkan bertahun-tahun dengan baterai.^13^ Strategi lain meliputi minimisasi komunikasi nirkabel dan pemilihan komponen yang memang dirancang untuk konsumsi daya rendah.^14^
2. **Latensi dan *Throughput* MQTT:** Penggunaan *edge computing* pada ESP32 dapat secara signifikan mengurangi latensi dan penggunaan *bandwidth* dengan melakukan pra-pemrosesan data di perangkat itu sendiri sebelum dikirim ke broker.^10^ Konfigurasi
   *Quality of Service* (QoS) MQTT juga memengaruhi *trade-off* antara latensi dan keandalan pengiriman pesan.^3^ Penempatan broker MQTT yang strategis, baik lokal maupun
   *cloud* , juga berdampak pada kinerja komunikasi.^3^
3. **Keandalan Komunikasi:** Untuk memastikan pengiriman data yang andal, beberapa studi mengintegrasikan protokol seperti ESP-NOW untuk komunikasi multi-hop, yang membantu menjaga cakupan di area yang luas atau terhalang.^5^ Mekanisme
   *buffering* data lokal pada ESP32 juga dapat digunakan untuk menyimpan data saat konektivitas terganggu dan mengirimkannya kembali setelah koneksi pulih.^40^

Pendekatan holistik terhadap optimasi sangat penting. Penelitian tesis perlu mempertimbangkan *trade-off* antara latensi rendah, konsumsi daya minimal, dan keandalan data, terutama untuk sistem portabel yang beroperasi di lingkungan yang mungkin tidak stabil atau memiliki sumber daya terbatas.

### C. Aplikasi dan Konteks Lingkungan

Jurnal-jurnal yang ditinjau mencakup berbagai aplikasi yang relevan dengan ruang simulasi industri dan laboratorium iklim:

1. **Lingkungan Industri:** Beberapa studi berfokus pada aplikasi industri seperti monitoring kebakaran ^5^, kendali robot ^2^, dan otomasi proses.^4^ Ini menunjukkan kemampuan ESP32 dan MQTT untuk beroperasi di lingkungan yang menuntut dan kritis.
2. **Lingkungan Laboratorium/Ruangan:** Banyak penelitian yang relevan berlokasi di lingkungan yang mirip dengan laboratorium atau ruangan tertutup, seperti monitoring suhu kelas ^8^, sistem
   *smarthome* ^1^, dan sistem kendali iklim.^11^ Ini secara langsung mendukung kelayakan penerapan sistem tesis di Laboratorium Iklim.
3. **Desain Portabel:** Konsep portabilitas ditekankan melalui studi tentang sistem akuisisi data portabel ^7^ dan perangkat IoT berdaya rendah yang dirancang untuk masa pakai baterai yang panjang.^13^ Ini memberikan panduan berharga untuk merancang sistem tesis agar mudah dipindahkan dan dioperasikan tanpa ketergantungan konstan pada sumber daya listrik.

Adaptabilitas solusi yang ditinjau menunjukkan bahwa teknologi ESP32 dan MQTT dapat diterapkan secara luas, dari aplikasi *smarthome* hingga industri, menegaskan kesesuaiannya untuk ruang simulasi industri.

### D. Tabel 2: Perbandingan Karakteristik Sistem

Tabel berikut menyajikan perbandingan terstruktur dari karakteristik teknis utama sistem yang dijelaskan dalam jurnal-jurnal yang ditinjau. Tabel ini memungkinkan identifikasi pola, kekuatan, dan kelemahan berbagai pendekatan, serta membantu dalam perancangan arsitektur sistem tesis dengan memilih fitur yang paling relevan dan efektif.

| No. | Jurnal                                                                                                                           | Mikrokontroler            | Protokol Komunikasi Utama | Lingkungan Aplikasi                                    | Fitur Kendali                         | Fitur Monitoring                                   | Aspek Portabilitas/Efisiensi Energi                                            | Metrik Kinerja Utama                                                                 |
| --- | -------------------------------------------------------------------------------------------------------------------------------- | ------------------------- | ------------------------- | ------------------------------------------------------ | ------------------------------------- | -------------------------------------------------- | ------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------ |
| 1   | Developing a Fire Monitoring System Based on MQTT, ESP-NOW, and a REM in Industrial Environments                                 | ESP32-CAM                 | MQTT, ESP-NOW             | Industri (deteksi kebakaran)                           | Tidak spesifik kendali aktif          | Deteksi kebakaran, transmisi data sensor           | Penggunaan ESP-NOW untuk multi-hop (jangkauan luas), optimasi penempatan node. | Tingkat keberhasilan deteksi (100%), latensi (150ms), kehilangan paket (0%).         |
| 2   | Design and implementation of a low-cost, open source IoT-based SCADA system using ESP32 with OLED, ThingsBoard and MQTT protocol | ESP32                     | MQTT                      | Sistem Tenaga Hibrida                                  | Kendali terkoordinasi (SCADA)         | Arus, tegangan, daya, data historis                | Solusi berbiaya rendah,*open-source* .                                       | Akuisisi data real-time, monitoring jarak jauh.                                      |
| 3   | IoT-Based Classroom Tedtsmperature Monitoring and Missing Data Prediction Using Raspberry Pi and ESP32                           | ESP32, Raspberry Pi       | WiFi (lokal)              | Kelas/Laboratorium Elektronik                          | Tidak spesifik kendali aktif          | Suhu, prediksi data hilang                         | Hemat biaya, mudah diintegrasikan.                                             | Akurasi monitoring suhu.                                                             |
| 4   | MQTT Protocol-Based ESP-32 Smarthome with Multi-sensor Recognition                                                               | ESP32                     | MQTT                      | *Smarthome*                                          | Kendali perangkat elektronik (On/Off) | Suhu, kelembaban, api, cahaya, deteksi putus kabel | Kendali via*smartphone* .                                                    | Akurasi sensor (98.12%), latensi MQTT (0.725s/0.67s).                                |
| 5   | Real-Time Data Acquisition with ESP32 for IoT Applications Using Open-Source MQTT Brokers                                        | ESP32                     | MQTT                      | Berbagai domain IoT (smart home, industri, lingkungan) | Kendali proses industri               | Akuisisi data sensor real-time                     | Fleksibilitas, skalabilitas.                                                   | Stabilitas tinggi, waktu respons cepat.                                              |
| 6   | Design and Implementation of ESP32-Based Edge Computing for Object Detection                                                     | ESP32-CAM                 | MQTT                      | Aplikasi*edge computing*(deteksi objek)              | Tidak spesifik kendali aktif          | Deteksi objek                                      | Pengurangan*bandwidth*& latensi ( *edge processing* ).                     | Waktu klasifikasi, waktu transmisi MQTT, penggunaan*bandwidth* .                   |
| 7   | Optimizing Data Transfer Speed and the Performance Evaluation of MQTT in IoT                                                     | Tidak spesifik (umum IoT) | MQTT                      | Monitoring lingkungan (atmosfer)                       | Tidak spesifik kendali aktif          | Suhu, kelembaban, intensitas cahaya                | Ringan, rendah daya, cocok untuk perangkat terbatas.                           | Latensi (rata-rata <50ms),*throughput* , QoS.                                      |
| 8   | On/Off Temperature Monitoring and Control via the Internet of Things Using iTCLab Kit                                            | ESP32                     | MQTT                      | Laboratorium (kendali suhu)                            | Kendali suhu On/Off                   | Monitoring suhu                                    | Kit pembelajaran, kendali via*smartphone* .                                  | Keberhasilan kendali, monitoring real-time.                                          |
| 9   | Temperature and Humidity Control System with Air Conditioner Based on Fuzzy Logic and Internet of Things                         | ESP32                     | IoT (WiFi)                | Ruangan (kendali iklim)                                | Kendali AC (Fuzzy Logic)              | Suhu, kelembaban                                   | -                                                                              | Efektivitas kendali suhu (-1.67°C perubahan), kendali kelembaban (kurang berhasil). |
| 10  | An Energy-Efficient E-Paper Sticky Note for Internet of Things (IoT) Applications                                                | ESP32-S3                  | MQTT, BLE, LoRa           | Smart home, kantor, fasilitas industri                 | Tidak spesifik kendali aktif          | Menampilkan pembacaan sensor, notifikasi           | Konsumsi daya sangat rendah (*deep-sleep* ), masa pakai baterai panjang.     | Konsumsi daya (mikroampere dalam*deep-sleep* ).                                    |

## V. Kesimpulan dan Rekomendasi untuk Pengembangan Tesis

### A. Sintesis Temuan Kunci

Tinjauan literatur yang komprehensif ini menegaskan bahwa kombinasi ESP32 dan protokol MQTT merupakan fondasi yang sangat kuat dan efisien untuk pengembangan sistem monitoring dan kendali IoT. ESP32 menawarkan kapabilitas pemrosesan dan konektivitas nirkabel yang memadai untuk berbagai aplikasi, sementara MQTT menyediakan mekanisme komunikasi Pub-Sub yang ringan, andal, dan berlatensi rendah, ideal untuk perangkat dengan sumber daya terbatas dan jaringan yang tidak stabil.

Pentingnya desain portabel dan efisiensi energi untuk aplikasi di lapangan atau lingkungan laboratorium yang dinamis telah ditekankan secara konsisten di berbagai studi. Kemampuan ESP32 untuk memasuki mode *deep-sleep* dengan konsumsi daya sangat rendah menjadikannya pilihan utama untuk perangkat bertenaga baterai yang membutuhkan masa pakai yang panjang. Selain itu, adopsi *edge computing* dan penempatan broker yang strategis, baik lokal maupun  *cloud* , terbukti esensial untuk optimasi kinerja, terutama dalam mengurangi latensi dan penggunaan  *bandwidth* .

Fleksibilitas dalam integrasi berbagai jenis sensor dan aktuator, serta pilihan antarmuka pengguna yang beragam (mulai dari dasbor *web* hingga aplikasi  *smartphone* ), menunjukkan adaptabilitas solusi berbasis ESP32 dan MQTT untuk memenuhi kebutuhan spesifik Laboratorium Iklim. Studi-studi yang ditinjau mencakup aplikasi dari *smarthome* hingga lingkungan industri yang menuntut, yang semakin memperkuat relevansi teknologi ini untuk ruang simulasi industri.

### B. Rekomendasi untuk Tesis

Berdasarkan sintesis temuan dari literatur yang ditinjau, beberapa rekomendasi dapat diajukan untuk pengembangan tesis mengenai Pengoptimalan Sistem Monitoring dan Kendali Ruang Simulasi Industri Berbasis ESP32 dengan Metode Pub-Sub MQTT dan Desain Portabel di Laboratorium Iklim Universitas Teknologi Bandung:

1. **Fokus pada Optimasi Energi Secara Eksplisit:** Mengingat penekanan pada "desain portabel", tesis harus secara eksplisit mengintegrasikan dan mengukur strategi optimasi energi. Hal ini mencakup implementasi mode *deep-sleep* pada ESP32, optimasi interval transmisi data, dan minimisasi aktivitas radio Wi-Fi saat tidak diperlukan. Pengukuran konsumsi daya dalam berbagai mode operasional akan memberikan bukti kuantitatif dari aspek portabilitas.
2. **Uji Kinerja Komunikasi MQTT yang Menyeluruh:** Penting untuk melakukan pengujian latensi dan keandalan komunikasi MQTT secara menyeluruh dalam lingkungan Laboratorium Iklim yang sebenarnya. Pertimbangkan untuk menguji berbagai tingkat *Quality of Service* (QoS) MQTT untuk memahami *trade-off* antara kecepatan dan jaminan pengiriman pesan. Analisis potensi interferensi nirkabel di lingkungan laboratorium juga akan sangat berharga.
3. **Pertimbangkan Arsitektur Hibrida:** Jelajahi kemungkinan arsitektur hibrida, di mana ESP32 berfungsi sebagai *edge device* yang melakukan pra-pemrosesan data (misalnya, filtering, agregasi, atau normalisasi) sebelum mengirimkannya. Broker MQTT dapat ditempatkan secara lokal (misalnya, pada Raspberry Pi atau server lokal) untuk latensi yang lebih rendah dan privasi data, atau di *cloud* untuk skalabilitas dan aksesibilitas global. Pendekatan ini dapat menyeimbangkan kinerja, skalabilitas, dan kebutuhan sumber daya.
4. **Validasi Akurasi Sensor:** Pastikan kalibrasi dan validasi akurasi sensor yang digunakan untuk monitoring lingkungan simulasi (misalnya, suhu, kelembaban, tekanan, kualitas udara). Data yang presisi adalah fundamental untuk sistem kendali yang efektif dan untuk memastikan validitas hasil simulasi di laboratorium.
5. **Desain Antarmuka Pengguna Intuitif dan Fungsional:** Manfaatkan platform *open-source* seperti ThingsBoard atau Node-RED untuk mengembangkan antarmuka pengguna yang intuitif dan kaya fitur. Antarmuka ini harus memungkinkan visualisasi data real-time, pengaturan parameter kendali, dan penerimaan notifikasi, yang dapat diakses melalui *smartphone* atau *web* untuk mendukung operasional sistem yang portabel.
6. **Aspek Keamanan Komunikasi:** Meskipun tidak banyak dibahas dalam sumber-sumber yang ditinjau, pertimbangkan aspek keamanan komunikasi MQTT. Implementasi TLS/SSL untuk enkripsi data dan otentikasi klien/broker akan sangat penting untuk melindungi data sensitif dan mencegah akses tidak sah di lingkungan laboratorium.

Dengan mengintegrasikan rekomendasi-rekomendasi ini, penelitian tesis diharapkan dapat menghasilkan sistem monitoring dan kendali ruang simulasi industri yang tidak hanya berfungsi secara efektif tetapi juga dioptimalkan untuk portabilitas, efisiensi, dan keandalan, memberikan kontribusi signifikan bagi Laboratorium Iklim Universitas Teknologi Bandung.
