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