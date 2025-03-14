#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Kamus */
    typedef struct {
        float x;
        float y;
    } Point; /* Nama type */

    Point P2;  /* Deklarasi pointer ke struct */
    Point P3; /* Deklarasi alokasi memori */


    Point *P4 = &P2;
    Point *P5 = &P3;

    printf("%zu\n", sizeof(Point));

    /* Program */
    /* Cara 1: Mengacu elemen pointer ke struct menggunakan operator "->" */
    printf("Titik P2, dengan P2->x dan P2->y:\n");

    P2 = (Point *)malloc(sizeof(Point)); /* Alokasi memori untuk P2 */
    if (P2 == NULL) { /* Periksa apakah alokasi berhasil */
        printf("Gagal mengalokasikan memori untuk P2.\n");
        return 1;
    }

    P2->x = 9.12;
    P2->y = 2.567;

    printf("P2.x = %f\nP2.y = %f\n", P2->x, P2->y);

    /* Cara 2: Menggunakan tanda kurung untuk prioritas operator */
    if (P3 == NULL) { /* Periksa apakah alokasi berhasil */
        printf("Gagal mengalokasikan memori untuk P3.\n");
        free(P2); /* Bebaskan memori sebelum keluar */
        return 1;
    }

    (*P3).x = 0.5;
    (*P3).y = 10.5;

    printf("P3.x = %f\nP3.y = %f\n", (*P3).x, (*P3).y);

    /* Bebaskan memori yang telah dialokasikan */
    free(P2);
    free(P3);

    return 0;
}
