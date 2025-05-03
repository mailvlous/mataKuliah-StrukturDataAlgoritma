#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "queue.h"
#include "anggota.h"



void tambahAnggota(char *nama, int level) {
    strcpy(daftarAnggota[jumlahAnggota].name, nama);
    daftarAnggota[jumlahAnggota].level = level;
    daftarAnggota[jumlahAnggota].indeksBuku = -1;
    daftarAnggota[jumlahAnggota].history = NULL;
    jumlahAnggota++;
}

int cariIndeksAnggota(char *nama) {
    for (int i = 0; i < jumlahAnggota; i++) {
        if (strcmp(daftarAnggota[i].name, nama) == 0) {
            return i;
        }
    }
    return -1;
}

void kembalikanBukuByNama(char *namaAnggota, char *tanggal) {
    int idxAnggota = cariIndeksAnggota(namaAnggota);
    if (idxAnggota == -1) {
        printf("Anggota '%s' tidak ditemukan.\n", namaAnggota);
        return;
    }

    kembalikanBuku(idxAnggota, tanggal);
}
