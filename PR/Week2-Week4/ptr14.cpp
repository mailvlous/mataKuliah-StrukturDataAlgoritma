#include <stdlib.h>
#include <stdio.h>

int main() {
    /* Kamus Data */
    int *tab;  // Deklarasi array dinamis
    int N, i;

    /* Program */
    printf("Contoh mengisi array dinamis berukuran 0..N:\n");
    printf("N = ");
    scanf("%d", &N);

    printf("Alokasi setelah mengetahui ukuran array\n");
    tab = (int *)malloc((N + 1) * sizeof(int)); // alokasi memori tab, N ditambah 1 karena index mulai dari 0

    if (tab != NULL) {
        for (i = 0; i <= N; i++) {
            printf("i = %d tab[i]= %d \n", i, *(tab)); // *(tab) akses nilai array tab[0]
            printf("i = %d tab[i] = %d\n", i, tab[i]); // *(tab) adalah nilai keseluruhan karena ad increment
        }
        printf("Akhir program\n");

        /* Dealokasi */
        free(tab);
        return 0;
    } else {
        printf("Alokasi gagal...\n");
        return 1;
    }
}
