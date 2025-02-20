#include <stdio.h>

int main() {
    // int i = 1;
    // int j = 1;
    
    // while (i <= 5) {
    //     while (j <= i) {
    //         printf("*");
    //         j++;
    //     }
    //     printf("\n");
    //     i++;
    //     j = 1;
    // }

    // int i = 5;
    // int j = 1;
    // int k = 1;
    
    // while (i>=1) {
    //     while (j <= i) {
    //         printf(" ");
    //         printf("*");
    //         j++;
    //     }
    //     printf("\n");
    //     i--;
    //     j = 1;
    // }



    // int i = 4;
    // int j = 1;
    // int k = 1;

    // while (i <= 4) {
    //     while (j <= i) {
    //         printf(" ");
    //         if (j == i) {
    //             printf("*");
    //         }
    //         j++;
    //     }
    // }

    //Soal4

    // int i = 4;
    // int j = 1;
    // int k = 1;
    // int max = 1;

    // for(i = 4; i >= 1; i--) {
    //     for(j = 1; j <= i; j++) {
    //         printf(" ");
            
    //     }
    //     for (k = 1; k <= max; k++) {
    //         printf("*");
    //     }
    //     max += 2;

    //     printf("\n");
    // }

    int i = 4;
    int j = 1;
    int k = 1;
    int max = 1;
    int l = 1;
    int m = 1;
    int n = 1;

    // for(i = 4; i >= 1; i--) {
    //     for(j = 1; j <= i; j++) {
    //         printf(" ");
            
    //     }
    //     for (k = 1; k <= max; k++) {
    //         printf("*");
    //     }
    //     max += 2;

    //     printf("\n");
    // }
    int max2 = 0;

    for(i = 0; i <= 4; i++) {
        for(j = 9; j >= i; j--) {
            printf("*");

        }
        for (k = 9; k <= max; k--) {
            printf(" ");
        }
        max2 = max2 + 2;

        printf("\n");
    }


}



