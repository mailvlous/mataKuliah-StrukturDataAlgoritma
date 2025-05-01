#include "listPeminjamanBuku.h"
#include "peminjamBuku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void createListPeminjamanBuku(ListPeminjamanBuku *L) {
    HeadBuku(L) = NULL;

}

addrKota createBukuElmt(char *buku) {
    addrBuku B = (addrBuku) malloc(sizeof(ElmtBuku));
    B->dataBuku.nmBuku = strdup(buku);       // Copy nama kota
    PeminjamBuku(B) = NULL;         // Awalnya belum ada penduduk
    NextBuku(B) = NULL;
    return B;
}


void addKota(ListKota *L, addrKota K) {
    if (HeadKota(L) == NULL) {
        HeadKota(L) = K;
    } else {
        addrKota temp = HeadKota(L);
        while (NextKota(temp) != NULL) {
            temp = NextKota(temp);
        }
        NextKota(temp) = K;
    }
}

void printListKota(ListKota L) {
    addrKota temp = L.head;
    printf("Kota: ");
    while (temp != NULL) {
        printf(" -> %s", temp->data.kt);
        temp = temp->next; // Akses langsung tanpa NextKota()
    }
    printf("\n");
}