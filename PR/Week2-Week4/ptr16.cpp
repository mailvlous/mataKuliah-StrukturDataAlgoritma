#include <stdio.h>
#include <stdlib.h>

#define STRING char*

int main() {
    /* Kamus */
    /* Definisi array statik yang elemennya string */
    static STRING s[3] = {"the", "time", "is"};

    /* Definisi array dinamis yang elemennya string */
    /* pointer char sudah didefinisikan dengan makro STRING
       sehingga tidak perlu dideklarasikan kembali jadi tidak
       perlu pointer to pointer lagi 
    */
    STRING* TabStr; // Deklarasi array of string
    int i;

    /* Program */
    // Cetak isi array statik
    for (i = 0; i < 3; i++) {
        printf("%s\n", s[i]);
    }

    /* Alokasi memori untuk array of string sebanyak 3 elemen */
    TabStr = (STRING *)malloc(3 * sizeof(STRING)); // alokasi jumlah kata

    if (TabStr == NULL) {
        printf("Alokasi gagal!\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        /* Alokasi memori untuk setiap string (maksimum 5 karakter + 1 null terminator) */
        TabStr[i] = (STRING)malloc(6 * sizeof(char)); // alokasi jumlah huruf setiap kata

        if (TabStr[i] == NULL) {
            printf("Alokasi gagal untuk string %d!\n", i);
            return 1;
        }

        /* Input string */
        printf("\nInput Str[%d], maksimum 5 karakter: ", i);
        scanf("%5s", TabStr[i]);

        /* Cetak nilai string */
        printf("\nNilai Str[%d]: %s\n", i, TabStr[i]);
    }

    /* Dealokasi memori */
    for (i = 0; i < 3; i++) {
        free(TabStr[i]);
    }
    free(TabStr);

    return 0;
}
