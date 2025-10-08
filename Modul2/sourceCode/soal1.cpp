#include <iostream>
using namespace std;

int main() {
    const int MHS = 5;   
    const int MK = 3;    

    string nama[MHS];
    float nilai[MHS][MK];
    float rata[MHS];

    for (int i = 0; i < MHS; i++) {
        cout << "Nama mahasiswa ke-" << i+1 << ": ";
        cin >> nama[i];
        float total = 0;
        for (int j = 0; j < MK; j++) {
            cout << "  Nilai MK" << j+1 << ": ";
            cin >> nilai[i][j];
            total += nilai[i][j];
        }
        rata[i] = total / MK;
        cout << endl;
    }

    
    int terbaik = 0;
    for (int i = 1; i < MHS; i++) {
        if (rata[i] > rata[terbaik]) {
            terbaik = i;
        }
    }

    cout << "=====================================================" << endl;
    cout << "\n              Data Nilai Mahasiswa              \n";
    cout << "=====================================================" << endl;
    for (int i = 0; i < MHS; i++) {
        cout << nama[i] << " | ";
        for (int j = 0; j < MK; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << "| Rata-rata: " << rata[i];
        if (i == terbaik) cout << " <-- Terbaik";
        cout << endl;
    }
    cout << "=====================================================" << endl;
    cout << "\nMahasiswa terbaik : " << nama[terbaik] << ", dengan rata-rata " << rata[terbaik] << endl;

    return 0;
}
