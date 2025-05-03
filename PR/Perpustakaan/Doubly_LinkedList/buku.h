#ifndef BUKU_H
#define BUKU_H


#include "queue.h"

#define Judul(B) (B)->judul
#define Stok(B) (B)->stok
#define NextBuku(B) (B)->nextBuku

typedef struct tBuku *addressBuku;

typedef struct tBuku {
    char *judul;
    int stok;
    addressBuku nextBuku; // Boleh dihapus jika tidak butuh linked list buku
    Queue antrian;
} Buku;

addressBuku createBuku(char *judul, int stok);

void ins_Awal_Buku(addressBuku *head, addressBuku buku);

void printList(addressBuku node);

addressBuku cariBuku(addressBuku listBuku, const char *namaBuku);

// void prosesPeminjamanBuku(addressBuku listBuku, char *namaBuku);

void prosesPeminjamanBuku(addressBuku *listBuku, char *judulBuku, Queue *q, char *tanggalPinjam);



// void printRiwayatPeminjaman(addressAnggota anggota);

void lihatListBuku(addressBuku listBuku);

void tambahBuku(addressBuku *listBuku);

void tambahAnggotaKeAntrian(addressBuku listBuku, const char *namaBuku);

void prosesPeminjaman(addressBuku listBuku, const char *namaBuku);

addressBuku cariBukuByNama(addressBuku listBuku, const char *namaBuku);

// void prosesPeminjaman(addressBuku L);


#endif // DEBUG

