#include <stdio.h>
#include <stdlib.h>
#include "comment_terlama_queue.h"
#include "comment_terlama_queue.c"
#include "comment_terbaru_stack.h"
#include "comment_terbaru_stack.c"
#include "comment.h"
#include "comment.c"

int main() {


    // Ins_Awal(&C, createComment("apa ya"));
    // Ins_Awal(&C, createComment("benar sekali"));
    // Ins_Awal(&C, createComment("aku punya ide"));
    // Ins_Awal(&C, createComment("idenya adalah"));
    // Ins_Awal(&C, createComment("tapi sebenarnya"));

    // enqueue_Comment(&CTerlama, createCommentTerlama("apa ya"));
    // enqueue_Comment(&CTerlama, createCommentTerlama("benar sekali"));
    // enqueue_Comment(&CTerlama, createCommentTerlama("aku punya ide"));
    // enqueue_Comment(&CTerlama, createCommentTerlama("idenya adalah"));
    // enqueue_Comment(&CTerlama, createCommentTerlama("tapi sebenarnya"));
    
    // push_Comment(&CTerbaru, createCommentTerbaru("apa ya"));
    // push_Comment(&CTerbaru, createCommentTerbaru("benar sekali"));
    // push_Comment(&CTerbaru, createCommentTerbaru("aku punya ide"));
    // push_Comment(&CTerbaru, createCommentTerbaru("idenya adalah"));
    // push_Comment(&CTerbaru, createCommentTerbaru("tapi sebenarnya"));

    // printComment(C);

    // printCommentTerlama(CTerlama);

    // printCommentTerbaru(CTerbaru);
    address C = NULL;
    address CTerlama = NULL;
    address CTerbaru = NULL;

    char *comment = (char *)malloc(256 * sizeof(char));
    if (comment == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return 1;
    }

    int choose;

    while (1) {
        printf("\nWelcome\n");
        printf("1. Tambahkan Komentar\n");
        printf("2. Cetak Komentar\n");
        printf("3. Urut berdasarkan komentar terlama\n");
        printf("4. Urut berdasarkan komentar terbaru\n");
        printf("5. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &choose);
        getchar(); 

        switch (choose) {
            case 1:
                printf("Masukkan Komentar: ");
                scanf("%s", comment);

                Ins_Awal(&C, createComment(comment));
                enqueue_Comment(&CTerlama, createComment(comment)); 
                push_Comment(&CTerbaru, createComment(comment)); 
                break;
            case 2:
                printf("\n=== Semua Komentar ===\n");
                printComment(C);
                break;
            case 3:
                printCommentTerlama(CTerlama);
                break;
            case 4:
                printCommentTerbaru(CTerbaru);
                break;
            case 5:
                free(comment);
                exit(0);
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    }

    return 0;

}