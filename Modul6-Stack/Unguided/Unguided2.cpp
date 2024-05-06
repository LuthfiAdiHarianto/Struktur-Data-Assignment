#include <iostream>
#include <stack>

using namespace std;

int main() {
  // Deklarasi variabel
  string kalimat;
  stack<char> tumpukan;

  // Meminta input kalimat
  cout << "Masukkan kalimat (minimal 3 kata): ";
  getline(cin, kalimat);

  // Memeriksa panjang kalimat
  if (kalimat.length() < 3) {
    cout << "Kalimat minimal harus 3 kata!" << endl;
    return 1;
  }

  // Memasukkan karakter kalimat ke stack
  for (char c : kalimat) {
    tumpukan.push(c);
  }

  // Mengeluarkan karakter dari stack dan membentuk kalimat terbalik
  kalimat = "";
  while (!tumpukan.empty()) {
    kalimat += tumpukan.top();
    tumpukan.pop();
  }

  // Menampilkan kalimat terbalik
  cout << "Kalimat terbalik: " << kalimat << endl;

  return 0;
}
