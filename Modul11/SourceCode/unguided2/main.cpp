#include <iostream>
#include "circularlist.h"

using namespace std;

int main() {
    CircularList L;
    createList(L);

    infotype mhs1 = {"Ali", "23111234", 'L', 3.5};
    infotype mhs2 = {"Budi", "23111235", 'L', 3.8};
    infotype mhs3 = {"Cici", "23111236", 'P', 3.9};

    address P1 = createData(mhs1);
    address P2 = createData(mhs2);
    address P3 = createData(mhs3);

    cout << "Insert First Ali\n";
    insertFirst(L, P1);

    cout << "Insert Last Budi\n";
    insertLast(L, P2);

    cout << "Insert After Ali → Cici\n";
    insertAfter(L, P1, P3);

    cout << "\n=== Isi List ===\n";
    printList(L);

    cout << "\nJumlah Elemen: " << nbElm(L) << endl;

    cout << "\nDelete Budi\n";
    deleteP(L, "Budi");

    cout << "\n=== Isi List Setelah Delete ===\n";
    printList(L);

    return 0;
}
