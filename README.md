
# Proyek IoT ESP32

## Deskripsi
Repositori ini berisi kode program, dataset pengujian, dan skrip analisis untuk proyek Internet of Things (IoT) berbasis ESP32.

Repositori disusun untuk mendokumentasikan proses pengujian pada Bagian A dan Bagian B serta mendukung reproduksi hasil analisis pada laporan.

## Struktur Repositori
```text
Proyek-IoT-ESP32/
├── README.md
├── code/
│   ├── bagian_A/
│   └── bagian_B/
├── dataset/
├── analysis/
│   └── requirements.txt
└── results/
    ├── tabel/
    └── grafik/
```

## Perangkat dan Perangkat Lunak
- Mikrokontroler ESP32
- WOKWI
- Mikrokontroler ESP8266
- Arduino IDE
- Koneksi jaringan Wi-Fi
- Wireshark

## Dependensi
Daftar library dan versi yang digunakan akan dicantumkan setelah disesuaikan dengan program pengujian.

## Konfigurasi Keamanan
Kredensial Wi-Fi, API Key, dan token tidak disimpan secara langsung di repositori. Konfigurasi pribadi harus diatur secara lokal sebelum program dijalankan.

## Langkah Menjalankan
1. Unduh atau clone repositori.
2. Buka kode program sesuai bagian pengujian.
3. Sesuaikan konfigurasi perangkat secara lokal.
4. Hubungkan ESP32 ke komputer.
5. Unggah program menggunakan Arduino IDE.
6. Jalankan pengujian dan simpan data yang dihasilkan.

## Reproduksi Analisis
1. Siapkan dataset hasil pengujian pada folder `dataset/`.
2. Siapkan dependensi analisis.
3. Jalankan skrip pada folder `analysis/`.
4. Periksa tabel dan grafik yang dihasilkan pada folder `results/`.

## Verifikasi
Hasil reproduksi akan diverifikasi dengan membandingkan hasil pengolahan ulang terhadap hasil analisis pada laporan.
