

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "buku.h"
#include "buku.c"
#include "anggota.h"
#include "anggota.c"
#include "queue.h"
#include "queue.c"
#include "catatan.h"
#include "catatan.c"
#include "single.h"

int main() {
    single();

    return 0;
}

void single() {
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
        printf("3. Tambah anggota ke Antrian Peminjaman dan Proses Peminjaman\n");
        printf("4. Proses Pengembalian\n");
        printf("5. Tampilkan History\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printList(ListBuku);
                break;
            case 2: 
                getchar(); // Buang newline sisa dari input sebelumnya
                printf("Judul buku: ");
                scanf("%99[^\n]", namaBuku); getchar();
                
                printf("Jumlah stok: ");
                scanf("%d", &stok); getchar();

                ins_Awal_Buku(&ListBuku, createBuku(namaBuku, stok));
                break;
            
            case 3: {
                getchar();
                char namaBuku[100];
                printf("Masukkan judul buku untuk disambungkan ke queue anggota: ");
                fgets(namaBuku, sizeof(namaBuku), stdin);
                namaBuku[strcspn(namaBuku, "\n")] = '\0';
            
                address buku = cariBukuByNama(ListBuku, namaBuku);
                if (buku == NULL) {
                    printf("Buku tidak ditemukan.\n");
                    break;
                }
            
                // Buat queue baru
                Queue antrian;
                createQueue(&antrian);
            
                // Input anggota satu per satu
                char namaAnggota[100];
                int level;
                char lanjut;
            
                do {
                    printf("Nama anggota: ");
                    fgets(namaAnggota, sizeof(namaAnggota), stdin);
                    namaAnggota[strcspn(namaAnggota, "\n")] = '\0';
            
                    printf("Level prioritas (1 = tinggi, 2 = sedang, 3 = rendah): ");
                    scanf("%d", &level); getchar(); // buang newline setelah scanf
            
                    enqueueAnggota(&antrian, createAnggota(namaAnggota, level));
            
                    printf("Tambah anggota lagi? (y/n): ");
                    scanf("%c", &lanjut); getchar(); // buang newline
                } while (lanjut == 'y' || lanjut == 'Y');
            
                sambungkanBukuDenganQueueByNama(&ListBuku, namaBuku, antrian);
                printf("Queue berhasil disambungkan ke buku '%s'.\n", namaBuku);

                urutkanAntrianBerdasarLevel(&ListBuku, namaBuku);

                prosesPeminjamanBuku(&ListBuku, namaBuku, antrian);

                break;
                }
            case 4:
                getchar();
                char namaBuku[100];
                printf("Masukkan judul buku yang ingin dikembalikan ");
                fgets(namaBuku, sizeof(namaBuku), stdin);
                namaBuku[strcspn(namaBuku, "\n")] = '\0';
            
                address buku = cariBukuByNama(ListBuku, namaBuku);
                if (buku == NULL) {
                    printf("Buku tidak ditemukan.\n");
                    break;
                }
                int jumlah;
            
                printf("Masukkan jumlah buku yg ingin dikembalikan: ");
                scanf("%d", &jumlah); getchar(); // buang newline setelah scanf
        
                prosesPengembalianBuku(&ListBuku, namaBuku, jumlah);

                break;
            case 5:
                tampilkanHistory();
                break;
            
            case 6:
                printf("Exit...");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    
}