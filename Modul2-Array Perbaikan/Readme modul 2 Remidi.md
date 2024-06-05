## Array remidi
## Coding by Luthfi Adi Harianto
## NIM 2311102172
## Kelas : IF 11 E

## MODUL 2
## Array Remidi

## TUJUAN PRAKTIKUM
a. Mahasiswa dapat memahami konsep Array.
b. Mahasiswa dapat mengetahui jenis dimensi Array dan cara penulisannya.
c. Mahasiswa dapat mengimplementasikan Array pada kode program yang dibuat

## Dasar Teori
Array adalah suatu struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Elemen-elemen array tersusun secara sekuensial dalam memori komputer. Semua elemem array bertipe sama. Array cocok untuk organisasi kumpulan data homogen yang ukuran atau jumlah elemen maksimumnya telah diketahui dari awal. Homogen adalah bahwa setiap elemen dari sebuah array tertentu haruslah mempunyai tipe data yang sama.
Array dibagi menjadi :
  
        1.  Array Satu Dimensi 

Array satu dimensi tidak lain adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda.  Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutan
Deklarasi : Type_Data Nama_Variabel [index] 
Misalnya : int A[5]; 

        2.  Array Dua Dimensi 

Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. Pendeklarasian array dua dimensi hampir sama dengan pendeklarasian array satu dimensi, kecuali bahwa array dua dimensi terdapat dua jumlah elemen array yang terdapat di dalam kurung siku dan keduanya boleh tidak sama.
Deklarasi : Type_Data Nama_Variabel [Index1] [index2]; 
Misal : int A[3][2];

        3.   Array Tiga Dimensi 
Array tiga dimensi digunakan untuk mengelola data dalam bentuk 3 dimensi atau tiga sisi. 
Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3]; 
Misal : int A [3][4][2];

## Guided 
guided 1
```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
// Deklarasi array
int arr[2][3][3];
// Input elemen
for (int x = 0; x < 2; x++)
{
for (int y = 0; y < 3; y++)
{
for (int z = 0; z < 3; z++)
{
cout << "Input Array[" << x << "][" << y << "][" << z <<
"] = ";
cin >> arr[x][y][z];
}
}
cout << endl;
}
// Output Array
for (int x = 0; x < 2; x++)
{
for (int y = 0; y < 3; y++)
{
for (int z = 0; z < 3; z++)
{
cout << "Data Array[" << x << "][" << y << "][" << z <<
"] = " << arr[x][y][z] << endl;
}
}
}
cout << endl;
// Tampilan array
for (int x = 0; x < 2; x++)
{
for (int y = 0; y < 3; y++)
{
for (int z = 0; z < 3; z++)
{
cout << arr[x][y][z] << ends;
}
cout << endl;
}
cout << endl;
}
}
```
![alt text](<Screenshot 2024-06-06 020845.png>) </br>
![alt text](<Screenshot 2024-06-06 020816.png>)</br>
## Guided
guided 2
```C++
#include <iostream>
using namespace std;
int main()
{
int maks, a, i = 1, lokasi;
cout << "Masukkan panjang array: ";
cin >> a;
int array[a];
cout << "Masukkan " << a << " angka\n";
for (i = 0; i < a; i++)
{
cout << "Array ke-" << (i) << ": ";
cin >> array[i];
}
maks = array[0];
for (i = 0; i < a; i++)
{
if (array[i] > maks)
{
maks = array[i];
lokasi = i;
}
}
cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
return 0;
};
```
![alt text](<Screenshot 2024-06-06 021042.png>)</br>
## Unguided 1
```C++
#include <iostream>

using namespace std;

int main() {
  // Deklarasi variabel
  int data[10];
  int i, n, genap, ganjil;

  // Meminta input dari user
  cout << "Masukkan jumlah data: ";
  cin >> n;

  cout << "Masukkan data: ";
  for (i = 0; i < n; i++) {
    cin >> data[i];
  }

  // Menampilkan data array
  cout << "\nData Array: ";
  for (i = 0; i < n; i++) {
    cout << data[i] << " ";
  }

  // Menghitung jumlah nomor genap dan ganjil
  genap = 0;
  ganjil = 0;
  for (i = 0; i < n; i++) {
    if (data[i] % 2 == 0) {
      genap++;
    } else {
      ganjil++;
    }
  }

  // Menampilkan nomor genap dan ganjil
  cout << "\nNomor Genap:\n";
  for (i = 0; i < n; i++) {
    if (data[i] % 2 == 0) {
      cout << data[i] << " ";
    }
  }

  cout << "\nNomor Ganjil:\n";
  for (i = 0; i < n; i++) {
    if (data[i] % 2 != 0) {
      cout << data[i] << " ";
    }
  }

  return 0;
}
```
![alt text](<Screenshot 2024-06-06 021307.png>)</br>
program tersebut menampilkan data array dari 1,2,3,4,5,6,7,8,9,10 kemudian diurutkan user melalui nomor genap 2,4,6,8 dan nomor ganjil 1,3,5,7,9

## Unguided 2
```C++
// Program input Array 3 dimensi

#include <iostream>
using namespace std;

int main() {
  int x, y, z;

  // Input jumlah elemen di setiap dimensi
  cout << "Masukkan jumlah elemen di dimensi X: ";
  cin >> x;
  cout << "Masukkan jumlah elemen di dimensi Y: ";
  cin >> y;
  cout << "Masukkan jumlah elemen di dimensi Z: ";
  cin >> z;

  // Deklarasi array tiga dimensi
  int array[x][y][z];

  // Input nilai elemen array
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < z; k++) {
        cout << "Masukkan nilai array[" << i << "][" << j << "][" << k << "]: ";
        cin >> array[i][j][k];
      }
    }
  }

  // Menampilkan elemen array
  cout << endl << "Elemen array:" << endl;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < z; k++) {
        cout << array[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
```
![alt text](<Screenshot 2024-06-06 021640.png>)</br>
![alt text](<Screenshot 2024-06-06 021654.png>)</br>
![alt text](<Screenshot 2024-06-06 021714.png>)</br>
program diatas adalah array tiga dimensi dimana jumlah dan ukuran array diinputkan terserah oleh user

## Unguided 3
```C++
#include <iostream>

using namespace std;

int main() {
  int pilihan;
  float nilai[100];
  int n;

  // Meminta input jumlah elemen array
  cout << "Masukkan jumlah elemen array: ";
  cin >> n;

  // Meminta input nilai elemen array
  for (int i = 0; i < n; i++) {
    cout << "Masukkan nilai elemen ke-" << i + 1 << ": ";
    cin >> nilai[i];
  }

  do {
    cout << "\nMenu:" << endl;
    cout << "1. Tampilkan Nilai Maksimum" << endl;
    cout << "2. Tampilkan Nilai Minimum" << endl;
    cout << "3. Tampilkan Nilai Rata-rata" << endl;
    cout << "4. Keluar" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1: {
        float maks = nilai[0];
        for (int i = 1; i < n; i++) {
          if (nilai[i] > maks) {
            maks = nilai[i];
          }
        }
        cout << "Nilai Maksimum: " << maks << endl;
        break;
      }
      case 2: {
        float min = nilai[0];
        for (int i = 1; i < n; i++) {
          if (nilai[i] < min) {
            min = nilai[i];
          }
        }
        cout << "Nilai Minimum: " << min << endl;
        break;
      }
      case 3: {
        float total = 0;
        for (int i = 0; i < n; i++) {
          total += nilai[i];
        }
        float rataRata = total / n;
        cout << "Nilai Rata-rata: " << rataRata << endl;
        break;
      }
      case 4: {
        cout << "Keluar dari program" << endl;
        break;
      }
      default: {
        cout << "Pilihan tidak valid!" << endl;
      }
    }
  } while (pilihan != 4);

  return 0;
}
```
![alt text](<Screenshot 2024-06-06 022118.png>)</br>
![alt text](<Screenshot 2024-06-06 022004.png>)</br>
![alt text](<Screenshot 2024-06-06 022021.png>) </br>
![alt text](<Screenshot 2024-06-06 022038.png>) </br>
![alt text](<Screenshot 2024-06-06 022054.png>)</br>
program diatas merupakan program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user

## Kesimpulan
Array mempunyai Keuntungan dan Kelemahan sebagai struktur data yaitu :

Keuntungan:
Akses elemen cepat menggunakan indeks.
Struktur data sederhana dan efisien dalam penggunaan memori.

Kelemahan:
Ukuran tetap membuatnya kurang fleksibel.
Tidak ada pengecekan batas saat mengakses elemen, yang dapat menyebabkan kesalahan jika indeks di luar rentang.

## Daftar Pustaka
[1]Pratama, Muhammad Aldi. "STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++." (2020).
[2]Efendi, Yasin. "Buku Ajar Pendidikan Algoritma dan Struktur Data." (2022).
[3]Putra, Muhammad Taufik Dwi, Munawir Munawir, and Ana Rahma Yuniarti. "BELAJAR PEMROGRAMAN LANJUT DENGAN C++." (2023).
