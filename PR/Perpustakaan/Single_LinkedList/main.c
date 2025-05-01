#include "buku.h"
#include "anggota.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    Buku ListBuku = NULL;

    ins_Awal_Buku(&ListBuku, createBuku("Harry Potter", 4));
    ins_Awal_Buku(&ListBuku, createBuku("The Hobbit", 3));

    Queue A;

    createQueue(&A);

    enqueueAnggota(&A, createAnggota("Dian", 2));
    enqueueAnggota(&A, createAnggota("Liam", 1));
    enqueueAnggota(&A, createAnggota("Andressa", 2));
    enqueueAnggota(&A, createAnggota("Red", 3));
    enqueueAnggota(&A, createAnggota("Ronny", 3));
    enqueueAnggota(&A, createAnggota("Sam", 2));

    Queue B;

    createQueue(&B);

    enqueueAnggota(&B, createAnggota("Saprayung", 1));


    printQueueAnggota(A);

    printQueueAnggota(B);

    printList(ListBuku);

    sambungkanBukuDenganQueueByNama(&ListBuku, "Harry Potter", B);
    sambungkanBukuDenganQueueByNama(&ListBuku, "The Hobbit", A);

    printList(ListBuku);

    urutkanAntrianBerdasarLevel(&ListBuku, "The Hobbit");

    printList(ListBuku);

    prosesPeminjamanBuku(&ListBuku, "Harry Potter", B);
    prosesPeminjamanBuku(&ListBuku, "The Hobbit", A);

    printList(ListBuku);

    prosesPengembalianBuku(&ListBuku, "The Hobbit", 4);

    printList(ListBuku);
    

}