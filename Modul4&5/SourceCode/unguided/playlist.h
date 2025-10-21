#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define Nil NULL

struct Lagu {
    string judul;
    string penyanyi;
    float durasi;
};

typedef struct Node *address;

struct Node {
    Lagu info;
    address next;
};

struct Playlist {
    address first;
};

// PROTOTYPE FUNGSI
void createList(Playlist &L);
address alokasi(Lagu x);
void dealokasi(address P);
bool isEmpty(Playlist L);
void insertFirst(Playlist &L, address P);
void insertLast(Playlist &L, address P);
void insertAfterK3(Playlist &L, address P);
void deleteByJudul(Playlist &L, string judul);
void printInfo(Playlist L);

#endif
