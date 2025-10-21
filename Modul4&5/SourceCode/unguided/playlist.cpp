#include "Playlist.h"


void createList(Playlist &L) {
    L.first = Nil;
}

address alokasi(Lagu x) {
    address P = new Node;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address P) {
    delete P;
}

bool isEmpty(Playlist L) {
    return (L.first == Nil);
}

void insertFirst(Playlist &L, address P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(Playlist &L, address P) {
    if (isEmpty(L)) {
        insertFirst(L, P);
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterK3(Playlist &L, address P) {
    if (isEmpty(L)) {
        cout << "Playlist masih kosong.\n";
        return;
    }
    address Q = L.first;
    int count = 1;

    while (Q != Nil && count < 3) {
        Q = Q->next;
        count++;
    }

    if (Q == Nil) {
        cout << "Kurang dari 3 lagu, menambahkan di akhir.\n";
        insertLast(L, P);
    } else {
        P->next = Q->next;
        Q->next = P;
    }
}

void deleteByJudul(Playlist &L, string judul) {
    if (isEmpty(L)) {
        cout << "Playlist kosong.\n";
        return;
    }

    address P = L.first;
    address prev = Nil;

    while (P != Nil && P->info.judul != judul) {
        prev = P;
        P = P->next;
    }

    if (P == Nil) {
        cout << "Lagu dengan judul \"" << judul << "\" tidak ditemukan.\n";
        return;
    }

    if (prev == Nil) {
        L.first = P->next; 
    } else {
        prev->next = P->next;
    }

    dealokasi(P);
    cout << "Lagu \"" << judul << "\" berhasil dihapus.\n";
}

void printInfo(Playlist L) {
    if (isEmpty(L)) {
        cout << "Playlist kosong.\n";
        return;
    }

    address P = L.first;
    int i = 1;
    cout << "\n=== Daftar Lagu dalam Playlist ===\n";
    while (P != Nil) {
        cout << i++ << ". Judul: " << P->info.judul
             << " | Penyanyi: " << P->info.penyanyi
             << " | Durasi: " << P->info.durasi << " menit\n";
        P = P->next;
    }
    cout << "=================================\n";
}
