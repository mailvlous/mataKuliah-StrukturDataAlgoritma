#ifndef listKota_H
#define listKota_H

#include "pendudukKota.h" // "."
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NextKota(K) (*K).next
#define PendudukKota(K) (*K).data.penduduk
#define DataKota(K) (*K).data

#define HeadKota(L) (*L).head

typedef struct tElmtKota* addrKota;
typedef struct tElmtKota {
    Kota data;
    addrKota next;
} ElmtKota;

typedef struct {
    addrKota head;
} ListKota;


void createListKota(ListKota *L);

addrKota createKotaElmt(char *kota);

void addKota(ListKota *L, addrKota K);

#endif