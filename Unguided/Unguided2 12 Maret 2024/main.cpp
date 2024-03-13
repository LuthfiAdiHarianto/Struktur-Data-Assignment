/*
oleh Luthfi ADi Harianto - 2311102172
*/

// Contoh Program Struct dan Class
#include <iostream>

using namespace std;

// Struct Person_172 yang berisi data nama string dan umur int
struct Person_172 {
    string Name_172;
    int Age_172;
};

// Class Vehicle_172 yang berisi data brand string, model string, dan tahun rilis int dalam akses public
class Vehicle_172 {
  public:
    string Brand_172;
    string Model_172;
    int YearReleased_172;
};

int main() {
    cout << "-=-= Declaration of Struct and Class by Luthfi Adi Harianto =-=-" << endl;

    // Deklarasi Struct Person_172
    Person_172 person{"Luthfi Adi Harianto", 18};
    cout << "\n- Biography - " << endl;
    cout << "Name: " << person.Name_172 << endl;
    cout << "Age: " << person.Age_172 << endl;

    // Deklarasi Class Vehicle_172
    Vehicle_172 vehicle;
    vehicle.Brand_172 = "Vario";
    vehicle.Model_172 = "K2743SG";
    vehicle.YearReleased_172 = 2013;
    cout << "\n- Luthfi's Vehicle -" << endl;
    cout << "Vehicle brand: " << vehicle.Brand_172 << endl;
    cout << "Vehicle model: " << vehicle.Model_172 << endl;
    cout << "Vehicle year released: " << vehicle.YearReleased_172 << endl;

    return 0;
}
