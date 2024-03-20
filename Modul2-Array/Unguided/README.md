## dasar teori
    Array merupakan struktur data yang paling dasar. Sebelum mempelajari struktur data
lainnya, alangkah baiknya, kita perlu mempelajari Array terlebih dahulu. Berikut ini
adalah beberapa jenis array :
    1) Array Satu Dimensi
Array satu dimensi adalah tipe variabel yang terdiri dari kumpulan data
dengan tipe yang sama yang disusun dalam satu baris atau satu dimensi. Setiap
elemen di dalam array memiliki sebuah indeks atau nomor yang digunakan
untuk mengakses elemen tersebut. Indeks dimulai dari 0 dan berakhir pada
jumlah elemen dikurangi satu.
Contohnya : sebuah array satu dimensi yang berisi bilangan bulat {1, 2,
3, 4, 5} memiliki lima elemen dan indeksnya dimulai dari 0. Indeks 0 merujuk
pada elemen pertama, indeks 1 merujuk pada elemen kedua, dan seterusnya
hingga indeks 4 merujuk pada elemen kelima.
Contoh :
#include <iostream>
using namespace std;
int main() {
    int arr[5] = {9, 3, 5, 2, 1}; //deklarasi array
    cout<< arr[1] << endl;
    cout<< arr[4];
}
Output : 
3 
1

    2) Array Dua Dimensi
Array dua dimensi adalah variable yang terdiri dari kumpulan array
satu dimensi dengan tipe yang sama yang disusun dalam baris dan kolom.
Dalam array dua dimensi, setiap elemen memiliki dua indeks, yaitu indeks
baris dan indeks kolom. Indeks baris menunjukkan posisi elemen dalam baris,
sementara indeks kolom menunjukkan posisi elemen dalam kolom.
Contoh :
#include <iostream>
using namespace std;
int main() {
    int arr[2][2] = {{3, 2}, {2, 5}};
    for (int i=0; i<2; i++) { //baris
    for(int j=0; j<2; j++) { //kolom
    cout<< arr[i][j] << ends;
    };
    cout << endl;
    };
    }
Output :
3 2
2 5

        3) Array Multidimensi
    Array multidimensi memiliki kesamaan dengan array satu dimensi dan
dua dimensi, namun memiliki kapasitas memori yang lebih besar. Array ini
digunakan untuk merepresentasikan array dengan dimensi lebih dari dua atau
array yang memiliki lebih dari dua indeks, seperti array tiga dimensi, array
empat dimensi, array lima dimensi, dan seterusnya.
    Contoh :
#include <iostream>
using namespace std;
    int main() {
        int arr[2][2][3] = {{{2, 8, 7}, {6, 5, 1}}, {{8,
        5, 2}, {9, 2 ,7}}};
        for (int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
        for(int k=0; k<3; k++) {
            cout<< arr[i][j][k] << ends;
            };
        cout<< endl;
        };
        cout<< endl;
    };
}
Output :
2 8 7
6 5 1
8 5 2
9 2 7

4) Array Empat Dimensi
Contoh :
int arr [3][2][4][4];
5) Array Lima Dimensi
Contoh :
int arr [2][4][4][3][3];

## Guided
Guided 1
## Program Input Array Tiga Dimensi
#include <iostream>

using namespace std;

// program input array 3 dimensi
int main()
{
    // deklarasi array
    int arr[2][3][3];
    // input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "]= ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // output array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Array[" << x << "][" << y << "][" << z << "]: " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
```
![alt text](<Screenshot 2024-03-20 094034-1.png>) </br>
![alt text](<Screenshot 2024-03-20 094059-1.png>) </br>
Kode diatas digunakan untuk menginputkan nilai melalui array 3 dimensi dengan menggunakan konsep perulangan for

## Guided 2
### Program Mencari Nilai Maksimal pada Array

#include <iostream>

using namespace std;
int main(){
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >>a;
    int array[a];
    cout << "Masukkan "<< a << "angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" <<(i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i =0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah "<<maks << " berada di Array ke " << lokasi << endl;
}
```
![alt text](<Screenshot 2024-03-20 095133-1.png>) </br>
Kode diatas digunakan untuk mencari maksimum nilai pada array ke berapa menggunakan perulangan for

## Unguided
## Unguided 1
## Program menampilkan nilai ganjil dan genap menggunakan array
// coding by Luthfi Adi Harianto 
// NIM : 2311102172
// Kelas : IF11E
#include <iostream>

using namespace std;
int main() {
    //deklarasi array data dengan 10 elemen 1-10
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "Data array: ";
    for (int i = 0; i < 10; i ++){
        cout << data[i] << " ";
    }
    cout << endl << endl;
//menginputkan elemen data nomor genap 
    cout << "nomor genap: ";
    //menampilkan data array elemen nomor genap dari 1-10
    for (int i = 0; i < 10; i++){
        if (data [i] % 2 ==0){
            cout << data[i] << " ";
        }
    }
    cout << endl << endl;
//menginputkan elemen data nomor ganjil
    cout << "nomor ganjil: ";
    //menampilkan data array elemen nomor ganjil dari 1-10 menggunakan perulangan for
    for (int i =0; i < 10; i ++){
        if (data [i] %2 !=0){
            cout << data[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
```
![alt text](<Screenshot 2024-03-19 121318-1.png>) </br>
Kode diatas digunakan untuk menampilkan output(dihasilkan/dikeluarkan) yang diinputkan(dimasukkan) dari user 1,2,3,4,5,6,7,8,9,10 menghasilkan nomor genap 2,4,6,8,10 dan nomor ganjil 1,3,5,7,9

## Unguided 2
## Program Input array 3 dimensi
// coding by Luthfi Adi Harianto 
// NIM : 2311102172
// Kelas : IF11E
#include <iostream>
using namespace std;

int main() {
  int x, y, z;

  // Input jumlah elemen di setiap dimensi
  cout << "Masukkan jumlah elemen di dimensi X: ";
  cin >> x;
  cout << "Masukkan jumlah elemen di dimensi Y: ";
  cin >> y;
  cout << "Masukkan jumlah elemen di dimensi Z: ";
  cin >> z;

  // Deklarasi array tiga dimensi
  int array[x][y][z];

  // Input nilai elemen array
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < z; k++) {
        cout << "Masukkan nilai array[" << i << "][" << j << "][" << k << "]: ";
        cin >> array[i][j][k];
      }
    }
  }
![alt text](<Screenshot 2024-03-19 121528-1.png>) </br>
![alt text](<Screenshot 2024-03-19 121549-1.png>) </br>
  // Menampilkan elemen array
  cout << endl << "Elemen array:" << endl;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < z; k++) {
        cout << array[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
```
![alt text](<Screenshot 2024-03-19 121528-1.png>) </br>
![alt text](<Screenshot 2024-03-19 121549-1.png>) </br>
Kode diatas digunakan untuk menampilkan output array tiga dimensi dimana jumlah atau ukuran elemen diinput kan oleh user
## Unguided 3
## Program menuprogram menu untuk mencari nilai Maksimum, Minimum dan Nilai rata rata yang dimasukkan oleh user
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
```
![alt text](<Screenshot 2024-03-19 121858-1.png>) </br>
Kode diatas digunakan untuk menampilkan output nilai maksimum, minimum , dan nilai rata rata dari suatu array yang dimasukkan nilai terserah/bebas oleh user