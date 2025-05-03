#include <stdio.h>
#include <stdlib.h>


int main() {
    int pilihan;

    do {
        printf("\n=== Menu Utama ===\n");
        printf("1. Jalankan Array\n");
        printf("2. Jalankan Single Linked List\n");
        printf("3. Jalankan Doubly Linked List\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                system("array_main.exe");
                break;
            case 2:
                system("Single_LinkedList/single.exe");
                break;
            case 3:
                system("Doubly_LinkedList/doubly.exe");
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}
