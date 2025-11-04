#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for(int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack Temp;
    createStack(Temp);

    while (S.top != -1) {
        push(Temp, pop(S));
    }

    S = Temp;
}

// TAMBAHAN SOAL 2
void pushAscending(Stack &S, infotype x) {
    Stack Temp;
    createStack(Temp);

    while (S.top != -1 && S.info[S.top] < x) {
        push(Temp, pop(S));
    }

    push(S, x);

    while (Temp.top != -1) {
        push(S, pop(Temp));
    }
}

// TAMBAHAN SOAL 3
void getInputStream(Stack &S) {
    char ch;

    while (true) {
        ch = cin.get();
        if (ch == '\n') break; 
        if (ch >= '0' && ch <= '9') {
            int x = ch - '0'; 
            push(S, x);
        }
    }
}
