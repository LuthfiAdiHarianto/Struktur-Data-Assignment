#include <iostream>
#include <stack>

using namespace std;

bool isPalindrome(string kalimat) {
  // Buat stack untuk menyimpan karakter kalimat
  stack<char> s;

  // Masukkan karakter kalimat ke dalam stack
  for (char c : kalimat) {
    s.push(c);
  }

  // Bandingkan karakter dari depan dan belakang kalimat
  string terbalik;
  while (!s.empty()) {
    terbalik += s.top();
    s.pop();
  }

  return kalimat == terbalik;
}

int main() {
  // Deklarasikan variabel untuk menyimpan kalimat
  string kalimat;

  // Minta pengguna untuk memasukkan kalimat
  cout << "Masukkan kalimat: ";
  cin >> kalimat;

  // Ubah semua huruf menjadi huruf kecil
  for (int i = 0; i < kalimat.size(); i++) {
    kalimat[i] = tolower(kalimat[i]);
  }

  // Periksa apakah kalimat palindrom
  if (isPalindrome(kalimat)) {
    cout << kalimat << " adalah kalimat palindrom" << endl;
  } else {
    cout << kalimat << " bukan kalimat palindrom" << endl;
  }

  return 0;
}
