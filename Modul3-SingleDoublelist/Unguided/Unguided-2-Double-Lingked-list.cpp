// Coding by Luthfi Adi Harianto 2311102172 IF 11 E
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