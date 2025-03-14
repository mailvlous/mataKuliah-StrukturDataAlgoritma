#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *T;  // Pointer ke array integer
    int N;   // Ukuran efektif
} tabint;

int main() {
    /* Kamus */
    tabint MyTab;
    int i;

    /* Program */
    printf("Tentukan ukuran tabel (maks 10): ");
    scanf("%d", &(MyTab.N));

    /* Alokasi memori untuk array */
    MyTab.T = (int *)malloc(MyTab.N * sizeof(int));

    if (MyTab.T == NULL) {
        printf("Alokasi memori gagal!\n");
        return 1;
    }
    int j = 11;
    /* Mengisi array dengan nilai indeksnya */
    for (i = 0; i < MyTab.N; i++) {
        
        MyTab.T[j] = j;
        printf("i = %d, MyTab.T[%d] = %d\n", i, i, MyTab.T[j]);
        j = j + 10;
    }

    /* Dealokasi memori */
    free(MyTab.T);

    return 0;
}
