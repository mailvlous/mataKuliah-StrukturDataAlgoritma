#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "catatan.h"

void tambahHistory(char *namaBuku, char *namaAnggota, int jumlah, char *tipeTransaksi) {
    if (historyCount < 100) {
        strcpy(historyList[historyCount].namaBuku, namaBuku);
        
        if (strcmp(tipeTransaksi, "Peminjaman") == 0 && namaAnggota != NULL) {
            strcpy(historyList[historyCount].namaAnggota, namaAnggota);
        } else {
            historyList[historyCount].namaAnggota[0] = '\0'; // kosongkan
        }

        historyList[historyCount].jumlah = jumlah;
        strcpy(historyList[historyCount].tipeTransaksi, tipeTransaksi);
        historyCount++;
    } else {
        printf("Catatan penuh!\n");
    }
}


void tampilkanHistory() {
    for (int i = 0; i < historyCount; i++) {
        printf("Buku: %s | ", historyList[i].namaBuku);

        if (strcmp(historyList[i].tipeTransaksi, "Peminjaman") == 0) {
            printf("Anggota: %s | ", historyList[i].namaAnggota);
        }

        printf("Jumlah: %d | Transaksi: %s\n", 
               historyList[i].jumlah, historyList[i].tipeTransaksi);
    }
}
