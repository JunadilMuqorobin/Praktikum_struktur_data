#include "Playlist.h"

int main() {
    Playlist L;
    createList(L);

    Lagu lagu1 = {"December", "Neck Deep", 3.4};
    Lagu lagu2 = {"Sinarengan", "Denny Caknan", 6.5};
    Lagu lagu3 = {"Rumah Ke Rumah", "Hindia", 5.1};
    Lagu lagu4 = {"Lantas", "Juicy Luicy", 4.0};
    Lagu lagu5 = {"Satu-Satu", "Tulus", 4.3};

    insertFirst(L, alokasi(lagu1));
    insertLast(L, alokasi(lagu2));
    insertLast(L, alokasi(lagu3));

    printInfo(L);

    cout << "\nMenambahkan lagu setelah lagu ke-3...\n";
    insertAfterK3(L, alokasi(lagu4));
    printInfo(L);

    cout << "\nMenambahkan lagu di awal playlist...\n";
    insertFirst(L, alokasi(lagu5));
    printInfo(L);

    cout << "\nMenghapus lagu 'Sinarengan'...\n";
    deleteByJudul(L, "Sinarengan");
    printInfo(L);

    return 0;
}
