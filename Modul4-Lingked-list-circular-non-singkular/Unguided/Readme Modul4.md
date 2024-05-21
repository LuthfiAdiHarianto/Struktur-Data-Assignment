## LINGKED LIST CIRCULAR DAN NON CIRCULAR
## Coding by Luthfi Adi Harianto
## NIM 2311102172
## Kelas : IF 11 E

## MODUL 4
## LINKED LIST CIRCULAR DAN NON CIRCULAR

## TUJUAN PRAKTIKUM
a. Praktikan dapat mengetahui dan memahami linked list circular dan non circular.
b. Praktikan dapat membuat linked list circular dan non circular.
c. Praktikan dapat mengaplikasikan atau menerapkan linked list circular dan non 
circular pada program yang dibuat.
## DASAR TEORI
1. Linked List Non Circular
Linked list non circular merupakan linked list dengan node pertama (head) dan 
node terakhir (tail) yang tidak saling terhubung. Pointer terakhir (tail) pada Linked 
List ini selalu bernilai ‘NULL’ sebagai pertanda data terakhir dalam list-nya. Linked 
list non circular dapat digambarkan sebagai berikut.
Gambar 1 Single Linked List Non Circular
OPERASI PADA LINKED LIST NON CIRCULAR
1. Deklarasi Simpul (Node)
2. Membuat dan Menginisialisasi Pointer Head dan Tail
``` C++
struct node
{
int data;
node *next;
};
node *head, *tail;
void init()
{
head = NULL;
tail = NULL;
};
```
Praktikum Struktur Data dan Algoritma 2
3. Pengecekan Kondisi Linked List
4. Penambahan Simpul (Node)
``` C++
bool isEmpty()
{
if (head == NULL && tail == NULL)
{
return true;
}
else
{
return false;
}
}
void insertBelakang(string dataUser)
{
if (isEmpty() == true)
{
node *baru = new node;
baru->data = dataUser;
head = baru;
tail = baru;
baru->next = NULL;
}
else
{
node *baru = new node;
baru->data = dataUser;
baru->next = NULL;
tail->next = baru;
tail = baru;
}
};
``` C++
5. Penghapusan Simpul (Node)
``` C++
void hapusDepan()
{
if (isEmpty() == true)
{
cout << "List kosong!" << endl;
}
else
{
node *helper;
helper = head;
if (head == tail)
{
head = NULL;
tail = NULL;
delete helper;
}
else
head = head->next;
helper->next = NULL;
delete helper;
}
}
}
``` C++
    Praktikum Struktur Data dan Algoritma 4
6. Tampil Data Linked List
```C++
void tampil()
{
if (isEmpty() == true)
{
cout << "List kosong!" << endl;
}
else
{
node *helper;
helper = head;
while (helper != NULL)
{
cout << helper->data << ends;
helper = helper->next;
}
}
}
``` C++
Praktikum Struktur Data dan Algoritma 5
1. Deklarasi Simpul (Node)
2. Membuat dan Menginisialisasi Pointer Head dan Tail
3. Pengecekan Kondisi Linked List
4. Pembuatan Simpul (Node) 
``` C++
struct Node
{
string data;
Node *next;
};
Node *head, *tail, *baru, *bantu, *hapus;
void init()
{
head = NULL;
tail = head;
}
int isEmpty()
{
if (head == NULL)
return 1; // true
else
return 0; // false
}
void buatNode(string data)
{
baru = new Node;
baru->data = data;
baru->next = NULL;
}
``` C++
    Praktikum Struktur Data dan Algoritma 6
5. Penambahan Simpul (Node)
// Tambah Depan
``` C++
void insertDepan(string data)
{
// Buat Node baru
buatNode(data);
if (isEmpty() == 1)
{
head = baru;
tail = head;
baru->next = head;
}
else
{
while (tail->next != head)
{
tail = tail->next;
}
baru->next = head;
head = baru;
tail->next = head;
}
}
``` C++
    Praktikum Struktur Data dan Algoritma 7
6. Penghapusan Simpul (Node)
``` C++
void hapusBelakang()
{
if (isEmpty() == 0)
{
hapus = head;
tail = head;
if (hapus->next == head)
{
head = NULL;
tail = NULL;
delete hapus;
}
else
{
while (hapus->next != head)
{
hapus = hapus->next;
}
while (tail->next != hapus)
{
tail = tail->next;
}
tail->next = head;
hapus->next = NULL;
delete hapus;
}
}
``` C++
    Praktikum Struktur Data dan Algoritma 8
7. Menampilkan Data Linked List
``` C++
void tampil()
{
if (isEmpty() == 0)
{
tail = head;
do
{
cout << tail->data << ends;
tail = tail->next;
} while (tail != head);
cout << endl;
}
}
``` C++
## Praktikum Struktur Data dan Algoritma 9

## GUIDED
1. Linked List Non Circular
``` C++
#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
int data;
Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
head = NULL;
tail = NULL;
}
// Pengecekan
bool isEmpty()
{
if (head == NULL)
return true;
else
return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
// Buat Node baru
Node *baru = new Node;
baru->data = nilai;
baru->next = NULL;
if (isEmpty() == true)
{
head = tail = baru;
tail->next = NULL;
}
else
{
baru->next = head;
head = baru;
}
}
// Tambah Belakang
void insertBelakang(int nilai)
{
// Buat Node baru
Node *baru = new Node;
baru->data = nilai;
baru->next = NULL;
if (isEmpty() == true)
{
head = tail = baru;
tail->next = NULL;
}
else
{
tail->next = baru;
tail = baru;
}
}
// Hitung Jumlah List
int hitungList()
{
Node *hitung;
hitung = head;
int jumlah = 0;
while (hitung != NULL)
{
jumlah++;
hitung = hitung->next;
}
return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
if (posisi < 1 || posisi > hitungList())
{
cout << "Posisi diluar jangkauan" << endl;
}
else if (posisi == 1)
{
cout << "Posisi bukan posisi tengah" << endl;
}
else
{
Node *baru, *bantu;
baru = new Node();
baru->data = data;
// tranversing
bantu = head;
int nomor = 1;
while (nomor < posisi - 1)
{
bantu = bantu->next;
}
baru
nomor++;
->next = bantu->next;
bantu->next = baru;
}
}
// Hapus Depan
void hapusDepan()
{
Node *hapus;
if (isEmpty() == false)
{
if (head->next != NULL)
{
hapus = head;
head = head->next
}
else
{
}
}
delete hapus;
head = tail = NULL;
else
{
cout << "List kosong!" << endl;
}
}
// Hapus Belakang
void hapusBelakang()
{
Node *hapus;
Node *bantu;
if (isEmpty() == false)
{
if (head != tail)
{
hapus = tail;
bantu = head;
while (bantu->next != tail)
{
bantu = bantu->next;
}
tail = bantu;
tail->next = NULL;
}
else
{
}
}
delete hapus;
head = tail = NULL;
else
{
cout << "List kosong!" << endl;
}
}
// Hapus Tengah
void hapusTengah(int posisi)
{
Node *bantu, *hapus, *sebelum;
if (posisi < 1 || posisi > hitungList())
{
cout << "Posisi di luar jangkauan" << endl;
}
else if (posisi == 1)
{
cout << "Posisi bukan posisi tengah" << endl;
}
else
{
int nomor = 1;
bantu = head;
while (nomor <= posisi)
{
if (nomor == posisi - 1)
{
sebelum = bantu;
}
if (nomor == posisi)
{
hapus = bantu;
}
bantu = bantu->next;
nomor++;
}
sebelum->next = bantu;
delete hapus;
}
}
// Ubah Depan
void ubahDepan(int data)
{
if (isEmpty() == 0)
{
head->data = data;
}
else
{
cout << "List masih kosong!" << endl;
}
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
Node *bantu;
if (isEmpty() == 0)
{
if (posisi < 1 || posisi > hitungList())
{
cout << "Posisi di luar jangkauan" << endl;
}
else if (posisi == 1)
{
}
else
{
cout << "Posisi bukan posisi tengah" << endl;
bantu = head;
int nomor = 1;
while (nomor < posisi)
{
bantu = bantu->next;
nomor++;
}
bantu->data = data;
}
}
else
{
cout << "List masih kosong!" << endl;
}
}
// Ubah Belakang
void ubahBelakang(int data)
{
if (isEmpty() == 0)
{
tail->data = data;
}
else
{
cout << "List masih kosong!" << endl;
}
}
// Hapus List
void clearList()
{
Node *bantu, *hapus;
bantu = head;
while (bantu != NULL)
{
hapus = bantu;
bantu = bantu->next;
delete hapus;
}
head = tail = NULL;
cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
Node *bantu;
bantu = head;
if (isEmpty() == false)
{
while (bantu != NULL)
{
cout << bantu->data << ends;
bantu = bantu->next;
}
cout << endl;
}
else
{
cout << "List masih kosong!" << endl;
}
}
int main()
{
init();
insertDepan(3);
tampil();
insertBelakang(5);
tampil();
insertDepan(2);
tampil();
insertDepan(1);
tampil();
hapusDepan();
tampil();
hapusBelakang();
tampil();
insertTengah(7, 2);
tampil();
hapusTengah(2);
tampil();
ubahDepan(1);
tampil();
ubahBelakang(8);
tampil();
ubahTengah(11, 2);
tampil();
return 0;
}
``` 
![alt text](<Screenshot 2024-04-03 170440-1.png>)</br>
program diatas digunakan untuk menampilkan output nilai angka yang dimasukkan

2. Linked List Circular
``` C++
#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST CIRCULAR
// Deklarasi Struct Node
struct Node
{
string data;
Node *next;
};
Node *head, *tail, *baru, *bantu, *hapus;
void init()
{
head = NULL;
tail = head;
}
// Pengecekan
int isEmpty()
{
if (head == NULL)
return 1; // true
else
return 0; // false
}
// Buat Node Baru
void buatNode(string data)
{
baru = new Node;
baru->data = data;
baru->next = NULL;
}
// Hitung List
int hitungList()
{
bantu = head;
int jumlah = 0;
while (bantu != NULL)
{
jumlah++;
bantu = bantu->next;
}
return jumlah;
}
// Tambah Depan
void insertDepan(string data)
{
// Buat Node baru
buatNode(data);
if (isEmpty() == 1)
{
head = baru;
tail = head;
baru->next = head;
}
else
{
while (tail->next != head)
{
tail = tail->next;
}
baru->next = head;
head = baru;
tail->next = head;
}
}
// Tambah Belakang
void insertBelakang(string data)
{
// Buat Node baru
buatNode(data);
if (isEmpty() == 1)
{
head = baru;
tail = head;
baru->next = head;
}
else
{
while (tail->next != head)
{
tail = tail->next;
}
tail->next = baru;
baru->next = head;
}
}
// Tambah Tengah
void insertTengah(string data, int posisi)
{
if (isEmpty() == 1)
{
head = baru;
tail = head;
baru->next = head;
}
else
{
baru->data = data;
// transversing
int nomor = 1;
bantu = head;
while (nomor < posisi - 1)
{
bantu = bantu->next;
nomor++;
}
baru->next = bantu->next;
bantu->next = baru;
}
}
// Hapus Depan
void hapusDepan()
{
if (isEmpty() == 0)
{
hapus = head;
tail = head;
if (hapus->next == head)
{
head = NULL;
tail = NULL;
}
else
{
delete hapus;
while (tail->next != hapus)
{
tail = tail->next;
}
head = head->next;
tail->next = head;
hapus->next = NULL;
delete hapus;
}
}
else
{
cout << "List masih kosong!" << endl;
}
}
// Hapus Belakang
void hapusBelakang()
{
if (isEmpty() == 0)
{
hapus = head;
tail = head;
if (hapus->next == head)
{
head = NULL;
tail = NULL;
}
else
{
delete hapus;
while (hapus->next != head)
{
hapus = hapus->next;
}
while (tail->next != hapus)
{
tail = tail->next;
}
tail->next = head;
hapus->next = NULL;
delete hapus;
}
}
else
{
cout << "List masih kosong!" << endl;
}
}
// Hapus Tengah
void hapusTengah(int posisi)
{
if (isEmpty() == 0)
{
// transversing
int nomor = 1;
bantu = head;
while (nomor < posisi - 1)
{
bantu = bantu->next;
nomor++;
}
hapus = bantu->next;
bantu->next = hapus->next;
delete hapus;
}
else
{
cout << "List masih kosong!" << endl;
}
}
// Hapus List
void clearList()
{
if (head != NULL)
{
hapus = head->next;
while (hapus != head)
{
bantu = hapus->next;
delete hapus;
hapus = bantu;
}
delete head;
head = NULL;
}
cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
if (isEmpty() == 0)
{
tail = head;
do
{
cout << tail->data << ends;
tail = tail->next;
} while (tail != head);
cout << endl;
}
else
{
cout << "List masih kosong!" << endl;
}
}
int main()
{
init();
insertDepan("Ayam");
tampil();
insertDepan("Bebek");
tampil();
insertBelakang("Cicak");
tampil();
insertBelakang("Domba");
tampil();
hapusBelakang();
tampil();
hapusDepan();
tampil();
insertTengah("Sapi", 2);
tampil();
hapusTengah(2);
tampil();
return 0;
```
![alt text](<Screenshot 2024-04-03 170506-1.png>)</br>
## Unguided
    Unguided 1
``` C++
// Coding by Luthfi Adi Harianto
// NIM 2311102172
// Kelas IF 11 E
#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct node {
    string nama;
    string nim;
    node *next;
};

// Deklarasi variabel head dan tail
node *head;
node *tail;

// Inisialisasi linked list
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool isempty() {
    return head == NULL;
}
// Menghitung jumlah node dalam linked list
int hitunglist() {
    int jumlah = 0;
    node *bantu = head;
    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Menambah data mahasiswa di depan linked list
void insertdepan(string nama, string nim) {
    // Membuat node baru
    node *baru = new node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    // Jika linked list kosong
    if (isempty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Menambah data mahasiswa di belakang linked list
void insertbelakang(string nama, string nim) {
    // Membuat node baru
    node *baru = new node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    // Jika linked list kosong
    if (isempty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Menambah data mahasiswa di tengah linked list
void inserttengah(string nama, string nim, int posisi) {
    if (posisi < 1 || posisi > hitunglist() + 1) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        if (posisi == 1) {
            insertdepan(nama, nim);
        } else if (posisi == hitunglist() + 1) {
            insertbelakang(nama, nim);
        } else {
            node *baru = new node;
            baru->nama = nama;
            baru->nim = nim;

            node *bantu = head;
            for (int i = 1; i < posisi - 1; ++i) {
                bantu = bantu->next;
            }

            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
}

// Mengubah data mahasiswa di depan linked list
void ubahdepan(string nama, string nim) {
    if (!isempty()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = head->nama;
        string nim_sebelum = head->nim;

        // Mengubah data
        head->nama = nama;
        head->nim = nim;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama << endl;
    } else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di belakang linked list
void ubahbelakang(string nama, string nim) {
    if (!isempty()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = tail->nama;
        string nim_sebelum = tail->nim;

        // Mengubah data
        tail->nama = nama;
        tail->nim = nim;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama << endl;
    } else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di tengah linked list
void ubahtengah(string nama, string nim, int posisi) {
    if (posisi < 1 || posisi > hitunglist()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        node *bantu = head;
        for (int i = 1; i < posisi; ++i) {
            bantu = bantu->next;
        }

        // Menyimpan data sebelum diubah
        string nama_sebelum = bantu->nama;
        string nim_sebelum = bantu->nim;

        // Mengubah data
        bantu->nama = nama;
        bantu->nim = nim;

        // Menampilkan informasi
        cout << "Data pada posisi " << posisi << " telah diubah dari " << nama_sebelum << " menjadi " << nama << endl;
    }
}

// Menghapus data mahasiswa di depan linked list
void hapusdepan() {
    if (!isempty()) {
        node *hapus = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
        }
        delete hapus;
    } else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di belakang linked list
void hapusbelakang() {
    if (!isempty()) {
        node *hapus = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        }
        delete hapus;
    } else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di tengah linked list
void hapustengah(int posisi) {
    if (posisi < 1 || posisi > hitunglist()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        if (posisi == 1) {
            hapusdepan();
        } else if (posisi == hitunglist()) {
            hapusbelakang();
        } else {
            node *hapus = head;
            for (int i = 1; i < posisi - 1; ++i) {
                hapus = hapus->next;
            }
            node *hapus_node = hapus->next;
            hapus->next = hapus_node->next;
            delete hapus_node;
        }
    }
}

// Menghapus seluruh data di dalam linked list
void hapuslist() {
    while (!isempty()) {
        hapusdepan();
    }
    cout << "Linked list berhasil dihapus semua!" << endl;
}

// Menampilkan seluruh data dalam linked list
void tampilkan() {
    if (!isempty()) {
        node *bantu = head;
        int nomor = 1; // Variabel untuk nomor indeks atau nomor urut
        cout << setw(5) << left << "No" << setw(15) << left << "NAMA" << "NIM" << endl;
        while (bantu != NULL) {
            cout << setw(5) << left << nomor << setw(15) << left << bantu->nama << bantu->nim << endl;
            bantu = bantu->next;
            nomor++; // Menginkremen nomor indeks atau nomor urut
        }
    } else {
        cout << "Linked list kosong!" << endl;
    }
}
int main() {
    init();
    int pilihan;
    string nama;
    string nim;
    int posisi;

    do {
        // Menampilkan menu
        cout << "Data Alih Mahasiswa Institut Teknologi Telkom Purwokerto to Telkom University Purwokerto"  << endl;
        cout <<endl;
        cout << "1.Tambah Depan" << endl;
        cout << "2.Tambah Belakang" << endl;
        cout << "3.Tambah Tengah" << endl;
        cout << "4.Ubah Depan" << endl;
        cout << "5.Ubah Belakang" << endl;
        cout << "6.Ubah Tengah" << endl;
        cout << "7.Hapus Depan" << endl;
        cout << "8.Hapus Belakang" << endl;
        cout << "9.Hapus Tengah" << endl;
        cout << "10.Hapus List" << endl;
        cout << "11.Tampilkan" << endl;
        cout << "0.Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan;
        cout <<endl;

        switch (pilihan) {
            case 1:
                cout <<"=TAMBAH DEPAN="<<endl;
                cout << endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insertdepan(nama, nim);
                break;
            case 2:
                cout << "=Tambah Belakang"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insertbelakang(nama, nim);
                break;
            case 3:
                cout << "=Tambah Tengah="<<endl;
                cout<<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout << "Masukkan Posisi :";
                cin >> posisi;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                inserttengah(nama, nim, posisi);
                break;
            case 4:
                cout << "=Ubah Depan="<<endl;
                cout<<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout << endl;
                ubahdepan(nama, nim);
                break;
            case 5:
                cout << "Ubah Belakang"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout << endl;
                ubahbelakang(nama, nim);
                break;
            case 6:
                cout << "Ubah Tengah"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout << "Masukkan Posisi :";
                cin >> posisi;
                cout << endl;
                ubahtengah(nama, nim, posisi);
                break;
            case 7:
                cout << "=Hapus Depan="<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama;
                cout << "data "<<nama<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapusdepan();
                break;
            case 8:
                cout << "=Hapus Belakang="<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama;
                cout << "data "<<nama<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapusbelakang();
                break;
            case 9:
                cout << "=Hapus Tengah="<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama;
                cout <<"Posisi"<<endl;
                cin >>posisi;
                cout << "data "<<nama<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapustengah(posisi);
                break;
            case 10:
                cout << "=Hapus List="<<endl;
                cout <<endl;
                hapuslist();
                break;
            case 11:
                cout << "=Menampilkan Semua data mahasiswa="<<endl;
                cout <<endl;
                cout <<"=Data Mahasiswa="<<endl;
                cout << endl;
                tampilkan();
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
```
![alt text](<Screenshot 2024-04-03 170847-1.png>)</br>
![alt text](<Screenshot 2024-04-03 170933-1.png>)</br>
Kode diatas digunakan untuk membuat list data mahasiswa institut teknologi telkom purwokerto meliputi nama dan nim selain itu list tersebut dapat ditambahkan diubah maupun dihapus

    Unguided 2
``` C++
// Coding by Luthfi Adi Harianto
// NIM 231102172
// Kelas IF 11 E
#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct node {
    string nama;
    string nim;
    node *next;
};

// Deklarasi variabel head dan tail
node *head;
node *tail;

// Inisialisasi linked list
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool isempty() {
    return head == NULL;
}
// Menghitung jumlah node dalam linked list
int hitunglist() {
    int jumlah = 0;
    node *bantu = head;
    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Menambah data mahasiswa di depan linked list
void insertdepan(string nama, string nim) {
    // Membuat node baru
    node *baru = new node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    // Jika linked list kosong
    if (isempty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Menambah data mahasiswa di belakang linked list
void insertbelakang(string nama, string nim) {
    // Membuat node baru
    node *baru = new node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    // Jika linked list kosong
    if (isempty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Menambah data mahasiswa di tengah linked list
void inserttengah(string nama, string nim, int posisi) {
    if (posisi < 1 || posisi > hitunglist() + 1) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        if (posisi == 1) {
            insertdepan(nama, nim);
        } else if (posisi == hitunglist() + 1) {
            insertbelakang(nama, nim);
        } else {
            node *baru = new node;
            baru->nama = nama;
            baru->nim = nim;

            node *bantu = head;
            for (int i = 1; i < posisi - 1; ++i) {
                bantu = bantu->next;
            }

            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
}

// Mengubah data mahasiswa di depan linked list
void ubahdepan(string nama, string nim) {
    if (!isempty()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = head->nama;
        string nim_sebelum = head->nim;

        // Mengubah data
        head->nama = nama;
        head->nim = nim;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama << endl;
    } else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di belakang linked list
void ubahbelakang(string nama, string nim) {
    if (!isempty()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = tail->nama;
        string nim_sebelum = tail->nim;

        // Mengubah data
        tail->nama = nama;
        tail->nim = nim;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama << endl;
    } else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di tengah linked list
void ubahtengah(string nama, string nim, int posisi) {
    if (posisi < 1 || posisi > hitunglist()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        node *bantu = head;
        for (int i = 1; i < posisi; ++i) {
            bantu = bantu->next;
        }

        // Menyimpan data sebelum diubah
        string nama_sebelum = bantu->nama;
        string nim_sebelum = bantu->nim;

        // Mengubah data
        bantu->nama = nama;
        bantu->nim = nim;

        // Menampilkan informasi
        cout << "Data pada posisi " << posisi << " telah diubah dari " << nama_sebelum << " menjadi " << nama << endl;
    }
}

// Menghapus data mahasiswa di depan linked list
void hapusdepan() {
    if (!isempty()) {
        node *hapus = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
        }
        delete hapus;
    } else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di belakang linked list
void hapusbelakang() {
    if (!isempty()) {
        node *hapus = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        }
        delete hapus;
    } else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di tengah linked list
void hapustengah(int posisi) {
    if (posisi < 1 || posisi > hitunglist()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        if (posisi == 1) {
            hapusdepan();
        } else if (posisi == hitunglist()) {
            hapusbelakang();
        } else {
            node *hapus = head;
            for (int i = 1; i < posisi - 1; ++i) {
                hapus = hapus->next;
            }
            node *hapus_node = hapus->next;
            hapus->next = hapus_node->next;
            delete hapus_node;
        }
    }
}

// Menghapus seluruh data di dalam linked list
void hapuslist() {
    while (!isempty()) {
        hapusdepan();
    }
    cout << "Linked list berhasil dihapus semua!" << endl;
}

// Menampilkan seluruh data dalam linked list
void tampilkan() {
    if (!isempty()) {
        node *bantu = head;
        int nomor = 1; // Variabel untuk nomor indeks atau nomor urut
        cout << setw(5) << left << "No" << setw(15) << left << "NAMA" << "NIM" << endl;
        while (bantu != NULL) {
            cout << setw(5) << left << nomor << setw(15) << left << bantu->nama << bantu->nim << endl;
            bantu = bantu->next;
            nomor++; // Menginkremen nomor indeks atau nomor urut
        }
    } else {
        cout << "Linked list kosong!" << endl;
    }
}
int main() {
    init();
    int pilihan;
    string nama;
    string nim;
    int posisi;
    do {
        // Menampilkan menu
        cout << "Data Alih Mahasiswa Institut Teknologi Telkom Purwokerto to Telkom University Purwokerto" << endl;
        cout <<endl;
        cout << "1.Tambah Depan" << endl;
        cout << "2.Tambah Belakang" << endl;
        cout << "3.Tambah Tengah" << endl;
        cout << "4.Ubah Depan" << endl;
        cout << "5.Ubah Belakang" << endl;
        cout << "6.Ubah Tengah" << endl;
        cout << "7.Hapus Depan" << endl;
        cout << "8.Hapus Belakang" << endl;
        cout << "9.Hapus Tengah" << endl;
        cout << "10.Hapus List" << endl;
        cout << "11.Tampilkan" << endl;
        cout << "0.Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan;
        cout <<endl;

     // Insert data mahasiswa dengan insertdepan
    insertdepan("Jawad", "23300001");

    // Insert data mahasiswa dengan inserttengah
    inserttengah("Luthfi", "231102172", 2);
    inserttengah("Farrel", "23300003", 3);
    inserttengah("Denis", "23300005", 4);
    inserttengah("Anis", "23300008", 5);
    // Insert data mahasiswa dengan insertbelakang
    insertbelakang("Bowo", "23300015");
    insertbelakang("Gahar", "23300040");
    insertbelakang("Udin", "23300048");
    insertbelakang("Ucok", "23300050");
    insertbelakang("Budi", "23300099");

    // menambahkan data wati diantara farrel dan Denis
    inserttengah("Farrel", "Wati", 2330004);

    // Menambahkan data owi di list awal
    insertdepan("Owi", "2330000");

    // menambahkan data david di list akhir
    insertbelakang("David", "23300100");

    // mengubah data Udin menjadi Idin list akhir
    ubahbelakang("Idin", "23300045");

    // ubah data terakhir menjadi lucy
    ubahbelakang("Lucy", "23300101");

    // ubah data awal menjadi bagas
    ubahdepan( "Bagas", "2330002");
        switch (pilihan) {
            case 1:
                cout <<"=TAMBAH DEPAN="<<endl;
                cout << endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insertdepan(nama, nim);
                break;
            case 2:
                cout << "=Tambah Belakang"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insertbelakang(nama, nim);
                break;
            case 3:
                cout << "=Tambah Tengah="<<endl;
                cout<<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout << "Masukkan Posisi :";
                cin >> posisi;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                inserttengah(nama, nim, posisi);
                break;
            case 4:
                cout << "=Ubah Depan="<<endl;
                cout<<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout << endl;
                ubahdepan(nama, nim);
                break;
            case 5:
                cout << "Ubah Belakang"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout << endl;
                ubahbelakang(nama, nim);
                break;
            case 6:
                cout << "Ubah Tengah"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout << "Masukkan Posisi :";
                cin >> posisi;
                cout << endl;
                ubahtengah(nama, nim, posisi);
                break;
            case 7:
                cout << "=Hapus Depan="<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama;
                cout << "data "<<nama<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapusdepan();
                break;
            case 8:
                cout << "=Hapus Belakang="<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama;
                cout << "data "<<nama<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapusbelakang();
                break;
            case 9:
                cout << "=Hapus Tengah="<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama;
                cout <<"Posisi"<<endl;
                cin >>posisi;
                cout << "data "<<nama<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapustengah(posisi);
                break;
            case 10:
                cout << "=Hapus List="<<endl;
                cout <<endl;
                hapuslist();
                break;
            case 11:
                cout << "=Menampilkan Semua data mahasiswa="<<endl;
                cout <<endl;
                cout <<"=Data Mahasiswa="<<endl;
                cout << endl;
                tampilkan();
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
```
![alt text](<Screenshot 2024-04-03 171050-1.png>)</br>
![alt text](<Screenshot 2024-04-03 171137-1.png>)</br>
![alt text](<Screenshot 2024-04-03 172416-1.png>)</br>
![alt text](<Screenshot 2024-04-03 173030-1.png>)</br>
Kode diatas digunakan untuk membuat list data mahasiswa institut teknologi telkom purwokerto meliputi nama owi jawad luthfi dan nama lainnya dan nim 2311102172 maupun nim angka lainnya selain itu list tersebut dapat ditambahkan diubah maupun dihapus

## Kesimpulan
dari lingked list circular dan non circular kita bisa menambah, edit, dan hapus suatu nama, nilai, barang dan lain lain yang kita inputkan ke dalam list yang kita miliki jadi lebih mudah dan efisien

## Daftar Pustaka
Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, 
problems, Interview Questions. CareerMonk Publications
de Medeiros, M.M.; Hoppen, N.; Macada, A.C.G. Data science for business: Benefits, challenges and opportunities. Bottom Line 2020, 330, 149–163. [Google Scholar] [CrossRef]
Nielsen, O.B. A comprehensive review of data governance literature. Sel. Pap. IRIS 2017, 8, 120–133. [Google Scholar]
Available online: http://www.datascienceassn.org/code-of-conduct.html (accessed on 27 February 2023).
Available online: https://chat.openai.com (accessed on 27 February 2023).
Ruby, M. How ChatGPT Works: The Model behind the Bot. Towards Data Science. 2023. Available online: https://towardsdatascience.com/how-chatgpt-works-the-models-behind-the-bot-1ce5fca96286 (accessed on 17 February 2023).
Chow, A.R.; Perrigo, B. The AI Arms Race Is Changing Everything. TIME Magazine. Available online: https://time.com/6255952/ai-impact-chatgpt-microsoft-google/ (accessed on 17 February 2023).
Thorp, H.H. ChatGPT is fun, but not an author. Science 2023, 379, 313. [Google Scholar] [CrossRef] [PubMed]
