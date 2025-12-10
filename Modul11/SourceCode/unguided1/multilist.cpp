#include <iostream>
using namespace std;
typedef bool boolean;
typedef struct listinduk list; 
#include "multilist.h"

boolean ListEmpty(listinduk L){
    return (L.first == Nil);
}
boolean ListEmptyAnak(listanak L){
    return (L.first == Nil);
}

/* pembuatan list kosong */
void CreateList(listinduk &L){
    L.first = Nil;
    L.last = Nil;
}
void CreateListAnak(listanak &L){
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotypeinduk P){
    address Pnew = new elemen_list_induk;
    if(Pnew != Nil){
        Pnew->info = P;    
                                 
        CreateListAnak(Pnew->lanak);
        Pnew->next = Nil;
        Pnew->prev = Nil;
    }
    return Pnew;
}
address_anak alokasiAnak(infotypeanak P){
    address_anak Pnew = new elemen_list_anak;
    if(Pnew != Nil){
        Pnew->info = P;
        Pnew->next = Nil;
        Pnew->prev = Nil;
    }
    return Pnew;
}
void dealokasi(address P){
    delete P;
}
void dealokasiAnak(address_anak P){
    delete P;
}

/* pencarian elemen */
address findElm(listinduk L, infotypeinduk X){
    if(ListEmpty(L)) return Nil;
    address P = L.first;
    while(P != Nil){
        if(P->info == X) return P;
        P = P->next;
    }
    return Nil;
}
address_anak findElm(listanak Lanak, infotypeanak X){
    if(ListEmptyAnak(Lanak)) return Nil;
    address_anak P = Lanak.first;
    while(P != Nil){
        if(P->info == X) return P;
        P = P->next;
    }
    return Nil;
}
boolean fFindElm(listinduk L, address P){
    if(ListEmpty(L)) return false;
    address Q = L.first;
    while(Q != Nil){
        if(Q == P) return true;
        Q = Q->next;
    }
    return false;
}
boolean fFindElmanak(listanak Lanak, address_anak P){
    if(ListEmptyAnak(Lanak)) return false;
    address_anak Q = Lanak.first;
    while(Q != Nil){
        if(Q == P) return true;
        Q = Q->next;
    }
    return false;
}
address findBefore(listinduk L, address P){
    if(ListEmpty(L) || P == L.first) return Nil;
    address Q = L.first;
    while(Q != Nil && Q->next != P){
        Q = Q->next;
    }
    if(Q == Nil) return Nil;
    return Q;
}
address_anak findBeforeAnak(listanak Lanak, infotypeinduk /*X*/, address_anak P){
    if(ListEmptyAnak(Lanak) || P == Lanak.first) return Nil;
    address_anak Q = Lanak.first;
    while(Q != Nil && Q->next != P){
        Q = Q->next;
    }
    if(Q == Nil) return Nil;
    return Q;
}

// tambah elemen
void insertFirst(listinduk &L, address P){
    if(ListEmpty(L)){
        L.first = P;
        L.last = P;
        P->next = Nil;
        P->prev = Nil;
    } else {
        P->next = L.first;
        P->prev = Nil;
        L.first->prev = P;
        L.first = P;
    }
}
void insertAfter(listinduk &L, address P, address Prec){
    if(Prec == Nil) return;
    if(Prec == L.last){
        insertLast(L, P);
        return;
    }
    P->next = Prec->next;
    P->prev = Prec;
    Prec->next->prev = P;
    Prec->next = P;
}
void insertLast(listinduk &L, address P){
    if(ListEmpty(L)){
        insertFirst(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        P->next = Nil;
        L.last = P;
    }
}

/* penambahan elemen (anak) */
void insertFirstAnak(listanak &L, address_anak P){
    if(ListEmptyAnak(L)){
        L.first = P;
        L.last = P;
        P->next = Nil;
        P->prev = Nil;
    } else {
        P->next = L.first;
        P->prev = Nil;
        L.first->prev = P;
        L.first = P;
    }
}
void insertAfterAnak(listanak &L, address_anak P, address_anak Prec){
    if(Prec == Nil) return;
    if(Prec == L.last){
        insertLastAnak(L, P);
        return;
    }
    P->next = Prec->next;
    P->prev = Prec;
    Prec->next->prev = P;
    Prec->next = P;
}
void insertLastAnak(listanak &L, address_anak P){
    if(ListEmptyAnak(L)){
        insertFirstAnak(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        P->next = Nil;
        L.last = P;
    }
}

/* penghapusan elemen (induk) */
void delFirst(listinduk &L, address &P){
    if(ListEmpty(L)) { P = Nil; return; }
    P = L.first;
    if(L.first == L.last){
        L.first = Nil;
        L.last = Nil;
    } else {
        L.first = P->next;
        L.first->prev = Nil;
    }
    P->next = Nil;
    P->prev = Nil;
}
void delLast(listinduk &L, address &P){
    if(ListEmpty(L)) { P = Nil; return; }
    P = L.last;
    if(L.first == L.last){
        L.first = Nil;
        L.last = Nil;
    } else {
        L.last = P->prev;
        L.last->next = Nil;
    }
    P->next = Nil;
    P->prev = Nil;
}
void delAfter(listinduk &L, address &P, address Prec){
    if(Prec == Nil || Prec->next == Nil) { P = Nil; return; }
    P = Prec->next;
    Prec->next = P->next;
    if(P->next != Nil) P->next->prev = Prec;
    else L.last = Prec;
    P->next = Nil;
    P->prev = Nil;
}
void delP (listinduk &L, infotypeinduk X){
    if(ListEmpty(L)) return;
    address P = findElm(L, X);
    if(P == Nil) return;
    // hapus semua anak pada P terlebih dahulu
    address_anak c = P->lanak.first;
    while(c != Nil){
        address_anak temp = c;
        c = c->next;
        dealokasiAnak(temp);
    }
    if(P == L.first){
        address tmp;
        delFirst(L, tmp);
        dealokasi(P);
    } else if(P == L.last){
        address tmp;
        delLast(L, tmp);
        dealokasi(P);
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
        dealokasi(P);
    }
}

/* penghapusan elemen (anak) */
void delFirstAnak(listanak &L, address_anak &P){
    if(ListEmptyAnak(L)) { P = Nil; return; }
    P = L.first;
    if(L.first == L.last){
        L.first = Nil;
        L.last = Nil;
    } else {
        L.first = P->next;
        L.first->prev = Nil;
    }
    P->next = Nil;
    P->prev = Nil;
}
void delLastAnak(listanak &L, address_anak &P){
    if(ListEmptyAnak(L)) { P = Nil; return; }
    P = L.last;
    if(L.first == L.last){
        L.first = Nil;
        L.last = Nil;
    } else {
        L.last = P->prev;
        L.last->next = Nil;
    }
    P->next = Nil;
    P->prev = Nil;
}
void delAfterAnak(listanak &L, address_anak &P, address_anak Prec){
    if(Prec == Nil || Prec->next == Nil) { P = Nil; return; }
    P = Prec->next;
    Prec->next = P->next;
    if(P->next != Nil) P->next->prev = Prec;
    else L.last = Prec;
    P->next = Nil;
    P->prev = Nil;
}
void delPAnak (listanak &L, infotypeanak X){
    if(ListEmptyAnak(L)) return;
    address_anak P = findElm(L, X);
    if(P == Nil) return;
    if(P == L.first){
        address_anak tmp;
        delFirstAnak(L, tmp);
        dealokasiAnak(P);
    } else if(P == L.last){
        address_anak tmp;
        delLastAnak(L, tmp);
        dealokasiAnak(P);
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
        dealokasiAnak(P);
    }
}

/* proses semua elemen list */
void printInfo(list L){
    if(ListEmpty(*((listinduk*)&L))) return;
    address P = L.first;
    while(P != Nil){
        cout << P->info;
        // print anak
        address_anak C = P->lanak.first;
        if(C != Nil) cout << " -> ";
        while(C != Nil){
            cout << C->info;
            if(C->next != Nil) cout << ", ";
            C = C->next;
        }
        cout << endl;
        P = P->next;
    }
}
int nbList(list L){
    int cnt = 0;
    address P = L.first;
    while(P != Nil){
        cnt++;
        P = P->next;
    }
    return cnt;
}
void printInfoAnak(listanak Lanak){
    address_anak P = Lanak.first;
    while(P != Nil){
        cout << P->info;
        if(P->next != Nil) cout << ", ";
        P = P->next;
    }
    cout << endl;
}
int nbListAnak(listanak Lanak){
    int cnt = 0;
    address_anak P = Lanak.first;
    while(P != Nil){
        cnt++;
        P = P->next;
    }
    return cnt;
}

/* proses terhadap list */
void delAll(listinduk &L){
    while(!ListEmpty(L)){
        address P;
        delFirst(L, P);
        // hapus semua anak
        address_anak c = P->lanak.first;
        while(c != Nil){
            address_anak tmp = c;
            c = c->next;
            dealokasiAnak(tmp);
        }
        dealokasi(P);
    }
}
