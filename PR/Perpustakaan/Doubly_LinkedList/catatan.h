#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char namaBuku[100];
    char namaAnggota[100];
    int jumlah; // Jumlah buku yang dipinjam atau dikembalikan
    char tipeTransaksi[20]; // "Peminjaman" atau "Pengembalian"
    char tanggal[20]; // Tanggal transaksi
} Catatan;

Catatan catatanList[100]; // Array untuk menyimpan catatan transaksi
int catatanCount = 0; // Untuk menghitung jumlah transaksi

void tambahCatatan(char *namaBuku, char *namaAnggota, int jumlah, char *tipeTransaksi) {
    if (catatanCount < 100) {
        strcpy(catatanList[catatanCount].namaBuku, namaBuku);
        
        if (strcmp(tipeTransaksi, "Peminjaman") == 0 && namaAnggota != NULL) {
            strcpy(catatanList[catatanCount].namaAnggota, namaAnggota);
        } else {
            catatanList[catatanCount].namaAnggota[0] = '\0'; // kosongkan
        }

        catatanList[catatanCount].jumlah = jumlah;
        strcpy(catatanList[catatanCount].tipeTransaksi, tipeTransaksi);
        catatanCount++;
    } else {
        printf("Catatan penuh!\n");
    }
}


void tampilkanCatatan() {
    for (int i = 0; i < catatanCount; i++) {
        printf("Buku: %s | ", catatanList[i].namaBuku);

        if (strcmp(catatanList[i].tipeTransaksi, "Peminjaman") == 0) {
            printf("Anggota: %s | ", catatanList[i].namaAnggota);
        }

        printf("Jumlah: %d | Transaksi: %s\n", 
               catatanList[i].jumlah, catatanList[i].tipeTransaksi);
    }
}
