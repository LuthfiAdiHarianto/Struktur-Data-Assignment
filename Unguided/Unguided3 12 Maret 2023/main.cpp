/*
oleh Luthfi Adi Harianto - 2311102172
*/

// Contoh Program Fungsi Map
#include <iostream>
#include <map> // Library supaya bisa menggunakan fungsi map dibawah

using namespace std;

int main() {

    // Deklarasi map dengan key int dan value string
    map<int, string> food_172;

    // Menambahkan elemen-elemen ke dalam map
    food_172[1] = "Fried Rice";
    food_172[2] = "Fried Chicken";
    food_172[3] = "Rice Gandul";
    food_172[4] = "Omelet";
    food_172[5] = "Ramen";

    cout << "-=-= Welcome to Luthfi's Food Menu! =-=-" << endl;
    for (int i = 1; i <= food_172.size(); ++i) { // Looping untuk menampilkan semua elemen map
        cout << "No." << i << " " << food_172[i] << endl; // Menampilkan elemen map
    }

    return 0;
}
