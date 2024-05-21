#include <iostream>
using namespace std;

int main() {
    // Data yang diberikan
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]); // Ukuran array data
    int target = 4; // Angka yang ingin dihitung kemunculannya
    int count = 0; // Variabel untuk menyimpan jumlah kemunculan angka 4

    // Algoritma Sequential Search
    for (int i = 0; i < size; ++i) {
        if (data[i] == target) {
            ++count;
        }
    }

    // Menampilkan hasil
    cout << "Jumlah angka " << target << " dalam data adalah: " << count << endl;

    return 0;
}
