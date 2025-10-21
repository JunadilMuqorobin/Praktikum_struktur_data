#include <iostream>
#include <cstdlib>
#include "singlyList.h"
#include "singlyList.cpp"

using namespace std;

int main(){
    List L;
    address P;

    CreateList(L);

    cout << "Mengisi list menggunakan insertLast..." << endl;

    P = alokasi(9);
    insertLast(L, P);

    P = alokasi(12);
    insertLast(L, P);

    P = alokasi(8);
    insertLast(L, P);

    P = alokasi(0);
    insertLast(L, P);
    
    P = alokasi(2);
    insertLast(L, P);

    cout << "Isi List sekarang adalah: ";
    printInfo(L);

    system("pause");
    return 0;

}
