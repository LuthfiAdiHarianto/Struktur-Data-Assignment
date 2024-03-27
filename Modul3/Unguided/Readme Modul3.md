## Single Double Lingked List
## Coding by Luthfi Adi Harianto
## NIM 2311102172
## Kelas : IF 11 E



A.	Tujuan
1.	Mahasiswa memahami perbedaan konsep Single dan Double Linked List
2.	Mahasiswa mampu menerapkan Single dan Double Linked List ke dalam pemrograman

B.	Dasar Teori
a)	Single Linked List
Linked List merupakan suatu bentuk struktur data yang berisi kumpulan data yang disebut sebagai node yang tersusun secara sekuensial, saling sambung menyambung, dinamis, dan terbatas. Setiap elemen dalam linked list dihubungkan ke elemen lain melalui pointer. Masing-masing komponen sering disebut dengan simpul atau node atau verteks. Pointer adalah alamat elemen. Setiap simpul pada dasarnya dibagi atas dua bagian pertama disebut bagian isi atau informasi atau data yang berisi nilai yang disimpan oleh simpul. Bagian kedua disebut bagian pointer yang berisi alamat dari node berikutnya atau sebelumnya. Dengan menggunakan struktur seperti ini, linked list dibentuk dengan cara menunjuk pointer next suatu elemen ke elemen yang mengikutinya. Pointer next pada elemen terakhir merupakan NULL, yang menunjukkan akhir dari suatu list. Elemen pada awal suatu list disebut head dan elemen terakhir dari suatu list disebut tail.

 
Dalam operasi Single Linked List, umumnya dilakukan operasi penambahan dan penghapusan simpul pada awal atau akhir daftar, serta pencarian dan pengambilan nilai pada simpul tertentu dalam daftar. Karena struktur data ini hanya memerlukan satu pointer untuk setiap simpul, maka Single Linked List umumnya lebih efisien dalam penggunaan memori dibandingkan dengan jenis Linked List lainnya, seperti Double Linked List dan Circular Linked List.
Single linked list yang kedua adalah circular linked list. Perbedaan circular linked list dan non circular linked adalah penunjuk next pada node terakhir pada circular linked list akan selalu merujuk ke node pertama.




b)	Double Linked List

Double Linked List adalah struktur data Linked List yang mirip dengan Single Linked List, namun dengan tambahan satu pointer tambahan pada setiap simpul yaitu pointer prev yang menunjuk ke simpul sebelumnya. Dengan adanya pointer prev, Double Linked List memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul mana saja secara efisien. Setiap simpul pada Double Linked List memiliki tiga elemen penting, yaitu elemen data (biasanya berupa nilai), pointer next yang menunjuk ke simpul berikutnya, dan pointer prev yang menunjuk ke simpul sebelumnya.

Keuntungan dari Double Linked List adalah memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul dimana saja dengan efisien, sehingga sangat berguna dalam implementasi beberapa algoritma yang membutuhkan operasi tersebut. Selain itu, Double Linked List juga memungkinkan kita untuk melakukan traversal pada list baik dari depan (head) maupun dari belakang (tail) dengan mudah. Namun, kekurangan dari Double Linked List adalah penggunaan memori yang lebih besar dibandingkan dengan Single Linked List, karena setiap simpul membutuhkan satu pointer tambahan. Selain itu, Double Linked List juga membutuhkan waktu eksekusi yang lebih lama dalam operasi penambahan dan penghapusan jika dibandingkan dengan Single Linked List.
 
Representasi sebuah double linked list dapat dilihat pada gambar berikut ini:




Di dalam sebuah linked list, ada 2 pointer yang menjadi penunjuk utama, yakni pointer HEAD yang menunjuk pada node pertama di dalam linked list itu sendiri dan pointer TAIL yang menunjuk pada node paling akhir di dalam linked list. Sebuah linked list dikatakan kosong apabila isi pointer head adalah NULL. Selain itu, nilai pointer prev dari HEAD selalu NULL, karena merupakan data pertama. Begitu pula dengan pointer next dari TAIL yang selalu bernilai NULL sebagai penanda data terakhir.



## Guided
a)	Latihan Single Linked List Source Code
 ``` C++
 #include <iostream> using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node struct Node{
//komponen/member int data;
Node *next;
};
Node *head;
Node *tail;
//Inisialisasi Node void init(){
head = NULL; tail = NULL;
}
// Pengecekan bool isEmpty(){
if (head == NULL) return true;
else
return false;
}
//Tambah Depan
void insertDepan(int nilai){
//Buat Node baru
Node *baru = new Node; baru->data = nilai; baru->next = NULL;
if (isEmpty() == true){ head = tail = baru;
tail->next = NULL;

}
else{
baru->next = head; head = baru;
}
}
//Tambah Belakang
void insertBelakang(int nilai){
//Buat Node baru
Node *baru = new Node; baru->data = nilai; baru->next = NULL;
if (isEmpty() == true){ head = tail = baru; tail->next = NULL;
}
else{
tail->next = baru; tail = baru;
}
}
//Hitung Jumlah List int hitungList(){
Node *hitung; hitung = head; int jumlah = 0;
while( hitung != NULL ){ jumlah++;
hitung = hitung->next;
}
return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
if( posisi < 1 || posisi > hitungList() ){ cout << "Posisi diluar jangkauan" << endl;
 
}
else if( posisi == 1){
cout << "Posisi bukan posisi tengah" <<
endl;
}
else{
Node *baru, *bantu; baru = new Node(); baru->data = data;
// tranversing bantu = head; int nomor = 1;
while( nomor < posisi - 1 ){ bantu = bantu->next; nomor++;
}
baru->next = bantu->next; bantu->next = baru;
}
}
//Hapus Depan
void hapusDepan() { Node *hapus;
if (isEmpty() == false){
if (head->next != NULL){ hapus = head;
head = head->next; delete hapus;
}
else{
head = tail = NULL;
}
}
else{
cout << "List kosong!" << endl;
}
}
 
//Hapus Belakang
void hapusBelakang() { Node *hapus;
Node *bantu;
if (isEmpty() == false){ if (head != tail){
hapus = tail; bantu = head;
while (bantu->next != tail){ bantu = bantu->next;
}
tail = bantu;
tail->next = NULL; delete hapus;
}
else{
head = tail = NULL;
}
}
else{
cout << "List kosong!" << endl;
}
}
//Hapus Tengah
void hapusTengah(int posisi){ Node *hapus, *bantu, *bantu2;
if( posisi < 1 || posisi > hitungList() ){
cout << "Posisi di luar jangkauan" << endl;
}
else if( posisi == 1){
cout << "Posisi bukan posisi tengah" <<
endl;
}
else{
int nomor = 1; bantu = head;
while( nomor <= posisi ){
 
if( nomor == posisi-1 ){ bantu2 = bantu;
}
if( nomor == posisi ){ hapus = bantu;
}
bantu = bantu->next; nomor++;
}
bantu2->next = bantu; delete hapus;
}
}
//Ubah Depan
void ubahDepan(int data){
if (isEmpty() == false){ head->data = data;
}
else{
cout << "List masih kosong!" << endl;
}
}
//Ubah Tengah
void ubahTengah(int data, int posisi){ Node *bantu;
if (isEmpty() == false){
if( posisi < 1 || posisi > hitungList() ){ cout << "Posisi di luar jangkauan" <<
 
endl;
endl;
}
else if( posisi == 1){
cout << "Posisi bukan posisi tengah" <<
}
else{
bantu = head; int nomor = 1;
while (nomor < posisi){
bantu = bantu->next;nomor++;
}
bantu->data = data;
}
}
else{
cout << "List masih kosong!" << endl;
}
}
//Ubah Belakang
void ubahBelakang(int data){ if (isEmpty() == false){
tail->data = data;
}
else{
cout << "List masih kosong!" << endl;
}
}
//Hapus List
void clearList(){
Node *bantu, *hapus; bantu = head;
while (bantu != NULL){ hapus = bantu;
bantu = bantu->next; delete hapus;
}
head = tail = NULL;
cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List void tampil(){
Node *bantu; bantu = head;
if (isEmpty() == false){
 
while (bantu != NULL){
cout << bantu->data << ends; bantu = bantu->next;
}
cout << endl;
}
else{
cout << "List masih kosong!" << endl;
}
}
int main(){
init(); insertDepan(3);tampil(); insertBelakang(5); tampil(); insertDepan(2); tampil(); insertDepan(1); tampil();
hapusDepan(); tampil(); hapusBelakang(); tampil(); insertTengah(7,2); tampil(); hapusTengah(2); tampil(); ubahDepan(1); tampil(); ubahBelakang(8); tampil(); ubahTengah(11, 2); tampil();
return 0;
}
```
![alt text](<Screenshot 2024-03-25 115937-1.png>) </br>
kode diatas digunakan untuk menampilkan nilai angka secara 3, 35, 235, 1235, 235, 23, 273, 23, 13, 18, 111

b)	Latihan Double Linked List Source Code
```C++ 

#include <iostream> using namespace std;

class Node {
public:int data; Node* prev; Node* next;
};
class DoublyLinkedList { public:
Node* head; Node* tail;
DoublyLinkedList() { head = nullptr; tail = nullptr;
}
void push(int data) {
Node* newNode = new Node; newNode->data = data; newNode->prev = nullptr; newNode->next = head;
if (head != nullptr) { head->prev = newNode;
}
else {
tail = newNode;
}
head = newNode;
}
void pop() {
if (head == nullptr) { return;
}
Node* temp = head; head = head->next;
if (head != nullptr) { head->prev = nullptr;
}
else {
tail = nullptr;
}
delete temp;
}
bool update(int oldData, int newData) {
Node* current = head;while (current != nullptr) { if (current->data == oldData) {
current->data = newData; return true;
}
current = current->next;
}
return false;
}
void deleteAll() {
Node* current = head;
while (current != nullptr) { Node* temp = current; current = current->next; delete temp;
}
head = nullptr; tail = nullptr;
}
void display() {
Node* current = head;
while (current != nullptr) { cout << current->data << " "; current = current->next;
}
cout << endl;
}
};

int main() {
DoublyLinkedList list; while (true) {
cout << "1. Add data" << endl; cout << "2. Delete data" << endl; cout << "3. Update data" << endl; cout << "4. Clear data" << endl; cout << "5. Display data" << endl;
cout << "6. Exit" << endl;int choice; cout << "Enter your choice: ";
cin >> choice; switch (choice) {
case 1: {
int data;
cout << "Enter data to add: "; cin >> data;
list.push(data); break;
}
case 2: {
list.pop(); break;
newData);
}
case 3: {
int oldData, newData;
cout << "Enter old data: "; cin >> oldData;
cout << "Enter new data: "; cin >> newData;
bool updated = list.update(oldData,

if (!updated) {
cout << "Data not found" << endl;
 
}
break;
}
case 4: {
list.deleteAll(); break;
}
case 5: {
list.display(); break;
}
case 6: {
return 0;
}
default: {
cout << "Invalid choice" << endl; break;
}
}
}
return 0;
}
```
![alt text](<Screenshot 2024-03-25 120128-1.png>)</br>
![alt text](<Screenshot 2024-03-25 120229-1.png>)</br>
![alt text](<Screenshot 2024-03-25 120249-1.png>)</br>
![alt text](<Screenshot 2024-03-25 120314-1.png>)</br>
kode diatas digunakan untuk menambah data , menghapus data, edit data yang sudah diinputkan

## Unguided
1.	Soal mengenai Single Linked List

``` C++
#include <iostream>

using namespace std;

struct Node {
  string nama;
  int usia;
  Node* next;
};

Node* head = NULL;

// Menambahkan data di awal linked list
void insertAwal(string nama, int usia) {
  Node* baru = new Node;
  baru->nama = nama;
  baru->usia = usia;
  baru->next = head;
  head = baru;
}

// Menambahkan data di akhir linked list
void insertAkhir(string nama, int usia) {
  Node* baru = new Node;
  baru->nama = nama;
  baru->usia = usia;
  baru->next = NULL;

  if (head == NULL) {
    head = baru;
  } else {
    Node* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = baru;
  }
}

// Menambahkan data di tengah linked list setelah node dengan nama tertentu
void insertTengah(string namaSebelum, string nama, int usia) {
  Node* baru = new Node;
  baru->nama = nama;
  baru->usia = usia;

  Node* temp = head;
  while (temp->next != NULL && temp->nama != namaSebelum) {
    temp = temp->next;
  }

  if (temp->nama == namaSebelum) {
    baru->next = temp->next;
    temp->next = baru;
  } else {
    cout << "Data dengan nama " << namaSebelum << " tidak ditemukan!" << endl;
  }
}

// Menghapus data dengan nama tertentu
void hapusData(string nama) {
  Node* temp = head;
  Node* prev = NULL;

  while (temp != NULL && temp->nama != nama) {
    prev = temp;
    temp = temp->next;
  }

  if (temp != NULL) {
    if (prev == NULL) {
      head = head->next;
    } else {
      prev->next = temp->next;
    }
    delete temp;
  } else {
    cout << "Data dengan nama " << nama << " tidak ditemukan!" << endl;
  }
}

// Mengubah data dengan nama tertentu
void ubahData(string nama, string namaBaru, int usiaBaru) {
  Node* temp = head;

  while (temp != NULL && temp->nama != nama) {
    temp = temp->next;
  }

  if (temp != NULL) {
    temp->nama = namaBaru;
    temp->usia = usiaBaru;
  } else {
    cout << "Data dengan nama " << nama << " tidak ditemukan!" << endl;
  }
}

// Menampilkan seluruh data
void tampilData() {
  Node* temp = head;

  while (temp != NULL) {
    cout << temp->nama << " " << temp->usia << endl;
    temp = temp->next;
  }
}

int main() {
  // Masukkan data sesuai urutan
  insertAwal("Luthfi", 18);
  insertAkhir("John", 19);
  insertAkhir("Jane", 20);
  insertAkhir("Michael", 18);
  insertAkhir("Yusuke", 19);
  insertAkhir("Akechi", 20);
  insertAkhir("Hoshino", 18);
  insertAkhir("Karin", 18);

  // Hapus data Akechi
  hapusData("Akechi");

  // Tambahkan data Futaba diantara John dan Jane
  insertTengah("John", "Futaba", 18);

  //Tambahkan data Igor diantara Luthfi dan John
  insertTengah("Luthfi","Igor", 20);

  // Ubah data Michael menjadi Reyn
  ubahData("Michael", "Reyn", 18);

  // Tampilkan seluruh data
  tampilData();

  return 0;
}
```
![alt text](<Screenshot 2024-03-25 122210-1.png>)</br>
Kode diatas digunakan untuk menginputkan beberapa nama untuk dimasukkan ke dalam list selain itu bisa digunakan untuk mengubah data nama atau pun menambahkan nama di ditengah menggunakan insertTengah

2.	Soal mengenai Double Linked List


``` C++
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

// Fungsi untuk menambahkan node di awal
void push(Node** head_ref, string new_namaProduk, int new_harga) {
    Node* new_node = new Node();
    new_node->namaProduk = new_namaProduk;
    new_node->harga = new_harga;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

// Fungsi untuk menambahkan node setelah node tertentu
void insertAfter(Node* prev_node, string new_namaProduk, int new_harga) {
    if (prev_node == NULL) {
        cout << "Node sebelumnya tidak boleh NULL\n";
        return;
    }
    Node* new_node = new Node();
    new_node->namaProduk = new_namaProduk;
    new_node->harga = new_harga;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    prev_node->next = new_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

// Fungsi untuk menambahkan node di akhir
void append(Node** head_ref, string new_namaProduk, int new_harga) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->namaProduk = new_namaProduk;
    new_node->harga = new_harga;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

// Fungsi untuk menghapus node
void deleteNode(Node** head_ref, Node* del) {
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    delete del;
}

// Fungsi untuk mengupdate node
void updateNode(Node* node, string new_namaProduk, int new_harga) {
    if (node == NULL) {
        cout << "Node yang akan diupdate tidak boleh NULL\n";
        return;
    }
    node->namaProduk = new_namaProduk;
    node->harga = new_harga;
}

// Fungsi untuk mencetak isi linked list
void printList(Node* node) {
    Node* last;
    cout << "Toko Luthfi Adi Harianto Skincare Purwokerto\n";
    cout << "Nama Produk\tHarga\n";
    while (node != NULL) {
        cout << node->namaProduk << "\t" << node->harga << "\n";
        last = node;
        node = node->next;
    }
}

// Fungsi untuk mendapatkan node ke-n
Node* getNode(Node* head, int n) {
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == n)
            return current;
        count++;
        current = current->next;
    }
    return NULL;
}

int main() {
    Node* head = NULL;
    append(&head, "Originote", 60000);
    append(&head, "Somethinc", 150000);
    append(&head, "Skintific", 100000);
    append(&head, "Wardah", 50000);
    append(&head, "Hanasui", 30000);

    int choice, harga, pos;
    string namaProduk;
    Node* temp;

    do {
        cout << "\nToko Luthfi Adi Harianto Skincare Purwokerto\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Update Data\n";
        cout << "4. Tambah Data Urutan Tertentu\n";
        cout << "5. Hapus Data Urutan Tertentu\n";
        cout << "6. Hapus Seluruh Data\n";
        cout << "7. Tampilkan Data\n";
        cout << "8. Exit\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                append(&head, namaProduk, harga);
                break;
            case 2:
                cout << "Masukkan nama produk yang akan dihapus: ";
                cin >> namaProduk;
                temp = head;
                while (temp != NULL && temp->namaProduk != namaProduk)
                    temp = temp->next;
                if (temp != NULL)
                    deleteNode(&head, temp);
                else
                    cout << "Produk tidak ditemukan\n";
                break;
            case 3:
                cout << "Masukkan nama produk yang akan diupdate: ";
                cin >> namaProduk;
                temp = head;
                while (temp != NULL && temp->namaProduk != namaProduk)
                    temp = temp->next;
                if (temp != NULL) {
                    cout << "Masukkan nama produk baru: ";
                    cin >> namaProduk;
                    cout << "Masukkan harga baru: ";
                    cin >> harga;
                    updateNode(temp, namaProduk, harga);
                } else
                    cout << "Produk tidak ditemukan\n";
                break;
            case 4:
                cout << "Masukkan posisi setelah produk mana Anda ingin menambahkan (0 untuk awal): ";
                cin >> pos;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                if (pos == 0)
                    push(&head, namaProduk, harga);
                else {
                    temp = getNode(head, pos - 1);
                    if (temp != NULL)
                        insertAfter(temp, namaProduk, harga);
                    else
                        cout << "Posisi tidak valid\n";
                }
                break;
            case 5:
                cout << "Masukkan posisi produk yang akan dihapus: ";
                cin >> pos;
                temp = getNode(head, pos);
                if (temp != NULL)
                    deleteNode(&head, temp);
                else
                    cout << "Posisi tidak valid\n";
                break;
            case 6:
                while (head != NULL)
                    deleteNode(&head, head);
                break;
            case 7:
                printList(head);
                break;
            case 8:
                cout << "Terima kasih telah menggunakan program ini\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (choice != 8);

    return 0;
}
```
![alt text](<Screenshot 2024-03-25 123613-1.png>)</br>
![alt text](<Screenshot 2024-03-27 173412-1.png>)</br>
![alt text](<Screenshot 2024-03-27 173553-1.png>)</br>
![alt text](<Screenshot 2024-03-27 173652-1.png>)</br>
![alt text](<Screenshot 2024-03-27 173801-1.png>)</br>
![alt text](<Screenshot 2024-03-27 173833-1.png>)</br>
Kode diatas digunakan untuk membuat sebuah toko kecantikan di daerah purwokerto dengan customer request program nama tokonya yaitu Toko Luthfi Adi Harianto Skincare Purwokerto dengan menggunakan double lingked list kita bisa menambahkan mengubah maupun mengupdate data produk yang akan kita jual

## Kesimpulan
dengan menggunakan single double lingked list kita dapat mempermudah update data yang kita inginkan entah itu menambah, menghapus, mengubah nama data tersebut dapat dilakukan dengan mudah.

## Referensi
(1) Herlihy, M., Luchangco, V., Moir, M.: Obstruction-free synchronization: Double-ended queues as an example. In: Proceedings of the 23rd International Conference on Distributed Computing Systems (2003)

(2) Sundell, H., Tsigas, P.: Lock-free and practical deques using single-word compare-and-swap. Technical Report 2004-02, Computing Science, Chalmers University of Technology (2004)

