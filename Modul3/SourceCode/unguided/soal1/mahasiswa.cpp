#include "mahasiswa.h"
#include <iostream>
using namespace std;

void inputMahasiswa(Mahasiswa &m) {
    cout << "Masukkan Nama   : ";
    getline(cin >> ws, m.nama);
    cout << "Masukkan NIM    : ";
    cin >> m.nim;
    cout << "Masukkan Nilai UTS   : ";
    cin >> m.uts;
    cout << "Masukkan Nilai UAS   : ";
    cin >> m.uas;
    cout << "Masukkan Nilai Tugas : ";
    cin >> m.tugas;
    
    m.nilaiAkhir = hitungNilaiAkhir(m);
}

float hitungNilaiAkhir(Mahasiswa m) {
    return (0.3 * m.uts) + (0.4 * m.uas) + (0.3 * m.tugas);
}

void tampilMahasiswa(Mahasiswa m) {
    cout << "\nNama         : " << m.nama << endl;
    cout << "NIM          : " << m.nim << endl;
    cout << "UTS          : " << m.uts << endl;
    cout << "UAS          : " << m.uas << endl;
    cout << "Tugas        : " << m.tugas << endl;
    cout << "Nilai Akhir  : " << m.nilaiAkhir << endl;
}
