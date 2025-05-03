#ifndef BUKU_H
#define BUKU_H

#define MAX_BUKU 100

#include "queue.h"
#include "anggota.h"

typedef struct {
    char judul[100];           // Gunakan array alih-alih pointer
    int stok;
    Queue antrian;            // Tetap pakai Queue untuk antrian peminjam
} Buku;

Buku daftarBuku[MAX_BUKU];

int jumlahBuku = 0;

void tambahBuku(char *judul, int stok);

void listBuku();

void pinjamBuku(int idxAnggota, int idxBuku, char *tanggal);

int cariIndeksBuku(char *judul);

void pinjamBukuByNama(char *namaAnggota, char *namaBuku, char *tanggal);


#endif // !BUKU_H
