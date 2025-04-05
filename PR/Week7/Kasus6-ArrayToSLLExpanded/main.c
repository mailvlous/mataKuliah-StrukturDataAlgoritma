#include "pendudukKota.h"
#include "pendudukKota.c"

#include "listKota.h"
#include "listKota.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    ListKota L;
    L.head = NULL;

    // addrKota K1 = createKotaElmt("Jakarta");
    // addrKota K2 = createKotaElmt("Bandung");

    // addKota(&L, K1);
    // addKota(&L, K2);

    // Ins_Penduduk(&(DataKota(K1)), createPenduduk("Budi", 20));

    // printKota(DataKota(K1));

    // printListKota(L);

    // findKota(L, "Jakarta");

    int choose;

    while (1) {
        printf("Menu:\n");
        printf("1. Tambah Kota\n");
        printf("2. Hapus Kota\n");
        printf("3. Buka Daftar Kota\n");
        printf("4. Buka Data Kota\n");
        printf("5. Keluar\n");
        
        scanf("%d", &choose);

        switch(choose) {
            case 1:
            printf("Masukkan nama kota: ");
            char *tambahKota;
            scanf("%s", &tambahKota);

            addKota(&L, createKotaElmt(tambahKota));

            break;


            case 2:


            break;

            case 3:
            printf("Daftar Kota:\n");
            printListKota(L);

            break;

            case 4:
            printf("Masukkan nama kota: \n");
            char *dataKota;
            scanf("%s", &dataKota);

            findKota(L, dataKota);

            break;

            case 5:
            exit(0);

        }
    }
}

