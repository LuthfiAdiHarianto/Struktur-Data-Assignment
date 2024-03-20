// coding by Luthfi Adi Harianto 
// NIM : 2311102172
// Kelas : IF11E
#include <iostream>
using namespace std;

int main() {
  int n;

  // Input jumlah elemen array
  cout << "Masukkan jumlah elemen array: ";
  cin >> n;

  // Deklarasi array
  int arr[n];

  // Input nilai elemen array
  for (int i = 0; i < n; i++) {
    cout << "Masukkan nilai array[" << i << "]: ";
    cin >> arr[i];
  }

  // Mencari nilai maksimum
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  // Mencari nilai minimum
  int min = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  // Menghitung nilai rata-rata
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  float avg = (float)sum / n;

  // Menampilkan hasil
  cout << endl << "Nilai maksimum: " << max << endl;
  cout << "Nilai minimum: " << min << endl;
  cout << "Nilai rata-rata: " << avg << endl;

  return 0;
}