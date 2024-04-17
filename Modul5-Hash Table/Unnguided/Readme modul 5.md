## Hash Table
## Coding by Luthfi Adi Harianto
## NIM 2311102172
## Kelas : IF 11 E

## MODUL 5
## HashTable
    A. TUJUAN PRAKTIKUM
a. Mahasiswa mampu menjelaskan definisi dan konsep dari Hash Code
b. Mahasiswa mampu menerapkan Hash Code kedalam pemrograman
    B. DASAR TEORI
a. Pengertian Hash Table
Hash Table adalah struktur data yang mengorganisir data ke dalam pasangan
kunci-nilai. Hash table biasanya terdiri dari dua komponen utama: array (atau
vektor) dan fungsi hash. Hashing adalah teknik untuk mengubah rentang nilai
kunci menjadi rentang indeks array.
Array menyimpan data dalam slot-slot yang disebut bucket. Setiap bucket
dapat menampung satu atau beberapa item data. Fungsi hash digunakan untuk
menghasilkan nilai unik dari setiap item data, yang digunakan sebagai indeks
array. Dengan cara ini, hash table memungkinkan pencarian data dalam waktu
yang konstan (O(1)) dalam kasus terbaik.
Sistem hash table bekerja dengan cara mengambil input kunci dan
memetakkannya ke nilai indeks array menggunakan fungsi hash. Kemudian, data
disimpan pada posisi indeks array yang dihasilkan oleh fungsi hash. Ketika data
perlu dicari, input kunci dijadikan sebagai parameter untuk fungsi hash, dan
posisi indeks array yang dihasilkan digunakan untuk mencari data. Dalam kasus
hash collision, di mana dua atau lebih data memiliki nilai hash yang sama, hash
table menyimpan data tersebut dalam slot yang sama dengan Teknik yang disebut
chaining.
    b. Fungsi Hash Table
Fungsi hash membuat pemetaan antara kunci dan nilai, hal ini dilakukan
melalui penggunaan rumus matematika yang dikenal sebagai fungsi hash. Hasil
dari fungsi hash disebut sebagai nilai hash atau hash. Nilai hash adalah
representasi dari string karakter asli tetapi biasanya lebih kecil dari aslinya.
    c. Operasi Hash Table
1. Insertion:
Memasukkan data baru ke dalam hash table dengan memanggil fungsi hash
untuk menentukan posisi bucket yang tepat, dan kemudian menambahkan
data ke bucket tersebut.
2. Deletion:
Menghapus data dari hash table dengan mencari data menggunakan fungsi
hash, dan kemudian menghapusnya dari bucket yang sesuai.
3. Searching:
Mencari data dalam hash table dengan memasukkan input kunci ke fungsi
hash untuk menentukan posisi bucket, dan kemudian mencari data di dalam
bucket yang sesuai.
4. Update:
Memperbarui data dalam hash table dengan mencari data menggunakan
fungsi hash, dan kemudian memperbarui data yang ditemukan.
5. Traversal:
Melalui seluruh hash table untuk memproses semua data yang ada dalam
tabel.
d. Collision Resolution
Keterbatasan tabel hash adalah jika dua angka dimasukkan ke dalam fungsi
hash menghasilkan nilai yang sama. Hal ini disebut dengan collision. Ada dua
teknik untuk menyelesaikan masalah ini diantaranya :
1. Open Hashing (Chaining)
Metode chaining mengatasi collision dengan cara menyimpan semua
item data dengan nilai indeks yang sama ke dalam sebuah linked list. Setiap
node pada linked list merepresentasikan satu item data. Ketika ada pencarian
atau penambahan item data, pencarian atau penambahan dilakukan pada
linked list yang sesuai dengan indeks yang telah dihitung dari kunci yang di
hash. Ketika linked list memiliki banyak node, pencarian atau penambahan
item data menjadi lambat, karena harus mencari di seluruh linked list.
Namun, chaining dapat mengatasi jumlah item data yang besar dengan
efektif, karena keterbatasan array dihindari.
2. Closed Hashing
● Linear Probing
Pada saat terjadi collision, maka akan mencari posisi yang kosong di
bawah tempat terjadinya collision, jika masih penuh terus ke bawah,
hingga ketemu tempat yang kosong. Jika tidak ada tempat yang kosong
berarti HashTable sudah penuh.
● Quadratic Probing
Penanganannya hampir sama dengan metode linear, hanya
lompatannya tidak satu-satu, tetapi quadratic ( 12, 22, 32, 42, ... )
● Double Hashing
Pada saat terjadi collision, terdapat fungsi hash yang kedua untuk
menentukan posisinya kembali.

## Guided
    Guided 1
``` C++
    #include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key) {
return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node {
int key;
int value;
Node* next;
Node(int key, int value) : key(key), value(value),
next(nullptr) {}
};
// Class hash table
class HashTable {
private:
Node** table;
public:
HashTable() {
table = new Node*[MAX_SIZE]();
}
~HashTable() {
for (int i = 0; i < MAX_SIZE; i++) {
Node* current = table[i];
while (current != nullptr) {
Node* temp = current;
current = current->next;
delete temp;
}
}
delete[] table;
}
// Insertion
void insert(int key, int value) {
int index = hash_func(key);
Node* current = table[index];
while (current != nullptr) {
if (current->key == key) {
current->value = value;
return;
}
current = current->next;
}
Node* node = new Node(key, value);
node->next = table[index];
table[index] = node;
}
// Searching
int get(int key) {
int index = hash_func(key);
Node* current = table[index];
while (current != nullptr) {
if (current->key == key) {
return current->value;
}
current = current->next;
}
return -1;
}
// Deletion
void remove(int key) {
int index = hash_func(key);
Node* current = table[index];
Node* prev = nullptr;
while (current != nullptr) {
if (current->key == key) {
if (prev == nullptr) {
table[index] = current->next;
} else {
prev->next = current->next;
}
delete current;
return;
}
prev = current;
current = current->next;
}
}
// Traversal
void traverse() {
for (int i = 0; i < MAX_SIZE; i++) {
Node* current = table[i];
while (current != nullptr) {
cout << current->key << ": " << current->value
<< endl;
current = current->next;
}
}
}
};
int main() {
HashTable ht;
// Insertion
ht.insert(1, 10);
ht.insert(2, 20);
ht.insert(3, 30);
// Searching
cout << "Get key 1: " << ht.get(1) << endl;
cout << "Get key 4: " << ht.get(4) << endl;
// Deletion
ht.remove(4);
// Traversal
ht.traverse();
return 0;
}
```
![alt text](<Screenshot 2024-04-17 124120-1.png>)</br>
Kode di atas menggunakan array dinamis “table” untuk menyimpan bucket dalam
hash table. Setiap bucket diwakili oleh sebuah linked list dengan setiap node
merepresentasikan satu item data. Fungsi hash sederhana hanya menggunakan
modulus untuk memetakan setiap input kunci ke nilai indeks array.
## Guided 2
``` C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int TABLE_SIZE = 11;
string name;
string phone_number;
class HashNode {
public:
string name;
string phone_number;
HashNode(string name, string phone_number) {
this->name = name;
this->phone_number = phone_number;
}
};
class HashMap {
private:
vector<HashNode*> table[TABLE_SIZE];
public:
int hashFunc(string key) {
int hash_val = 0;
for (char c : key) {
hash_val += c;
}
return hash_val % TABLE_SIZE;
}
void insert(string name, string phone_number) {
int hash_val = hashFunc(name);
for (auto node : table[hash_val]) {
if (node->name == name) {
node->phone_number = phone_number;
return;
}
}
table[hash_val].push_back(new HashNode(name,
phone_number));
}
void remove(string name) {
int hash_val = hashFunc(name);
for (auto it = table[hash_val].begin(); it !=
table[hash_val].end(); it++) {
if ((*it)->name == name) {
table[hash_val].erase(it);
return;
}
}
}
string searchByName(string name) {
int hash_val = hashFunc(name);
for (auto node : table[hash_val]) {
if (node->name == name) {
return node->phone_number;
}
}
return "";
}
void print() {
for (int i = 0; i < TABLE_SIZE; i++) {
cout << i << ": ";
for (auto pair : table[i]) {
if(pair != nullptr){
cout << "[" << pair->name << ", " <<
pair->phone_number << "]";
}
}
cout << endl;
}
}
};
int main() {
HashMap employee_map;
employee_map.insert("Mistah", "1234");
employee_map.insert("Pastah", "5678");
employee_map.insert("Ghana", "91011");
cout << "Nomer Hp Mistah : "
<<employee_map.searchByName("Mistah") << endl;
cout << "Phone Hp Pastah : "
<<employee_map.searchByName("Pastah") << endl;
employee_map.remove("Mistah");
cout << "Nomer Hp Mistah setelah dihapus : "
<<employee_map.searchByName("Mistah") << endl << endl;
cout << "Hash Table : " << endl;
employee_map.print();
return 0;
}
```
![alt text](<Screenshot 2024-04-17 124151-1.png>)</br>
![alt text](<Screenshot 2024-04-17 124206-1.png>)</br>
Pada program di atas, class HashNode merepresentasikan setiap node dalam hash
table, yang terdiri dari nama dan nomor telepon karyawan. Class HashMap
digunakan untuk mengimplementasikan struktur hash table dengan menggunakan
vector yang menampung pointer ke HashNode. Fungsi hashFunc digunakan
untuk menghitung nilai hash dari nama karyawan yang diberikan, dan fungsi
insert digunakan untuk menambahkan data baru ke dalam hash table. Fungsi
remove digunakan untuk menghapus data dari hash table, dan fungsi
searchByName digunakan untuk mencari nomor telepon dari karyawan dengan
nama yang diberikan.

## Unguided
    unguided 1
``` C++
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Struktur untuk data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    int nilai;
};

// Fungsi untuk menambahkan data mahasiswa
void tambahData(unordered_map<string, Mahasiswa>& hashTable) {
    Mahasiswa mhs;
    cout << "Masukkan Nama Mahasiswa: ";
    cin >> mhs.nama;
    cout << "Masukkan NIM Mahasiswa: ";
    cin >> mhs.nim;
    cout << "Masukkan Nilai Mahasiswa: ";
    cin >> mhs.nilai;
    
    hashTable[mhs.nim] = mhs;
    cout << "Data Mahasiswa berhasil ditambahkan." << endl;
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NIM
void hapusData(unordered_map<string, Mahasiswa>& hashTable) {
    string nim;
    cout << "Masukkan NIM Mahasiswa yang akan dihapus: ";
    cin >> nim;

    if (hashTable.find(nim) != hashTable.end()) {
        hashTable.erase(nim);
        cout << "Data Mahasiswa dengan NIM " << nim << " berhasil dihapus." << endl;
    } else {
        cout << "Data Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk mencari data mahasiswa berdasarkan NIM
void cariDataNIM(const unordered_map<string, Mahasiswa>& hashTable) {
    string nim;
    cout << "Masukkan NIM Mahasiswa yang ingin dicari: ";
    cin >> nim;

    if (hashTable.find(nim) != hashTable.end()) {
        Mahasiswa mhs = hashTable.at(nim);
        cout << "Data Mahasiswa ditemukan:" << endl;
        cout << "Nama: " << mhs.nama << endl;
        cout << "NIM: " << mhs.nim << endl;
        cout << "Nilai: " << mhs.nilai << endl;
    } else {
        cout << "Data Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }
}
int main() {
    unordered_map<string, Mahasiswa> hashTable;
    int choice;
    do {
        cout << "\nSelamat Datang di Arsip Data Mahasiswa Institut Teknologi Telkom Purwokerto\n";
        cout << "\nMenu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Cari Data berdasarkan NIM\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tambahData(hashTable);
                break;
            case 2:
                hapusData(hashTable);
                break;
            case 3:
                cariDataNIM(hashTable);
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
```
![alt text](<Screenshot 2024-04-17 121438-1.png>)</br>
![alt text](<Screenshot 2024-04-17 121520-1.png>)</br>
![alt text](<Screenshot 2024-04-17 121648-1.png>)</br>
Kode diatas digunakan untuk menginputkan menyimpan data mahasiswa institut teknologi telkom purwokerto menggunakan metode hash table dengan mencari nim mahasiswa tersebut

## Kesimpulan
Hash table merupakan struktur data yang secara asosiatif menyimpan data, hash table menjadi struktur data di mana operasi penyisipan dan pencarian data terjadi sangat cepat terlepas dari ukuran data tersebut. Hash table menggunakan array sebagai media penyimpanan dan tekniknya untuk menghasilkan indeks suatu elemen yang dimasukkan atau ditempatkan.

## Daftar Pustaka
1.) Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts,
problems, Interview Questions. CareerMonk Publications.
2.) F. Ramadhan, “Implementasi Algoritma Hash Based
Terhadap Aturan Asosiasi untuk Menentukan Frequent
Itemset Study Kasus Rumah Makan Seafood ‘Kita,’”
Semin. Nas. Teknol. Inf. dan Multimed., pp. 97–102, 2017.
3.) E. A. Orisky Sitra Arifah Destiyati, “Analisis Perbandingan
Algoritma Apriori Dan Algoritma Hash Based Pada Market
Basket Analysis Di Apotek Uad,” J. Sarj. Tek. Inform., vol.
3, no. 1, pp. 1–10, 2015, doi: 10.12928/jstie.v3i1.2896.
4.) Yuli Mard, “Data Mining : Klasifikasi Menggunakan
Algoritma C4.5,” J. Edik Inform., vol. 2, no. 2, pp. 213–
219, 2017.
