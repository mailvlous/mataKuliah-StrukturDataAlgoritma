#include "listKota.h"
#include "pendudukKota.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void createListKota(ListKota *L) {
    HeadKota(L) = NULL;

}

addrKota createKotaElmt(char *kota) {
    addrKota K = (addrKota) malloc(sizeof(ElmtKota));
    K->data.kt = strdup(kota);       // Copy nama kota
    PendudukKota(K) = NULL;         // Awalnya belum ada penduduk
    NextKota(K) = NULL;
    return K;
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
}

void printSeluruhKota(ListKota L) {
    addrKota temp = L.head;
    printf("Kota: ");
    while (temp != NULL) {
        printf(" -> %s", temp->data.kt);
        temp = temp->next; // Akses langsung tanpa NextKota()
    }
}

void findKota(ListKota L, char *kota) {
    addrKota temp = L.head;
    while (temp != NULL) {
        if (strcmp(temp->data.kt, kota) == 0) {
            printf("\n");
            printKota(DataKota(temp));
        } 
        temp = temp->next; // Akses langsung tanpa NextKota()
    }
}