#include <iostream>
using namespace std;

// membuat struktur struct
struct Node {
    string data;
    Node* next;
};
// Deklarasi pointer
Node* front = NULL;
Node* back = NULL;

// memeriksa antrian kosong atau tidak
bool isEmpty() {
    return (front == NULL);
}

// menambahkan antrian baru
void enqueueAntrian(string data) {
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
// menghapus antrian paling depan
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
// menghitung jumlah elemen dalam antrian
int countQueue() {
    Node* temp = front;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
// menghapus semua antrian
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
// melihat antrian yang sudah kita buat
void viewQueue() {
    Node* temp = front;
    cout << "Data antrian teller:" << endl;
    int i = 1;
    while(temp!=NULL) {
        cout << i << ". " << temp->data << endl;
        temp = temp->next;
        i++;
    }
}
// program utama
int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
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
