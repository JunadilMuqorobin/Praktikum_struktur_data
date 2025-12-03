#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#define Nil NULL

using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);

// Tambahan nomor 2
int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root);

// tambahan nomor 3
void PreOrder(address root);
void PostOrder(address root);


#endif
