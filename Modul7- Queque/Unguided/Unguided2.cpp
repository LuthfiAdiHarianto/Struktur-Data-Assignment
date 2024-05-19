#include <iostream>
using namespace std;
// membuat struktur struct mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
};

struct Node {
    Mahasiswa data;
    Node* next;
};
// Deklarasi Pointer
Node* front = NULL;
Node* back = NULL;

// memeriksa antrian kosong atau tidak
bool isEmpty() {
    return (front == NULL);
}
// memasukkan nama dan nim yang kita inginkan
void enqueueAntrian(Mahasiswa data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(front == NULL && back == NULL){
        front = back = temp;
        return;
    }
    back->next = temp;
    back = temp;
}
// menghapus nama dan nim paling atas dari list yang sudah dibuat
void dequeueAntrian() {
    Node* temp = front;
    if(front == NULL) {
        cout << "Antrian kosong" << endl;
        return;
    }
    if(front == back) {
        front = back = NULL;
    }
    else {
        front = front->next;
    }
    delete temp;
}
// menghitung jumlah elemen antrian
int countQueue() {
    Node* temp = front;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
// menghapus list mahasiswa
void clearQueue() {
    Node* current = front;
    Node* next;
 
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    front = back = NULL;
}
// melihat list mahasiswa yang sudah dibuat
void viewQueue() {
    Node* temp = front;
    cout << "Data antrian mahasiswa:" << endl;
    int i = 1;
    while(temp!=NULL) {
        cout << i << ". Nama: " << temp->data.nama << ", NIM: " << temp->data.nim << endl;
        temp = temp->next;
        i++;
    }
}
// program utama
int main() {
    Mahasiswa mhs1 = {"Andi", "123456"};
    Mahasiswa mhs2 = {"Maya", "654321"};
    enqueueAntrian(mhs1);
    enqueueAntrian(mhs2);
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
