#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "history.h"
#include "anggota.h"

void tampilkanHistory(int idxAnggota) {
    addressHistory h = daftarAnggota[idxAnggota].history;
    printf("Riwayat peminjaman untuk %s:\n", daftarAnggota[idxAnggota].name);
    while (h != NULL) {
        printf("- %s | Pinjam: %s | Kembali: %s | Status: %s\n",
               h->namaBuku,
               h->tanggalPinjam,
               h->tanggalKembali,
               h->status == 0 ? "Dipinjam" : "Dikembalikan");
        h = h->next;
    }
}

void tampilkanHistoryByNama(char *namaAnggota) {
    int idx = cariIndeksAnggota(namaAnggota);
    if (idx == -1) {
        printf("Anggota '%s' tidak ditemukan.\n", namaAnggota);
        return;
    }

    tampilkanHistory(idx);
}

