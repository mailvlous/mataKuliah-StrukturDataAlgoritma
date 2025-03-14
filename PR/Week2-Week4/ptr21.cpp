#include <stdlib.h>
#include <stdio.h>

/* Definisi akses komponen type, standard kuliah Algoritma dan Pemrograman */
#define info(P) (*P).info
#define next(P) (*P).next
#define Nil NULL

/* Definisi TYPE global */
/* Element list linier */
typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info;
    address next;
} ElmtList;

/* Program Utama */
int main() {
    /* Kamus */
    address First = Nil;
    address P, Q;

    /* P karena pointer maka hanya menunjuk */

    /* Alokasi, insert sebagai elemen pertama */
    P = (address) malloc(sizeof(ElmtList));
    if (P == Nil) {
        printf("Gagal mengalokasikan memori!\n");
        return 1;
    }
    info(P) = 10;
    next(P) = Nil;
    First = P;

    /* Alokasi, insert sebagai elemen pertama */
    Q = (address) malloc(sizeof(ElmtList));
    if (Q == Nil) {
        printf("Gagal mengalokasikan memori!\n");
        free(P);
        return 1;
    }
    info(Q) = 20;
    next(Q) = First;
    First = Q;

    /* Alokasi, insert sebagai elemen pertama */
    P = (address) malloc(sizeof(ElmtList));
    if (P == Nil) {
        printf("Gagal mengalokasikan memori!\n");
        free(Q);
        free(First);
        return 1;
    }
    info(P) = 30;
    next(P) = First;
    First = P;

    /* Cetak elemen ketiga */
    if (next(next(First)) != Nil) {
        printf("%d\n", info(next(next(First))));
    } else {
        printf("Elemen tidak cukup dalam list.\n");
    }

    /* Bebaskan memori */
    while (First != Nil) {
        address temp = First;
        First = next(First);
        free(temp);
    }

    return 0;
}
