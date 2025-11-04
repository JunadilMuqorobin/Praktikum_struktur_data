#ifndef STACK_H
#define STACK_H

#define MAX 20
typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// TAMBAHAN SOAL 2
void pushAscending(Stack &S, infotype x);

// TAMBAHAN SOAL 3
void getInputStream(Stack &S);

#endif
