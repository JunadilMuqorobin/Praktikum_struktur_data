#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    Mahasiswa data[10];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> jumlah;

    if (jumlah > 10) jumlah = 10;

    cout << "\n=== Input Data Mahasiswa ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        inputMahasiswa(data[i]);
    }

    cout << "\n=== Daftar Nilai Mahasiswa ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1;
        tampilMahasiswa(data[i]);
    }

    return 0;
}
