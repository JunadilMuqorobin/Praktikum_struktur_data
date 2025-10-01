#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "Masukkan dua bilangan float: ";
    cin >> a >> b;

    cout << "Penjumlahan       : " << (a + b) << endl;
    cout << "Pengurangan a - b : " << (a - b) << endl;
    cout << "Pengurangan b - a : " << (b - a) << endl;
    cout << "Perkalian         : " << (a * b) << endl;

    if (b != 0)
        cout << "Pembagian a / b   : " << (a / b) << endl;
    else
        cout << "Pembagian a / b   : Tidak valid (b = 0)\n";

    if (a != 0)
        cout << "Pembagian b / a   : " << (b / a) << endl;
    else
        cout << "Pembagian b / a   : Tidak valid (a = 0)\n";

    return 0;
}
