#ifndef HISTORY_H
#define HISTORY_H

#include "queue.h"


typedef struct tHistory *addressHistory;
typedef struct tAnggota *addressAnggota;

// Definisi struktur History
typedef struct tHistory {
    char *namaBuku;
    char *tanggalPinjam;
    char *tanggalKembali; // NULL kalau belum dikembalikan
    int status; // 0 = dipinjam, 1 = dikembalikan
    addressHistory next;
} History;

addressHistory createHistory(char *namaBuku, char *tanggalPinjam, char *tanggalKembali, int status);

// void tambahHistory(char *namaBuku, char *namaAnggota, int status, const char *aksi, Queue *queueAnggota);

char* tanggal_sekarang();

void tambahHistoryAnggota(addressAnggota anggota, addressHistory H);

void tambahRiwayatPeminjaman(addressAnggota anggota, const char *namaBuku, const char *tanggalPinjam);

// void printRiwayatPeminjamanByName(addressAnggota head, const char *namaAnggota);
#endif // !HISTORY_H


