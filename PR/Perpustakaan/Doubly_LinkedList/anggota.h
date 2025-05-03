#ifndef ANGGOTA_H
#define ANGGOTA_H 

#include "buku.h"
#include "history.h"
#include "queue.h"


#define Nama(A) (A)->name
#define Level(A) (A)->level


typedef struct tAnggota *addressAnggota;

typedef struct tBuku *addressBuku;

typedef struct tAnggota {
    char *name;
    int level;
    addressBuku buku;         // Buku yang sedang dipinjam (jika ada)
    addressHistory history;   // Riwayat peminjaman
    addressAnggota next;        // untuk master list
    addressAnggota nextQueue; // Untuk keperluan antrian buku
} Anggota;

typedef struct {
    addressAnggota first;
} ListAnggota;

typedef struct {
    addressAnggota front;
    addressAnggota rear;
} QueueHistory;


addressAnggota createAnggota(const char *name, int level);

void tambahAnggota(ListAnggota *LA, char *nama, int level);

addressAnggota cariAnggotaListAnggota(ListAnggota LA, char *nama);

addressAnggota cariAnggotaByName(addressAnggota head, const char *nama);

void tampilkanRiwayatPeminjaman(addressAnggota anggotaList, const char *namaAnggota);

// addressAnggota findAnggotaByName(Queue *queue, const char *namaAnggota);

// void enqueue(QueueAnggota *Q, addressAnggota anggota);

// void dequeue(QueueAnggota *Q);


#endif // !ANGGOTA_H


