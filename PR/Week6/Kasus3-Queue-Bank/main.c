#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "queue.c"
#include "linked.h"
#include "linked.c"

int main() {
    int i, antrian, q, choose;
    antrian = 1;
    address Q;

    create_Queue(&Q);

    while (1) {
        printf("Welcome\n");
        printf("1. Ambil Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("4. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            enqueue(&Q, createQueue(antrian));
            antrian++;
            printQueue(Q);
            break;
        
        case 2:
            if (isQueueEmpty(Q)) {
                printf("Antrian Kosong\n");
            } else {
                dequeue(&Q, &q);
                printf("Antrian %d telah diproses\n", q);
                printQueue(Q);
            }
            break;
        
        case 3:
            printQueue(Q);
            break;

        case 4:
        
            return 0;

        default:
            printf("Pilihan tidak tersedia\n");
            break;
        }
    }
    return 0;
}