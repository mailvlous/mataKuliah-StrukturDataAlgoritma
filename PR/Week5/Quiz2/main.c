#include "linked.h"
#include "linked.c"
#include <stdlib.h>
#include <stdio.h>


int main() {
    address p = NULL;
    int x;
    
    Ins_Awal(&p, createNode(7));
    Tampil_List(p);

    Ins_Akhir(&p, createNode(11));
    Tampil_List(p);

    InsertAfter(&p, createNode(9));
    Tampil_List(p);

    Ins_Awal(&p, createNode(5));
    Tampil_List(p);

    Ins_Akhir(&p, createNode(13));
    Tampil_List(p);

    Del_Akhir(&p, &x);
    Tampil_List(p);

    Del_After_Value(&p, 5, &x);
    Tampil_List(p);

    Del_Awal(&p, &x);
    Tampil_List(p);

    Del_Awal(&p, &x);
    Del_Awal(&p, &x);
    Tampil_List(p);

    return 0;

}