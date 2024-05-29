#include <iostream>
#include <limits>

using namespace std;

int main() {
  int n_2311102172;
  cout << "Silakan masukan jumlah simpul: ";
  cin >> n_2311102172;

  // Inisialisasi array untuk menyimpan nama kota
  string kota[n_2311102172];
  cout << "Silakan masukan nama simpul\n";
  for (int i = 0; i < n_2311102172; i++) {
    cout << "Simpul " << i + 1 << ": ";
    cin >> kota[i];
  }

  // Inisialisasi array 2D untuk menyimpan bobot antar kota
  int graph[n_2311102172][n_2311102172];
  cout << "Silakan masukkan bobot antar simpul\n";
  for (int i = 0; i < n_2311102172; i++) {
    for (int j = 0; j < n_2311102172; j++) {
      cout << kota[i] << "--> " << kota[j] << " = ";
      cin >> graph[i][j];
    }
  }

  // Menampilkan matriks graph
  cout << "\n";
  cout << "  ";
  for (int i = 0; i < n_2311102172; i++) {
    cout << kota[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < n_2311102172; i++) {
    cout << kota[i] << " ";
    for (int j = 0; j < n_2311102172; j++) {
      cout << graph[i][j] << " ";
    }
    cout << "\n";
  }

  // Input kota asal dan tujuan
  int asal, tujuan;
  cout << "\n";
  cout << "Masukan kota asal (nomor simpul): ";
  while (!(cin >> asal) || asal < 1 || asal > n_2311102172) {
    cout << "Input tidak valid. Masukan nomor simpul yang benar: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  asal--; // Penyesuaian indeks array

  cout << "Masukan kota tujuan (nomor simpul): ";
  while (!(cin >> tujuan) || tujuan < 1 || tujuan > n_2311102172) {
    cout << "Input tidak valid. Masukan nomor simpul yang benar: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  tujuan--; // Penyesuaian indeks array

  // Menghitung jarak antar kota
  int jarak = graph[asal][tujuan];
  cout << "\nJarak dari " << kota[asal] << " ke " << kota[tujuan] << " adalah: " << jarak << endl;

  return 0;
}