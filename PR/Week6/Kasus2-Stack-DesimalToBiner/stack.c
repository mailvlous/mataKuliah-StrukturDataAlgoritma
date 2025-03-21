#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include "stack.c"
#include <linked.c>


address createStack (infotype p) {
    return createNode(p);
}

void push (address *p, address PNew) {
    Ins_Awal(p, PNew);
}

void pop (address *p, infotype *x) {
    Del_Awal(p, x);
}

void printStack (address p) {
    Tampil_List(p);
}

int decimalToBiner (int num) {
    address *Stack = NULL;

    while (num != 0) {
        address biner = createStack(num%2);
        Ins_Awal(&Stack, biner);
        num /= 2;
    }

    return Stack;
}