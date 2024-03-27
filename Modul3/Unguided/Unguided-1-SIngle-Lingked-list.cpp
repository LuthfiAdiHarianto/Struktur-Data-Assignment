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