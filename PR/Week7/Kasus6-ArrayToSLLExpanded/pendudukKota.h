#ifndef PENDUDUKKOTA_H
#define PENDUDUKKOTA_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define Nama(P) (*P).nama
#define Umur(P) (*P).umur
#define Next(P) (*P).next
#define Prev(P) (*P).prev

#define NamaKota(K) K.kt
#define Penduduk(K) (*K).penduduk
#define ListPenduduk(K) K.penduduk

typedef int infotype;
typedef struct tElmtList* address;
typedef struct tElmtList {
    char *nama;
    infotype umur;
    infotype level;
    address next;
    address prev;
} ElmtList;

typedef struct {
    char *kt;
    address penduduk; 
} Kota;

Kota createKota(char *kota);

address createPenduduk(char *nama, int umur);

void Ins_Penduduk(Kota *K, address penduduk);

void printKota(Kota K);

#endif