#include <iostream>
#include "arrayDuaD.h"
using namespace std;

int main() {
    int arr1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int arr2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "=== Array 1 Sebelum Ditukar ===\n";
    tampilArray(arr1);

    cout << "\n=== Array 2 Sebelum Ditukar ===\n";
    tampilArray(arr2);

    tukarArray(arr1, arr2, 1, 1);

    cout << "\n=== Setelah Menukar Elemen (1,1) ===\n";
    cout << "Array 1:\n";
    tampilArray(arr1);

    cout << "\nArray 2:\n";
    tampilArray(arr2);

    int a = 10, b = 20;
    int *p1 = &a;
    int *p2 = &b;

    cout << "\nNilai sebelum ditukar melalui pointer:\n";
    cout << "a = " << a << ", b = " << b << endl;

    tukarPointer(p1, p2);

    cout << "Nilai setelah ditukar melalui pointer:\n";
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
