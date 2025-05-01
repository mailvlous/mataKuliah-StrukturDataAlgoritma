#include "peminjamBuku.h"
#include "peminjamBuku.c"

#include "listPeminjamanBuku.h"
#include "listPeminjamanBuku.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    ListPeminjamanBuku LPB;
    LPB.head = NULL;

    addrBuku B1 = createBukuElmt("Laskar Pelangi");


    addBuku(&LPB, B1);

}