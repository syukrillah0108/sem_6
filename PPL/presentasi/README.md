# **Keyword**

`curl -X POST http://127.0.0.1:1880/api/sensor -H "Content-Type: application/json" -d @data.json `

# **a. Pengujian Black Box**

* **Equivalence Partitioning** : Membagi input ke dalam kelompok yang mewakili skenario pengujian serupa untuk mengurangi jumlah pengujian.
  ```json
  {
      "id_kec": "32.73.04",
      "fields": ["id_desa", "nm_desa"]
  }
  ```

| ID | Input                                                   | Equivalence Class | Expected Result | Actual Result | Status |
| -- | ------------------------------------------------------- | ----------------- | --------------- | ------------- | ------ |
| 1  | {"id_kec": "32.73.04","fields": ["id_desa", "nm_desa"]} | Valid             |                 |               |        |
| 2  | {"id_kec": "32.73.98","fields": ["id_desa", "nm_desa"]} | Invalid           |                 |               |        |

> **Contoh:** Jika API menerima usia 18–60, maka:
>
> * Valid class: angka antara 18–60
> * Invalid class: angka di bawah 18 atau di atas 60

* **Boundary Value Analysis** : Menguji batas nilai minimum dan maksimum untuk memastikan sistem bekerja dengan baik dalam kondisi ekstrem.

| ID | Input                                                                                                  | (Min/Max/Above/Below) | Expected Result | Actual Result | Status |
| -- | ------------------------------------------------------------------------------------------------------ | --------------------- | --------------- | ------------- | ------ |
| 1  | {"id_kec": ,"fields": ["nm_desa"]}                                                                     | **Min**         |                 |               |        |
| 2  | {"id_kec": "32.73.04","fields": ["id_desa","id_prov","id_kab","id_kec","nm_desa","st_desa"]}           | **Max**         |                 |               |        |
| 3  | {"id_kec": "32.73.04","fields": []}                                                                    | **Below**       |                 |               |        |
| 4  | {"id_kec": "32.73.04","fields": ["id_desa","id_prov","id_kab","id_kec","nm_desa","st_desa","nm_desa"]} | **Above**       |                 |               |        |
| 5  | {"id_kec": "32.73.04","fields": ["id_desa","id_prov","id_kab","id_kec","nm_desa","st_desa","test"]}    | **Above**       |                 |               |        |

> **Contoh:** Jika API menerima jumlah karakter 5–10

* **AboveState Transition Testing** : Menguji bagaimana sistem berpindah dari satu keadaan ke keadaan lain berdasarkan input yang diberikan.

| ID | Input                        | Expected Next State | Expected Output                                 | Actual Output | Status |
| -- | ---------------------------- | ------------------- | ----------------------------------------------- | ------------- | ------ |
| 1  | Invalid username or password | -                   | Invalid username or password. Please try again. |               | OK     |
| 2  | Valid username and password | Home Page           | Login successful! Redirecting...                |               | OK     |

* **Decision Table Testing** : Menggunakan tabel keputusan untuk menguji berbagai kombinasi input dan output.

| ID | id_kec     | fields    | Logical | Expected Message | Actual Message |
| -- | ---------- | --------- | ------- | ---------------- | -------------- |
| 1  | "32.73.04" | "nm_desa" | AND     |                  |                |
| 2  | "32.73.04" | "temp"    | OR      |                  |                |
| 3  | "32.73.99" | "temp"    | NOT     |                  |                |

---

# **b. Pengujian untuk Sistem Waktu Nyata (Real-Time System Testing)**

* **Performance Testing** : Mengukur waktu respons sistem di bawah berbagai kondisi beban.

| ID | Skenario      | Request | Latensi | Waktu Respon | Status |
| -- | ------------- | ------- | ------- | ------------ | ------ |
| 1  | Rendah        | 10      |         |              |        |
| 2  | Normal        | 50      |         |              |        |
| 3  | Sedang        | 100     |         |              |        |
| 4  | Tinggi        | 500     |         |              |        |
| 5  | Sangat Tinggi | 1000    |         |              |        |

* **Stress Testing** : Mendorong sistem ke batas maksimumnya untuk melihat bagaimana sistem menangani beban tinggi.

| ID | Skenario        | Request | Latensi | Sistem Crash? | Status |
| -- | --------------- | ------- | ------- | ------------- | ------ |
| 1  | Extreme         | 10000   |         |               |        |
| 2  | Sangant Extreme | 50000   |         |               |        |

* **Reliability Testing** : Menguji keandalan sistem selama periode yang lama.

| ID | Durasi | Request | Gangguan Waktu | Error Tercatat | Status |
| -- | ------ | ------- | -------------- | -------------- | ------ |
| 1  | 12 jam | 10000   |                |                |        |
| 2  | 24 jam | 50000   |                |                |        |

* **Concurrency Testing** : Menguji bagaimana sistem menangani banyak proses atau thread secara bersamaan.

| ID | Jumlah thread/user | Aksi yang diuji | Expected Result | Actual Result | Status |
| -- | ------------------ | --------------- | --------------- | ------------- | ------ |
| 1  | Extreme            | 10000           |                 |               |        |
| 2  | Sangant Extreme    | 50000           |                 |               |        |

---

# **c. Peralatan Uji Otomatis (Automated Testing Tools)**

* **Functional Testing Tools** : Menguji apakah perangkat lunak bekerja sesuai spesifikasi (contoh: Selenium, Cypress).
* **Performance Testing Tools** : Menguji kecepatan, skalabilitas, dan keandalan aplikasi (contoh: JMeter, Gatling).
* **Unit Testing Tools** : Menguji bagian kecil dari kode secara independen (contoh: JUnit untuk Java, PyTest untuk Python).
* **Security Testing Tools** : Mengidentifikasi celah keamanan dalam sistem (contoh: OWASP ZAP, Burp Suite).

---
