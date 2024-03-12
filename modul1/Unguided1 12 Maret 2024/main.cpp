/*
oleh Luthfi Adi Harianto - 2311102172
*/

#include <iostream>
#include <cmath> // Library untuk fungsi pemangkatan dibawah

using namespace std;

char Choice_172; // Data primitif char untuk pilihan menu Choice_172
float One_172, Two_172; // Data primitif float untuk bilangan pertama dan kedua supaya bisa menyimpan bilangan desimal

void LuthfiProgramStart_172() { // Fungsi untuk menampilkan menu pilihan
    cout << "KALKULATOR Luthfi";
    cout << "\nA. Penjumlahan";
    cout << "\nB. Perkalian";
    cout << "\nC. Pembagian";
    cout << "\nD. Pengurangan";
    cout << "\nE. Pangkat" << endl;
    cout << "Masukkan Pilihan : ";
    cin >> Choice_172;
}

float AdditionLogic_172() { // Fungsi Penjumlahan
    cout << "\n--- PENJUMLAHAN ---" << endl;
    cout << "Bilangan pertama : ";
    cin >> One_172;
    cout << "Ditambah bilangan kedua : ";
    cin >> Two_172;
    cout << "Hasil penjumlahan : ";
    return One_172 + Two_172; // Mengembalikan hasil penjumlahan
}

float MultiplicationLogic_172() { // Fungsi Perkalian
    cout << "\n--- PERKALIAN ---" << endl;
    cout << "Bilangan pertama : ";
    cin >> One_172;
    cout << "Dikali bilangan kedua : ";
    cin >> Two_172;
    cout << "Hasil perkalian : ";
    return One_172 * Two_172; // Mengembalikan hasil perkalian
}

float DivisionLogic_172() { // Fungsi Pembagian
    cout << "\n--- PEMBAGIAN ---" << endl;
    cout << "Bilangan pertama : ";
    cin >> One_172;
    cout << "Dibagi bilangan kedua : ";
    cin >> Two_172;
    cout << "Hasil pembagian : ";
    return One_172 / Two_172; // Mengembalikan hasil pembagian
}

float SubtractionLogic_172() { // Fungsi Pengurangan
    cout << "\n--- PENGURANGAN ---" << endl;
    cout << "Bilangan pertama : ";
    cin >> One_172;
    cout << "Dikurangi bilangan kedua : ";
    cin >> Two_172;
    cout << "Hasil pengurangan : ";
    return One_172 - Two_172; // Mengembalikan hasil pengurangan
}

float SquaredLogic_172() { // Fungsi Pemangkatan
    cout << "\n--- PEMANGKATAN ---" << endl;
    cout << "Bilangan pertama : ";
    cin >> One_172;
    cout << "Dipangkati bilangan kedua : ";
    cin >> Two_172;
    cout << "Hasil pemangkatan : ";
    return pow(One_172, Two_172); // Mengembalikan hasil pemangkatan dan pow itu fungsi dari library cmath diatas
}

int main() {
    do { // Looping menu pilihan
        LuthfiProgramStart_172();
        switch (Choice_172) { // Switch case untuk memilih menu
            case 'A':
            case 'a':
                cout << AdditionLogic_172() << "\n" << endl; // Jika user memilih A/a, maka akan menjalankan fungsi penjumlahan
                break;
            case 'B':
            case 'b':
                cout << MultiplicationLogic_172() << "\n" << endl; // Jika user memilih B/b, maka akan menjalankan fungsi perkalian
                break;
            case 'C':
            case 'c':
                cout << DivisionLogic_172() << "\n" << endl; // Jika user memilih C/c, maka akan menjalankan fungsi pembagian
                break;
            case 'D':
            case 'd':
                cout << SubtractionLogic_172() << "\n" << endl; // Jika user memilih D/d, maka akan menjalankan fungsi pengurangan
                break;
            case 'E':
            case 'e':
                cout << SquaredLogic_172() << "\n" << endl; // Jika user memilih E/e, maka akan menjalankan fungsi pemangkatan
                break;
            default:
                cout << "\nUhh.. not a valid number so yea goodbye" << endl;
                return 0;
        }
    } while (Choice_172 != 0); // Looping akan terus berjalan selama user tidak memilih 0

    return 0;
}
