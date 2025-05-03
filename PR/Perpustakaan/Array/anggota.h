#ifndef ANGGOTA_H 
#define ANGGOTA_H


#define MAX_ANGGOTA 100


#include "history.h"
#include "buku.h"

typedef struct {
    char name[100];                // Gunakan array
    int level;
    int indeksBuku;               // Indeks buku yang sedang dipinjam (misalnya -1 jika tidak meminjam)
    addressHistory history;       // Tetap pakai linked list untuk riwayat
    // nextQueue dihapus, karena tidak pakai linked list
} Anggota;

Anggota daftarAnggota[MAX_ANGGOTA];

int jumlahAnggota = 0;

void tambahAnggota(char *nama, int level);

int cariIndeksAnggota(char *nama);

void kembalikanBukuByNama(char *namaAnggota, char *tanggal);

#endif 

