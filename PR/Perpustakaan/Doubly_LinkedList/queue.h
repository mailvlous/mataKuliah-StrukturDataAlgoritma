#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "anggota.h"
#include "buku.h"

#define Front(Q) (Q)->front
#define Rear(Q) (Q)->rear

typedef struct {
    addressAnggota front;
    addressAnggota rear;
} Queue;

int isQueueEmpty(Queue Q);

bool isEmptyQueue(Queue q);

void createQueue(Queue *p);

void Ins_Akhir(addressAnggota *p, addressAnggota Pnew);

void Del_Awal(addressAnggota *p, char *x);

void enqueueAnggota(Queue *queue_anggota, addressAnggota anggota);

// void enqueueAnggota(addressBuku buku, addressAnggota anggota);

addressAnggota dequeueAnggota(Queue *q);


void printQueueAnggota(Queue q);

void sambungkanQueueKeBuku(addressBuku *L, char *judul, Queue A);

void sambungkanBukuDenganQueueByNama(addressBuku *listBuku, const char *namaBuku, Queue *queueAnggota);


void urutkanAntrianBerdasarLevel(addressBuku *listBuku, const char *namaBuku);

// void prosesPeminjamanBuku(addressBuku listBuku, const char *namaBuku);

void sambungUrutProsesAntrian(addressBuku listBuku, const char *namaBuku, Queue q);

void printHistory(addressAnggota anggota);

void printHistoryQueue(Queue Q);

addressAnggota cariAnggota(Queue Q, const char* nama);

void printHistoryByName(Queue Q, char *nama);

addressAnggota cariAnggotaDiQueue(Queue A, const char* nama);

void printHistoryByNameListAnggota(ListAnggota LA, char *nama);

addressAnggota findAnggotaByName(Queue *queue, const char *namaAnggota);

void tambahHistory(char *namaBuku, char *namaAnggota, int status, const char *aksi, Queue *queueAnggota);


void prosesPengembalianBuku(addressBuku *listBuku, const char *namaBuku, int jumlah);

void printListBukuDanAntrian(addressBuku listBuku);

void printRiwayatPeminjaman(addressAnggota anggota);

void printRiwayatPeminjamanByName(addressBuku listBuku, char *namaAnggota);

#endif // !



