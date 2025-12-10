#include "circularlist.h"

void createList(CircularList &L) {
    L.first = NULL;
}

address createData(infotype x) {
    address P = new Node;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(CircularList &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        P->next = P;
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        P->next = L.first;
        last->next = P;
        L.first = P;
    }
}

void insertLast(CircularList &L, address P) {
    if (L.first == NULL) {
        insertFirst(L, P);
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        last->next = P;
        P->next = L.first;
    }
}

void insertAfter(CircularList &L, address Prec, address P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(CircularList &L, address &P) {
    if (L.first == NULL) return;

    P = L.first;

    if (L.first->next == L.first) { 
        L.first = NULL;
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        L.first = P->next;
        last->next = L.first;
    }
    P->next = NULL;
}

void deleteLast(CircularList &L, address &P) {
    if (L.first == NULL) return;

    address last = L.first;
    address prev = NULL;

    while (last->next != L.first) {
        prev = last;
        last = last->next;
    }

    P = last;

    if (prev == NULL) { 
        L.first = NULL;
    } else {
        prev->next = L.first;
    }

    P->next = NULL;
}

void deleteAfter(CircularList &L, address Prec, address &P) {
    if (Prec == NULL || Prec->next == NULL) return;

    P = Prec->next;

    if (P == L.first) return;

    Prec->next = P->next;
    P->next = NULL;
}

void deleteP(CircularList &L, string namaKey) {
    if (L.first == NULL) return;

    address P = L.first;
    address prev = NULL;

    do {
        if (P->info.nama == namaKey) {
            if (P == L.first) {
                deleteFirst(L, P);
            } else {
                prev->next = P->next;
                P->next = NULL;
            }
            dealokasi(P);
            return;
        }
        prev = P;
        P = P->next;
    } while (P != L.first);
}

address findElm(CircularList L, string namaKey) {
    if (L.first == NULL) return NULL;

    address P = L.first;

    do {
        if (P->info.nama == namaKey) return P;
        P = P->next;
    } while (P != L.first);

    return NULL;
}

void printList(CircularList L) {
    if (L.first == NULL) {
        cout << "(kosong)" << endl;
        return;
    }

    address P = L.first;

    do {
        cout << "Nama: " << P->info.nama
             << ", NIM: " << P->info.nim
             << ", JK: " << P->info.jk
             << ", IPK: " << P->info.ipk << endl;

        P = P->next;
    } while (P != L.first);
}

int nbElm(CircularList L) {
    if (L.first == NULL) return 0;

    int count = 0;
    address P = L.first;

    do {
        count++;
        P = P->next;
    } while (P != L.first);

    return count;
}
