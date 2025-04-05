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

    Ins_Penduduk(&(DataKota(K1)), createPenduduk("Budi", 20));
    Ins_Penduduk(&(DataKota(K1)), createPenduduk("Caca", 21));

    printKota(DataKota(K1));

    printListKota(L);

    hapus_Penduduk(&(DataKota(K1)), "Budi");

    printKota(DataKota(K1));

    hapusKota(&L, "Bandung");

    printListKota(L);

    // int choose;

    // while (1) {
    //     printf("\nMenu:\n");
    //     printf("1. Tambah Kota\n");
    //     printf("2. Hapus Kota\n");
    //     printf("3. Buka Daftar Kota\n");
    //     printf("4. Tambah Penduduk\n");
    //     printf("5. Hapus Penduduk\n");
    //     printf("6. Buka Data Kota\n");
    //     printf("7. Keluar\n");
    //     printf("Pilihan: ");

    //     scanf("%d", &choose);
    //     getchar(); 

    //     switch(choose) {
    //         case 1: {
    //             char tambahKota[100];
    //             printf("Masukkan nama kota: ");
    //             scanf("%s", tambahKota);
    //             addKota(&L, createKotaElmt(tambahKota));
    //             break;
    //         }

    //         case 2:

    //             break;

    //         case 3:
    //             printf("Daftar Kota:\n");
    //             printListKota(L);

    //             break;

    //         case 4: {
    //             char dataKota[100];
    //             scanf("%s", dataKota);
    //             if (findKota(L, dataKota)) {
    //                 printf("Data Kota:\n");
    //             }

    //             break;
    //         }

    //         case 5:
    //             exit(0);

    //         default:
    //             printf("Pilihan tidak valid.\n");
    //     }
    // }

    // return 0;
}

