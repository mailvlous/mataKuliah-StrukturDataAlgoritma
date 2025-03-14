#include <stdlib.h>
#include <stdio.h>

int main() {
    /* Kamus */
    /* Definisi array statik yang elemennya string */
    static char *s[3] = {"the", "time", "is"}; // berada pada segmen read only

    /* Definisi array dinamis yang elemennya string */
    char **TabStr;  // Deklarasi array of string
    int i;

    /* Program */
    // Cetak isi array statik
    for (i = 0; i < 3; i++) {
        printf("%s\n", s[i]);
    }

    /* Alokasi memori untuk array of string sebanyak 3 elemen */
    TabStr = (char **)malloc(3 * sizeof(char *)); // alokasi jumlah kata
    
    if (TabStr == NULL) {
        printf("Alokasi gagal!\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        /* Alokasi memori untuk setiap string (maksimum 5 karakter + 1 null terminator) */
        TabStr[i] = (char *)malloc(6 * sizeof(char)); // alokasi jumlah huruf setiap kata

        if (TabStr[i] == NULL) {
            printf("Alokasi gagal untuk string %d!\n", i);
            return 1;
        }

        /* Input string */
        printf("\nInput Str[%d], maksimum 5 karakter: ", i);
        /* meskipun diinput lebih dari 5 karakter, hanya akan diambil 5
        karakter pertama, 5 karakter kedua, dan seterusnya */
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
