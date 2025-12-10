#include <iostream>
using namespace std;
typedef bool boolean;
typedef struct listinduk list;
#include "multilist.h"

int main(){
    listinduk L;
    CreateList(L);

    address p1 = alokasi(10);
    address p2 = alokasi(20);
    address p3 = alokasi(30);

    insertLast(L, p1);
    insertLast(L, p2);
    insertLast(L, p3);

    cout << "Setelah menambah 3 parent:" << endl;
    printInfo(L);
    cout << "Jumlah parent: " << nbList(L) << endl << endl;

    address_anak a1 = alokasiAnak(101);
    address_anak a2 = alokasiAnak(102);
    address_anak a3 = alokasiAnak(201);

    address found = findElm(L, 10);
    if(found != Nil){
        insertLastAnak(found->lanak, a1);
        insertLastAnak(found->lanak, a2);
    }

    found = findElm(L, 20);
    if(found != Nil){
        insertLastAnak(found->lanak, a3);
    }

    cout << "Setelah menambah anak:" << endl;
    printInfo(L);
    cout << "Jumlah anak parent 10: " << nbListAnak(findElm(L,10)->lanak) << endl << endl;

    // hapus child 102 dari parent 10
    delPAnak(findElm(L,10)->lanak, 102);
    cout << "Setelah menghapus anak 102 dari parent 10:" << endl;
    printInfo(L);
    cout << endl;

    // hapus parent 20 beserta anaknya
    delP(L, 20);
    cout << "Setelah menghapus parent 20:" << endl;
    printInfo(L);
    cout << "Jumlah parent: " << nbList(L) << endl << endl;

    delAll(L);
    cout << "Setelah delAll, jumlah parent: " << nbList(L) << endl;

    return 0;
}
