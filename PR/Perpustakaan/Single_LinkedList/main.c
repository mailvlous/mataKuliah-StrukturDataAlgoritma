#include "buku.h"
#include "anggota.h"
#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
    // Buku ListBuku = NULL;

    // ins_Awal_Buku(&ListBuku, createBuku("Harry Potter", 4));
    // ins_Awal_Buku(&ListBuku, createBuku("The Hobbit", 3));

    // Queue A;

    // createQueue(&A);

    // enqueueAnggota(&A, createAnggota("Dian", 2));
    // enqueueAnggota(&A, createAnggota("Liam", 1));
    // enqueueAnggota(&A, createAnggota("Andressa", 2));
    // enqueueAnggota(&A, createAnggota("Red", 3));
    // enqueueAnggota(&A, createAnggota("Ronny", 3));
    // enqueueAnggota(&A, createAnggota("Sam", 2));

    // Queue B;

    // createQueue(&B);

    // enqueueAnggota(&B, createAnggota("Saprayung", 1));

    // printQueueAnggota(A);

    // printQueueAnggota(B);

    // printList(ListBuku);

    // sambungkanBukuDenganQueueByNama(&ListBuku, "Harry Potter", B);
    // sambungkanBukuDenganQueueByNama(&ListBuku, "The Hobbit", A);

    // printList(ListBuku);

    // urutkanAntrianBerdasarLevel(&ListBuku, "The Hobbit");

    // printList(ListBuku);

    

    // prosesPeminjamanBuku(&ListBuku, "Harry Potter", B);
    // prosesPeminjamanBuku(&ListBuku, "The Hobbit", A);

    // tampilkanHistory();

    // printList(ListBuku);

    // prosesPengembalianBuku(&ListBuku, "The Hobbit", 4);
    
    // tampilkanHistory();

    // printList(ListBuku);

    int choice;
    char namaBuku[100], namaAnggota[100];
    int stok, level;
    Buku ListBuku = NULL;

    while (1) {
        
        printf("\n=== Program Perpustakaan ===\n");
        printf("1. Lihat List Buku\n");
        printf("2. Tambah Buku\n");
        printf("3. Tambah Antrian Anggota\n");
        printf("4. Proses Peminjaman\n");
        printf("5. Proses Pengembalian\n");
        printf("6. Tampilkan History\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printList(ListBuku);
                break;
            case 2: {
                getchar(); // Buang newline sisa dari input sebelumnya
                printf("Judul buku: ");
                scanf("%99[^\n]", namaBuku); getchar();
                
                printf("Jumlah stok: ");
                scanf("%d", &stok); getchar();

                ins_Awal_Buku(&ListBuku, createBuku(namaBuku, stok));
                break;
            }
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
    
}