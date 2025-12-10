#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#define Nil NULL

typedef bool boolean;
typedef int infotypeanak;
typedef int infotypeinduk;
typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

/* ----- Struct Anak ----- */
struct elemen_list_anak{
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

/* List anak */
struct listanak {
    address_anak first;
    address_anak last;
};

/* ----- Struct Induk ----- */
struct elemen_list_induk{
    infotypeinduk info;
    listanak lanak;       // list anak milik elemen induk
    address next;
    address prev;
};

/* List induk */
struct listinduk {
    address first;
    address last;
};

/********* pengecekan apakah list kosong ***********/
boolean ListEmpty(listinduk L);
/* true jika list induk kosong */

boolean ListEmptyAnak(listanak L);
/* true jika list anak kosong */

/********* pembuatan list kosong *********/
void CreateList(listinduk &L);
void CreateListAnak(listanak &L);

/********* manajemen memori *********/
address alokasi(infotypeinduk X);
address_anak alokasiAnak(infotypeanak X);

void dealokasi(address P);
void dealokasiAnak(address_anak P);

/********* pencarian elemen *********/
address findElm(listinduk L, infotypeinduk X);
address_anak findElm(listanak L, infotypeanak X);

boolean fFindElm(listinduk L, address P);
boolean fFindElmanak(listanak L, address_anak P);

address findBefore(listinduk L, address P);
address_anak findBeforeAnak(listanak L, infotypeinduk X, address_anak P);

/********* penambahan elemen *********/
void insertFirst(listinduk &L, address P);
void insertAfter(listinduk &L, address P, address Prec);
void insertLast(listinduk &L, address P);

void insertFirstAnak(listanak &L, address_anak P);
void insertAfterAnak(listanak &L, address_anak P, address_anak Prec);
void insertLastAnak(listanak &L, address_anak P);

/********* penghapusan elemen *********/
void delFirst(listinduk &L, address &P);
void delLast(listinduk &L, address &P);
void delAfter(listinduk &L, address &P, address Prec);
void delP(listinduk &L, infotypeinduk X);

void delFirstAnak(listanak &L, address_anak &P);
void delLastAnak(listanak &L, address_anak &P);
void delAfterAnak(listanak &L, address_anak &P, address_anak Prec);
void delPAnak(listanak &L, infotypeanak X);

/********* proses semua elemen *********/
void printInfo(listinduk L);
int nbList(listinduk L);

void printInfoAnak(listanak L);
int nbListAnak(listanak L);

void delAll(listinduk &L);

#endif