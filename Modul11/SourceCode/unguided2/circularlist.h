#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    char jk;
    float ipk;
};

typedef Mahasiswa infotype;

struct Node {
    infotype info;
    Node *next;
};

typedef Node* address;

struct CircularList {
    address first;
};

void createList(CircularList &L);

address createData(infotype x);
void dealokasi(address P);

void insertFirst(CircularList &L, address P);
void insertLast(CircularList &L, address P);
void insertAfter(CircularList &L, address Prec, address P);

void deleteFirst(CircularList &L, address &P);
void deleteLast(CircularList &L, address &P);
void deleteAfter(CircularList &L, address Prec, address &P);
void deleteP(CircularList &L, string namaKey);

address findElm(CircularList L, string namaKey);

void printList(CircularList L);
int nbElm(CircularList L);

#endif
