#include <iostream>

using namespace std;

struct Mahasiswa
{
    string nama;
    string NIM;
};

int main() {
    Mahasiswa mhs;
    mhs.nama = "Juna";
    mhs.NIM = "103112400281";

    cout << "Nama : " << mhs.nama << endl << "NIM : " << mhs.NIM << endl;
    return 0;
}