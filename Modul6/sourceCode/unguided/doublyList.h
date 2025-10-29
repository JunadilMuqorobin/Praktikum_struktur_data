#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
using namespace std;

#define Nil nullptr

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct ElmList* address;

struct ElmList {
    kendaraan info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(const kendaraan &x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(const List &L);
address findElm(const List &L, const string &nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);

#endif
