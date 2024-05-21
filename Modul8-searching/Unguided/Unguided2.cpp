#include <iostream>
#include <string>

using namespace std;

int main() {
  // Deklarasi variabel
  string kalimat;
  int jumlahVokal = 0;

  // Input kalimat
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  // Hitung jumlah vokal
  for (char huruf : kalimat) {
    if (huruf == 'a' || huruf == 'A' ||
        huruf == 'i' || huruf == 'I' ||
        huruf == 'u' || huruf == 'U' ||
        huruf == 'e' || huruf == 'E' ||
        huruf == 'o' || huruf == 'O') {
      jumlahVokal++;
    }
  }

  // Tampilkan hasil
  cout << "Jumlah huruf vokal dalam kalimat: " << jumlahVokal << endl;

  return 0;
}
