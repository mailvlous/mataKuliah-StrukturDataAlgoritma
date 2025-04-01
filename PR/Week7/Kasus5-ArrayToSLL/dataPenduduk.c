#include "dataPenduduk.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

address createPenduduk(char *nama) {
    address P = (address)malloc(sizeof(Penduduk));
    if (P == NULL) {
        printf("Gagal mengalokasikan memori untuk penduduk!\n");
        return NULL;
    }

    NamaPenduduk(P) = strdup(nama); 
    if (NamaPenduduk(P) == NULL) {
        printf("Gagal mengalokasikan memori untuk nama penduduk!\n");
        free(P);
        return NULL;
    }

    Next(P) = NULL;
    return P;
}

void addPenduduk(Kota *kota, address penduduk) {
    if (penduduk == NULL) return; 
    
    if (ListPenduduk(kota) == NULL) {
        ListPenduduk(kota) = penduduk;
    } else {
        address p = ListPenduduk(kota);
        while (Next(p) != NULL) {
            p = Next(p);
        }
        Next(p) = penduduk;
    }
} 


void printPendudukKota(Kota *kota) {
    if (kota == NULL || NamaKota(kota) == NULL) {
        printf("Kota tidak ada\n");
        return;
    }

    printf("Kota: %s\n", NamaKota(kota));

    if (ListPenduduk(kota) == NULL) {
        printf("  (Tidak ada penduduk)\n");
        return;
    }

    address p = ListPenduduk(kota);
    while (p != NULL) {
        if (NamaPenduduk(p) != NULL) { 
            printf("  - %s\n", NamaPenduduk(p));
        }
        p = Next(p);
    }
}


void DeleteKota(Kota *K) {
    address curr = ListPenduduk(K);
    address temp;
    
    while (curr != NULL) {
        temp = curr;
        curr = Next(curr);
        free(NamaPenduduk(temp)); 
        free(temp);
    }

    ListPenduduk(K) = NULL; 

    if (NamaKota(K) != NULL) {
        free(NamaKota(K));
        NamaKota(K) = NULL; 
    }
}


