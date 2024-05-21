#include <iostream>
#include <string>

using namespace std;

int binarySearch(string kalimat, char huruf, int bawah, int atas) {
  // Cek jika batas bawah lebih besar dari batas atas
  if (atas < bawah) {
    return -1;
  }

  // Hitung indeks tengah
  int tengah = bawah + (atas - bawah) / 2;

  // Bandingkan huruf pada indeks tengah dengan huruf yang dicari
  if (kalimat[tengah] == huruf) {
    return tengah;
  } else if (kalimat[tengah] < huruf) {
    return binarySearch(kalimat, huruf, tengah + 1, atas);
  } else {
    return binarySearch(kalimat, huruf, bawah, tengah - 1);
  }
}

int main() {
  // Deklarasi variabel
  string kalimat;
  char huruf;

  // Input kalimat dan huruf yang dicari
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);
  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> huruf;

  // Panggil fungsi binarySearch
  int index = binarySearch(kalimat, huruf, 0, kalimat.length() - 1);

  // Tampilkan hasil pencarian
  if (index != -1) {
    cout << "Huruf '" << huruf << "' ditemukan pada indeks " << index << endl;
  } else {
    cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat" << endl;
  }

  return 0;
}
