#ifndef DATAPENDUDUK_H
#define DATAPENDUDUK_H
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define NamaKota(K) ((K)->kt)        // Akses nama kota
#define ListPenduduk(K) ((K)->penduduk)    // Akses daftar penduduk
#define NamaPenduduk(P) ((P)->nm)    // Akses nama penduduk
#define Next(P) ((P)->next)       // Akses penduduk berikutnya

typedef struct tPenduduk *address;
typedef struct tPenduduk {
    char *nm;
    address next;
} Penduduk;

typedef struct{
    char *kt;
    address penduduk; 
} Kota;

address createPenduduk(char *nama);

void addPenduduk(Kota *kota, address penduduk);

void printPendudukKota(Kota *kota);

#endif