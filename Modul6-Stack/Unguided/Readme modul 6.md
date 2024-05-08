## Stack
## Coding by Luthfi Adi Harianto
## NIM 2311102172
## Kelas : IF 11 E

## MODUL 6
## Stack

A. TUJUAN PRAKTIKUM
a. Mampu memahami konsep stack pada struktur data dan algoritma
b. Mampu mengimplementasikan operasi-operasi pada stack
c. Mampu memecahkan permasalahan dengan solusi stack
B. DASAR TEORI
Stack adalah struktur data sederhana yang digunakan untuk menyimpan data (mirip
dengan Linked Lists). Dalam tumpukan, urutan kedatangan data penting. Sebuah
tumpukan piring di kafetaria adalah contoh bagus dari tumpukan. Piring ditambahkan
ke tumpukan saat mereka dibersihkan dan ditempatkan di bagian atas. Ketika sebuah
piring dibutuhkan, diambil dari bagian atas tumpukan. Piring pertama yang
ditempatkan di tumpukan adalah yang terakhir digunakan.
Definisi: Sebuah tumpukan adalah daftar terurut di mana penyisipan dan penghapusan
dilakukan di satu ujung, disebut atas. Elemen terakhir yang dimasukkan adalah yang
pertama dihapus. Oleh karena itu, disebut daftar Last in First out (LIFO).
Operasi pada stack melibatkan beberapa fungsi dasar yang dapat dilakukan pada
struktur data ini. Berikut adalah beberapa operasi umum pada stack:
a. Push (Masukkan): Menambahkan elemen ke dalam tumpukan pada posisi paling
atas atau ujung.
b. Pop (Keluarkan): Menghapus elemen dari posisi paling atas atau ujung tumpukan.
c. Top (Atas): Mendapatkan nilai atau melihat elemen teratas pada tumpukan tanpa
menghapusnya.
d. IsEmpty (Kosong): Memeriksa apakah tumpukan kosong atau tidak.
e. IsFull (Penuh): Memeriksa apakah tumpukan penuh atau tidak (terutama pada
implementasi tumpukan dengan kapasitas terbatas).
f. Size (Ukuran): Mengembalikan jumlah elemen yang ada dalam tumpukan.
g. Peek (Lihat): Melihat nilai atau elemen pada posisi tertentu dalam tumpukan
tanpa menghapusnya.
h. Clear (Hapus Semua): Mengosongkan atau menghapus semua elemen dari
tumpukan.
i. Search (Cari): Mencari keberadaan elemen tertentu dalam tumpukan.

## Guided
```C++
#include <iostream>
using namespace std;
string arrayBuku[5];
int maksimal = 5, top = 0;
bool isFull() {
return (top == maksimal);
}
bool isEmpty() {
return (top == 0);
}
void pushArrayBuku(string data) {
if (isFull()) {
cout << "Data telah penuh" << endl;
} else {
arrayBuku[top] = data;
top++;
}
}
void popArrayBuku() {
if (isEmpty()) {
cout << "Tidak ada data yang dihapus" << endl;
} else {
arrayBuku[top - 1] = "";
top--;
}
}
void peekArrayBuku(int posisi) {
if (isEmpty()) {
cout << "Tidak ada data yang bisa dilihat" << endl;
} else {
int index = top;
for (int i = 1; i <= posisi; i++) {
index--;
}
cout << "Posisi ke " << posisi << " adalah " <<
arrayBuku[index] << endl;
}
}
int countStack() {
return top;
}
void changeArrayBuku(int posisi, string data) {
if (posisi > top) {
cout << "Posisi melebihi data yang ada" << endl;
} else {
int index = top;
for (int i = 1; i <= posisi; i++) {
index--;
}
arrayBuku[index] = data;
}
}
void destroyArraybuku() {
for (int i = top; i >= 0; i--) {
arrayBuku[i] = "";
}
top = 0;
}
void cetakArrayBuku() {
if (isEmpty()) {
cout << "Tidak ada data yang dicetak" << endl;
} else {
for (int i = top - 1; i >= 0; i--) {
cout << arrayBuku[i] << endl;
}
}
}
int main() {
pushArrayBuku("Kalkulus");
pushArrayBuku("Struktur Data");
pushArrayBuku("Matematika Diskrit");
pushArrayBuku("Dasar Multimedia");
pushArrayBuku("Inggris");
cetakArrayBuku();
cout << "\n";
cout << "Apakah data stack penuh? " << isFull() << endl;
cout << "Apakah data stack kosong? " << isEmpty() << endl;
peekArrayBuku(2);
popArrayBuku();
cout << "Banyaknya data = " << countStack() << endl;
changeArrayBuku(2, "Bahasa Jerman");
cetakArrayBuku();
cout << "\n";
destroyArraybuku();
cout << "Jumlah data setelah dihapus: " << top << endl;
cetakArrayBuku();
return 0;
}
```
![alt text](<Screenshot 2024-05-06 213203.png>)</br>
## Unguided 
Unguided 1
```C++
#include <iostream>
#include <stack>

using namespace std;

bool isPalindrome(string kalimat) {
  // Buat stack untuk menyimpan karakter kalimat
  stack<char> s;

  // Masukkan karakter kalimat ke dalam stack
  for (char c : kalimat) {
    s.push(c);
  }

  // Bandingkan karakter dari depan dan belakang kalimat
  string terbalik;
  while (!s.empty()) {
    terbalik += s.top();
    s.pop();
  }

  return kalimat == terbalik;
}

int main() {
  // Deklarasikan variabel untuk menyimpan kalimat
  string kalimat;

  // Minta pengguna untuk memasukkan kalimat
  cout << "Masukkan kalimat: ";
  cin >> kalimat;

  // Ubah semua huruf menjadi huruf kecil
  for (int i = 0; i < kalimat.size(); i++) {
    kalimat[i] = tolower(kalimat[i]);
  }

  // Periksa apakah kalimat palindrom
  if (isPalindrome(kalimat)) {
    cout << kalimat << " adalah kalimat palindrom" << endl;
  } else {
    cout << kalimat << " bukan kalimat palindrom" << endl;
  }

  return 0;
}
```
![alt text](<Screenshot 2024-05-06 212644.png>)</br>
![alt text](<Screenshot 2024-05-06 212736.png>)</br>
## Cara Kerja Program Unguided 1
Pertama kita masukkan stack pada include untuk memasukkan header file yang kita buat ke dalam sebuah program yang sedang dikembangkan agar program kita berjalan
Kemudian membuat stack menyimpan karakter kalimat yang kita masukkan dengan menggunakan stack <char> s
Jangan lupa kita pastikan program yang sedang kita kembangkan yaitu kosong dengan mengecek menggunakan is.empty
Program kemudian membandingkan karakter dari stack satu per satu dan menambahkan nya ke string baru yaitu terbalik. Setiap karakter dalam kalimat yang diinputkan kita looping(ulang) menggunakan for.
Kemudian terakhir dengan menambahkan fungsi tolower yaitu dengan menggunakan tolower kita dapat mengubah semua huruf dalam kalimat menjadi huruf kecil, dikarenakan palindrom tidak memperhitungkan perbedaan huruf besar maupun kecil
Jika sudah kita masukkan kalimat untuk mengecek apakah kalimat tersebut palindrom atau bukan
Jika kalimat tersebut palindrom output yang dihasilkan "kalimat adalah kalimat palindrom"
Jika kalimat tersebut tidak palindrom maka hasil output yang keluar adalah
"Kalimat bukan kalimat palindrom"

## Unguided 2
```C++
#include <iostream>
#include <stack>

using namespace std;

int main() {
  // Deklarasi variabel
  string kalimat;
  stack<char> tumpukan;

  // Meminta input kalimat
  cout << "Masukkan kalimat (minimal 3 kata): ";
  getline(cin, kalimat);

  // Memeriksa panjang kalimat
  if (kalimat.length() < 3) {
    cout << "Kalimat minimal harus 3 kata!" << endl;
    return 1;
  }

  // Memasukkan karakter kalimat ke stack
  for (char c : kalimat) {
    tumpukan.push(c);
  }

  // Mengeluarkan karakter dari stack dan membentuk kalimat terbalik
  kalimat = "";
  while (!tumpukan.empty()) {
    kalimat += tumpukan.top();
    tumpukan.pop();
  }

  // Menampilkan kalimat terbalik
  cout << "Kalimat terbalik: " << kalimat << endl;

  return 0;
}
```
![alt text](<Screenshot 2024-05-06 212815.png>)</br>
![alt text](<Screenshot 2024-05-06 212845.png>)</br>
## Cara Kerja Program Unguided 2
Program ini akan meminta input kalimat dari pengguna. Pastikan kalimat yang dimasukkan minimal memiliki 3 kata.
Program kemudian akan membalik kalimat tersebut menggunakan stack. Stack adalah struktur data yang bekerja dengan prinsip "Last In, First Out" (LIFO).
Setiap karakter dalam kalimat dimasukkan ke dalam stack. Kemudian, karakter-karakter tersebut dikeluarkan dari stack satu per satu, sehingga membentuk kalimat yang terbalik.
Hasilnya, program akan menampilkan kalimat yang sudah terbalik.
getline(cin, kalimat): Digunakan untuk mengambil input kalimat dari pengguna. 
kalimat.length(): Digunakan untuk menghitung panjang kalimat. 
tumpukan.push(c): Digunakan untuk memasukkan karakter c ke dalam stack. 
tumpukan.empty(): Digunakan untuk memeriksa apakah stack kosong. 
tumpukan.top(): Digunakan untuk mendapatkan karakter teratas dalam stack tanpa mengeluarkannya. 
tumpukan.pop(): Digunakan untuk mengeluarkan karakter teratas dari stack.

## Kesimpulan
Stack merupakan struktur data yang penting dan serba guna di dalam C++ dikarenakan memiliki fungsi yang banyak bisa di combo dengan array maupun lingked list. dengan prinsip "terakhir masuk, pertama keluar" (LIFO). Elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan.
1. Kelebihan
membantu mengelola data dengan metode LIFO
secara otomatis membersihkan objek
tidak mudah rusak
ukuran variabel tidak dapat diubah
mengontrol memori secara mandiri
2. Kekurangan
memori stack sangat terbatas
ada kemungkinan stack akan meluap atau overflow jika terlalu banyak objek
tidak memungkinkan akses acak, karena harus mengeluarkan tumpukan paling atas terlebih dahulu untuk mengakses tumpukan paling bawah
## Daftar Pustaka
Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts,
problems, Interview Questions. CareerMonk Publications
Serebryany, Kostya. "Sanitize, fuzz, and harden your C++ code." San Francisco, CA (2016).
Wortman, Kevin. "Stacks: CS2/C++." POGIL Activity Clearinghouse 3.4 (2022).
Amy, Matthew, and Vlad Gheorghiu. "staq—A full-stack quantum processing toolkit." Quantum Science and Technology 5.3 (2020): 034016.


