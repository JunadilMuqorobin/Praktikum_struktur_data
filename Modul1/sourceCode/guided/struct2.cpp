#include <iostream>

using namespace std;

struct Mahasiswa
{
    string nama;
    string NIM;
};

int main() {

    Mahasiswa mhs;
    cout << "Nama : ";
    getline(cin, mhs.nama);
    cout << "NIM  : ";
    cin >> mhs.NIM;

    cout << "Nama : " << mhs.nama << endl << "NIM : " << mhs.NIM << endl;
    return 0;
}