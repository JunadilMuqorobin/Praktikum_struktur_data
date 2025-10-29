#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);
    kendaraan k;
    address P;

    cout << "masukkan nomor polisi: D001\n";
    cout << "masukkan warna kendaraan: hitam\n";
    cout << "masukkan tahun kendaraan: 90\n\n";
    k.nopol = "D001"; k.warna = "hitam"; k.thnBuat = 90;
    if (findElm(L, k.nopol) == Nil)
        insertLast(L, alokasi(k));
    else
        cout << "nomor polisi sudah terdaftar\n\n";

    cout << "masukkan nomor polisi: D003\n";
    cout << "masukkan warna kendaraan: putih\n";
    cout << "masukkan tahun kendaraan: 70\n\n";
    k.nopol = "D003"; k.warna = "putih"; k.thnBuat = 70;
    if (findElm(L, k.nopol) == Nil)
        insertLast(L, alokasi(k));
    else
        cout << "nomor polisi sudah terdaftar\n\n";

    cout << "masukkan nomor polisi: D001\n";
    cout << "masukkan warna kendaraan: merah\n";
    cout << "masukkan tahun kendaraan: 80\n";
    if (findElm(L, "D001") == Nil)
        insertLast(L, alokasi(k));
    else
        cout << "nomor polisi sudah terdaftar\n\n";

    cout << "masukkan nomor polisi: D004\n";
    cout << "masukkan warna kendaraan: kuning\n";
    cout << "masukkan tahun kendaraan: 90\n\n";
    k.nopol = "D004"; k.warna = "kuning"; k.thnBuat = 90;
    if (findElm(L, k.nopol) == Nil)
        insertLast(L, alokasi(k));
    else
        cout << "nomor polisi sudah terdaftar\n\n";

    printInfo(L);

    cout << "Masukkan Nomor Polisi yang dicari : D001\n";
    address Q = findElm(L, "D001");
    if (Q != Nil) {
        cout << "\nNomor Polisi : " << Q->info.nopol << endl;
        cout << "Warna        : " << Q->info.warna << endl;
        cout << "Tahun        : " << Q->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    cout << "\nMasukkan Nomor Polisi yang akan dihapus : D003\n";
    Q = findElm(L, "D003");
    if (Q != Nil) {
        cout << "Data dengan nomor polisi D003 berhasil dihapus.\n";
        address removed = Nil;
        if (Q == L.first)
            deleteFirst(L, removed);
        else if (Q == L.last)
            deleteLast(L, removed);
        else
            deleteAfter(L, Q->prev, removed);
        dealokasi(removed);
    } else {
        cout << "Data tidak ditemukan.\n";
    }
    printInfo(L);

    return 0;
}
