#include <iostream>

using namespace std;

int main() {
  int pilihan;
  float nilai[100];
  int n;

  // Meminta input jumlah elemen array
  cout << "Masukkan jumlah elemen array: ";
  cin >> n;

  // Meminta input nilai elemen array
  for (int i = 0; i < n; i++) {
    cout << "Masukkan nilai elemen ke-" << i + 1 << ": ";
    cin >> nilai[i];
  }

  do {
    cout << "\nMenu:" << endl;
    cout << "1. Tampilkan Nilai Maksimum" << endl;
    cout << "2. Tampilkan Nilai Minimum" << endl;
    cout << "3. Tampilkan Nilai Rata-rata" << endl;
    cout << "4. Keluar" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1: {
        float maks = nilai[0];
        for (int i = 1; i < n; i++) {
          if (nilai[i] > maks) {
            maks = nilai[i];
          }
        }
        cout << "Nilai Maksimum: " << maks << endl;
        break;
      }
      case 2: {
        float min = nilai[0];
        for (int i = 1; i < n; i++) {
          if (nilai[i] < min) {
            min = nilai[i];
          }
        }
        cout << "Nilai Minimum: " << min << endl;
        break;
      }
      case 3: {
        float total = 0;
        for (int i = 0; i < n; i++) {
          total += nilai[i];
        }
        float rataRata = total / n;
        cout << "Nilai Rata-rata: " << rataRata << endl;
        break;
      }
      case 4: {
        cout << "Keluar dari program" << endl;
        break;
      }
      default: {
        cout << "Pilihan tidak valid!" << endl;
      }
    }
  } while (pilihan != 4);

  return 0;
}
