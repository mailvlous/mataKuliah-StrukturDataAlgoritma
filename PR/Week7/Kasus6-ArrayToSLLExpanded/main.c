#include "pendudukKota.h"
#include "pendudukKota.c"

#include "listKota.h"
#include "listKota.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    ListKota L;
    L.head = NULL;

    addrKota K1 = createKotaElmt("Jakarta");
    addrKota K2 = createKotaElmt("Bandung");

    addKota(&L, K1);
    addKota(&L, K2);

    Ins_Penduduk(&(K1->data), createPenduduk("Budi", 20));


    printListKota(L);

    // int choose;

    // while (1) {
    //     printf("Menu:\n");
    //     printf("1. Tambah Kota\n");
    //     printf("2. Hapus Kota\n");
    //     printf("3. Buka Daftar Kota\n");
    //     printf("4. Buka Data Kota");
    //     printf("4. Keluar\n");
        
    //     scanf(&choose);

    //     switch(choose) {
    //         case 1:

    //         break;

    //         case 2:

    //         break;

    //         case 3:
    //         printf("Daftar Kota:\n");


    //         break;

    //         case 4:

    //         break;

    //     }
    // }
}

