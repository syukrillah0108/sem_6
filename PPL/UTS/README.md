1. Metode Graph Based
2. Metode Equivalence Partitioning
   Membagi input ke dalam kelompok yang mewakili skenario pengujian serupa untuk mengurangi jumlah pengujian.

   Struktur Data yang akan di uji

```SQL
    CREATE TABLE `desa` (
        `id_desa` varchar(20) DEFAULT NULL,
        `id_prov` varchar(20) DEFAULT NULL,
        `id_kab` varchar(20) DEFAULT NULL,
        `id_kec` varchar(20) DEFAULT NULL,
        `nm_desa` varchar(20) DEFAULT NULL,
        `st_desa` varchar(255) DEFAULT NULL
    )
```

    Format Input API`{"id_kec": "{id kecamatan}","fields": [{daftar kolom yang mau diambil}]}`

| ID | Input                                                                     | Equivalence Class | Expected Result            | Actual Result | Status | Resume                                                                                        |
| -- | ------------------------------------------------------------------------- | ----------------- | -------------------------- | ------------- | ------ | --------------------------------------------------------------------------------------------- |
| 1  | {<br />"id_kec": "32.73.04",<br />"fields": ["id_desa", "nm_desa"]<br />} | Valid             | mengembalikan nilai        |               |        | id_kec dan daftar fields**tersedia** di database                                        |
| 2  | {<br />"id_kec": "32.73.98",<br />"fields": ["id_desa", "nm_desa"]<br />} | Invalid           | tidak mengembalikan nilai |               |        | id_kec tidak**tersedia** di database dan daftar fields **tersedia** di database  |
| 3  | {<br />"id_kec": "32.73.04",<br />"fields": ["nm_desa"]<br />}            | Valid             | mengembalikan nilai        |               |        | id_kec dan daftar fields**tersedia** di database                                        |
| 4  | {<br />"id_kec": "32.73.04",<br />"fields": ["alamat"]<br />}             | Invalid           | tidak mengembalikan nilai |               |        | id_kec**tersedia** di database dan daftar fields **tidak tersedia** di database |
| 5  | {<br />"fields": ["id_desa", "nm_desa"]<br />}                            | Invalid           | tidak mengembalikan nilai  |               |        | tidak menyertakan kunci id_kec                                                                |
| 6  | {<br />\"id_kec": "32.73.04"<br />}                                       | Invalid           | tidak mengembalikan nilai |               |        | tidak menyertakan kunci fields                                                                |

3. Boundary Values Analysis
4. Fuzzing
5. Cause-Effect
