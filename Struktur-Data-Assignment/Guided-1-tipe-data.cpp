#include <iostream>
using namespace std;
// main program
int main()
{
    char op;
    float num1, num2;
    // it allows to enter operator i,e,+-,-,#, /
    cin >> op;
    cin >> num1 >> num2;
    switch (op)
    {
    case '+':
        cout << num1 + num2;
        break;
    case '-':
        cout << num1 - num2;
        break;
    case '*':
        cout << num1 * num2;
        break;
    case '/':
        cout << num1 / num2;
        break;
    default:
        cout << "Eror! operator is not correct";
    }
    return 0;
}