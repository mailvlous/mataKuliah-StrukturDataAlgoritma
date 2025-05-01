#include "linked.h"
#include "linked.c"
#include <stdlib.h>
#include <stdio.h>


int main() {
    address L1, L2;

    L1 = NULL;
    L2 = NULL;

    Ins_Awal(&L1, createNode(1));
    Ins_Awal(&L1, createNode(2));
    Ins_Awal(&L1, createNode(4));

    Ins_Awal(&L2, createNode(1));
    Ins_Awal(&L2, createNode(3));
    Ins_Awal(&L2, createNode(4));

    address mergedTwoList(address L1, address L2) {
        if (L1 == NULL) return L2;
        if (L2 == NULL) return L1;

        if (Info(L1) < Info(L2)) {
            Next(L1) = mergedTwoList(Next(L1), L2);
        }
        else {
            Next(L2) = mergedTwoList(L1, Next(L2));
        }
        return L1;
    }
    
    return 0;
}


