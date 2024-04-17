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
