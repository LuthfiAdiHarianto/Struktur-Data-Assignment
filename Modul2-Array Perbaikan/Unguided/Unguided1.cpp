#include <iostream>

using namespace std;

int main() {
  // Deklarasi variabel
  int data[10];
  int i, n, genap, ganjil;

  // Meminta input dari user
  cout << "Masukkan jumlah data: ";
  cin >> n;

  cout << "Masukkan data: ";
  for (i = 0; i < n; i++) {
    cin >> data[i];
  }

  // Menampilkan data array
  cout << "\nData Array: ";
  for (i = 0; i < n; i++) {
    cout << data[i] << " ";
  }

  // Menghitung jumlah nomor genap dan ganjil
  genap = 0;
  ganjil = 0;
  for (i = 0; i < n; i++) {
    if (data[i] % 2 == 0) {
      genap++;
    } else {
      ganjil++;
    }
  }

  // Menampilkan nomor genap dan ganjil
  cout << "\nNomor Genap:\n";
  for (i = 0; i < n; i++) {
    if (data[i] % 2 == 0) {
      cout << data[i] << " ";
    }
  }

  cout << "\nNomor Ganjil:\n";
  for (i = 0; i < n; i++) {
    if (data[i] % 2 != 0) {
      cout << data[i] << " ";
    }
  }

  return 0;
}
