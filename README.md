# Rancang-Bangun-Keamanan-Ganda-Pada-Brankas-Berbasis-Arduino 
Rancang Bangun Keamanan Ganda Pada Brankas Berbasis  Arduino  

Alat ini bekerja dengan cara memanfaatkan dua buah pengaman, yakni yang pertama dengan menempelkan kartu RFID lalu data ditransfer ke Arduino, jika kartu tidak terdeteksi maka mengulang dari awal, namun jika scan kartu berhasil maka akan lanjut ke tahap selanjutnya yaitu memasukkan pin melalui keypad yang telah tersedia, jika berhasil maka pintu terbuka dan jika salah memasukkan password buzzer akan berbunyi dan mengulang untuk memasukkan password. Jika pasword sudah benar maka selenoid akan bekerja untuk membuka pintu brankas. Kemudian pintu akan terbuka dan LED akan hidup.  


​Komponen yang digunakan pada proyek:
1. Papan tombol 16x4
2. Pembaca RFID 
3. RFID Card
5. Kunci Pintu Solenoid
6. Relai
7. LDC I2C
8. Bel
9.  Arduino Uno

Diagram  Block alat 
![image](https://user-images.githubusercontent.com/122041231/211178705-f608cad3-9773-4bdb-81b1-e1ed08be53e4.png)

Diagram Pengawatan
![image](https://user-images.githubusercontent.com/122041231/211178719-2616906a-ecf7-4135-8176-f2f7a39d19cd.png)

Diagram alir 

![image](https://user-images.githubusercontent.com/122041231/211179009-67bb06a0-5be3-45b6-aebb-ffaaeb324500.png)


