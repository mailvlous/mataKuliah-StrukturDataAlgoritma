#include <stdio.h>

/* Definisi tabel integer */
typedef struct {
    int tab[10];  // Array integer
    int N;        // Ukuran efektif
} tabint;

/* tabint merupakan tipe data baru 
   yang terdiri dari array integer statis dan N integer
   */

/* Prototype */
void incTab(tabint *T);  // Increment setiap elemen tabel
void printTab(tabint T); // Print tabel

int main() {
    /* Kamus */
    tabint T;
    int i;

    /* Program */
    T.N = 3;
    printf("Isi dan print tabel untuk indeks 0..%d\n", T.N - 1);

    /* Input elemen tabel */
    for (i = 0; i < T.N; i++) {
        printf("Input tabel ke-%d: ", i);
        scanf("%d", &(T.tab[i]));
    }

    /* Print tabel sebelum increment */
    printTab(T);

    /* Increment tabel (by reference) */
    incTab(&T);

    /* Print tabel setelah increment */
    printTab(T);

    return 0;
}

/* Body prototype */
void incTab(tabint *T) {
    /* Increment setiap elemen tabel */
    for (int i = 0; i < (*T).N; i++) {
        (*T).tab[i] += 1;
    }
}

void printTab(tabint T) {
    /* Print setiap elemen tabel */
    for (int i = 0; i < T.N; i++) {
        printf("T[%d] = %d\n", i, T.tab[i]);
    }
}
