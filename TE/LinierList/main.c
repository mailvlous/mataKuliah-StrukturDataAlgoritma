#include "linked.h"
#include "linked.c"
#include <stdlib.h>
#include <stdio.h>


int main() {
    address First = NULL; // Pointer ke head linked list
    address Pnew;
    infotype x;

    printf("=== Program Linked List dengan Macro ===\n");

    // Insert di awal
    printf("\nMenambahkan elemen di awal...\n");
    Pnew = (address) malloc(sizeof(ElmtList));
    Info(Pnew) = 10;
    Next(Pnew) = NULL;
    Ins_Awal(&First, Pnew);

    Pnew = (address) malloc(sizeof(ElmtList));
    Info(Pnew) = 20;
    Next(Pnew) = NULL;
    Ins_Awal(&First, Pnew);

    Pnew = (address) malloc(sizeof(ElmtList));
    Info(Pnew) = 30;
    Next(Pnew) = NULL;
    Ins_Awal(&First, Pnew);

    // Menampilkan list
    printf("\nLinked List setelah insert di awal:\n");
    Tampil_List(First);

    // Insert di akhir
    printf("\nMenambahkan elemen di akhir...\n");
    Pnew = (address) malloc(sizeof(ElmtList));
    Info(Pnew) = 40;
    Next(Pnew) = NULL;
    Ins_Akhir(&First, Pnew);

    printf("\nLinked List setelah insert di akhir:\n");
    Tampil_List(First);

    // Hapus elemen pertama
    printf("\nMenghapus elemen pertama...\n");
    Del_Awal(&First, &x);
    printf("Elemen yang dihapus: %d\n", x);

    printf("\nLinked List setelah delete awal:\n");
    Tampil_List(First);

    // Hapus elemen terakhir
    printf("\nMenghapus elemen terakhir...\n");
    Del_Akhir(&First, &x);
    printf("Elemen yang dihapus: %d\n", x);

    printf("\nLinked List setelah delete akhir:\n");
    Tampil_List(First);

    // Hapus elemen setelah node pertama
    printf("\nMenghapus elemen setelah node pertama...\n");
    Del_After(&First, &x);
    printf("Elemen yang dihapus: %d\n", x);

    printf("\nLinked List setelah delete after:\n");
    Tampil_List(First);

    return 0;
}


