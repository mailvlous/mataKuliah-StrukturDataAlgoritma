#ifndef ANGGOTA_H
#define ANGGOTA_H

#include <stdio.h>
#include <malloc.h>
#include "buku.h"

#define Name(P) (P)->name
#define Value(P) (P)->value
#define Tipe(P) (P)->tipe
#define Next(P) (P)->next 

// typedef enum {
//     TipeAnggota,
//     TipeBuku
// }Tipe;

// typedef struct tNode *address;

// typedef struct tNode{
//     char *name;
//     int value;
//     Tipe tipe;
//     address next;
// }Node;

typedef Node* Anggota;

Anggota createAnggota(char *nama, int level) {
    address newAnggota = (address)malloc(sizeof(Node));

    if (newAnggota == NULL){
        printf("ALokasi gamgal");
    }
    Name(newAnggota) = nama;
    Value(newAnggota) = level;
    Tipe(newAnggota) = TipeAnggota;
    Next(newAnggota) = NULL;

    return newAnggota;
}

void ins_Awal_Anggota(address *head, address anggota) {
    if (anggota == NULL) return;

    Next(anggota) = *head;
    *head = anggota;
}

void print_Anggota(address anggota) {
    if (anggota == NULL) {
        printf("{}");
        return;
    }

    printf("List Buku: ");
    printf("{");
    while (anggota != NULL) {
        printf("[ %s | Level: %d ]", Name(anggota), Value(anggota));
        anggota = Next(anggota);
        printf(" -> ");
    }
    printf("}");
    printf("\n");
}


#endif