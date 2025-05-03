#ifndef ANGGOTA_H
#define ANGGOTA_H


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

Anggota createAnggota(char *nama, int level);

void ins_Awal_Anggota(address *head, address anggota);

void print_Anggota(address anggota);

#endif