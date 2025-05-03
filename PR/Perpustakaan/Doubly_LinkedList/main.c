#include "buku.h"
#include "anggota.h"
#include "queue.h"
#include "history.h"
#include "buku.c"
#include "queue.c"
#include "anggota.c"

#include "history.c"

#include <stdlib.h>
#include <stdio.h>

int main() {
    addressBuku listBuku = NULL;
    int choice;

    do {
        printf("\n=== Menu Perpustakaan ===\n");
        printf("1. Tambah Buku ke List\n");
        printf("2. Tambah Anggota ke Antrian Buku\n");
        printf("3. Proses Peminjaman Buku\n");
        printf("4. Tampilkan Semua Buku dan Antrian\n");
        printf("5. Tampilkan Riwayat Anggota\n");
        printf("6. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &choice); getchar(); // Buang newline

        if (choice == 1) {
            char judul[100];
            int stok;
            printf("Judul buku: ");
            fgets(judul, sizeof(judul), stdin);
            judul[strcspn(judul, "\n")] = '\0';

            printf("Jumlah stok: ");
            scanf("%d", &stok); getchar();

            ins_Awal_Buku(&listBuku, createBuku(judul, stok));
            printf("Buku berhasil ditambahkan.\n");

        } else if (choice == 2) {
            char judul[100];
            printf("Masukkan judul buku yang akan diberi antrian: ");
            fgets(judul, sizeof(judul), stdin);
            judul[strcspn(judul, "\n")] = '\0';

            addressBuku buku = cariBukuByNama(listBuku, judul);
            if (buku == NULL) {
                printf("Buku tidak ditemukan.\n");
                continue;
            }

            Queue q;
            createQueue(&q);
            char nama[100];
            int level;
            char lanjut;
            do {
                printf("Nama anggota: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';
                printf("Level (1=tinggi, 2=sedang, 3=rendah): ");
                scanf("%d", &level); getchar();
                enqueueAnggota(&q, createAnggota(nama, level));

                printf("Tambah anggota lagi? (y/n): ");
                scanf("%c", &lanjut); getchar();
            } while (lanjut == 'y' || lanjut == 'Y');

            sambungkanBukuDenganQueueByNama(&listBuku, judul, &q);
            printf("Antrian berhasil disambungkan ke buku.\n");

        } else if (choice == 3) {
            char judul[100], tanggal[20];
            printf("Judul buku: ");
            fgets(judul, sizeof(judul), stdin);
            judul[strcspn(judul, "\n")] = '\0';
            printf("Tanggal peminjaman (YYYY-MM-DD): ");
            fgets(tanggal, sizeof(tanggal), stdin);
            tanggal[strcspn(tanggal, "\n")] = '\0';

            addressBuku buku = cariBukuByNama(listBuku, judul);
            if (buku == NULL) {
                printf("Buku tidak ditemukan.\n");
                continue;
            }

            urutkanAntrianBerdasarLevel(&listBuku, judul);
            prosesPeminjamanBuku(&listBuku, judul, &buku->antrian, tanggal);

        } else if (choice == 4) {
            printListBukuDanAntrian(listBuku);

        } else if (choice == 5) {
            char nama[100];
            printf("Nama anggota: ");
            fgets(nama, sizeof(nama), stdin);
            nama[strcspn(nama, "\n")] = '\0';
            printRiwayatPeminjamanByName(listBuku, nama);

        } else if (choice == 6) {
            getchar();
            char namaBuku[100];
            printf("Masukkan judul buku yang ingin dikembalikan ");
            fgets(namaBuku, sizeof(namaBuku), stdin);
            namaBuku[strcspn(namaBuku, "\n")] = '\0';
        
            addressBuku buku = cariBukuByNama(listBuku, namaBuku);
            if (buku == NULL) {
                printf("Buku tidak ditemukan.\n");
                break;
            }
            int jumlah;
        
            printf("Masukkan jumlah buku yg ingin dikembalikan: ");
            scanf("%d", &jumlah); getchar(); // buang newline setelah scanf
    
            prosesPengembalianBuku(&listBuku, namaBuku, jumlah);

            break;
        }
        else if (choice == 7) {
            tampilkanHistory();
        }
        else if (choice == 6) {
            printf("Keluar dari program.\n");
        }
        else {
            printf("Pilihan tidak valid.\n");
        }
    } while (choice != 8);

}


// int main() {
//     addressBuku listBuku = NULL;
//     int choice;
//     char namaBuku[100];
//     int stok;

//     do {
//         printf("\n=== Program Perpustakaan ===\n");
//         printf("1. Lihat List Buku\n");
//         printf("2. Tambah Buku\n");
//         printf("3. Tambah Anggota ke Antrian Peminjaman dan Proses Peminjaman\n");
//         printf("4. Kembalikan Buku\n");
//         printf("4. Lihat List dan Antrian\n");
//         printf("5. Exit\n");
//         printf("Masukkan pilihan (1-5): ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 lihatListBuku(listBuku);
//                 break;
//             case 2:
//                 getchar(); // Buang newline sisa dari input sebelumnya
//                 printf("Judul buku: ");
//                 scanf("%99[^\n]", namaBuku); getchar();
                
//                 printf("Jumlah stok: ");
//                 scanf("%d", &stok); getchar();

//                 ins_Awal_Buku(&listBuku, createBuku(namaBuku, stok));
//             break;
//             case 3:{
//                 getchar();
//                 char namaBuku[100];
//                 printf("Masukkan judul buku untuk disambungkan ke queue anggota: ");
//                 fgets(namaBuku, sizeof(namaBuku), stdin);
//                 namaBuku[strcspn(namaBuku, "\n")] = '\0';
            
//                 addressBuku buku = cariBukuByNama(listBuku, namaBuku);
//                 if (buku == NULL) {
//                     printf("Buku tidak ditemukan.\n");
//                     break;
//                 }
//                 Queue queueAnggota;
//                 createQueue(&queueAnggota);

//                 char namaAnggota[100];
//                 int level;
//                 char lanjut;
//                 do {
//                     printf("Nama anggota: ");
//                     fgets(namaAnggota, sizeof(namaAnggota), stdin);
//                     namaAnggota[strcspn(namaAnggota, "\n")] = '\0';
            
//                     printf("Level prioritas (1 = tinggi, 2 = sedang, 3 = rendah): ");
//                     scanf("%d", &level); getchar(); // buang newline setelah scanf
            
//                     enqueueAnggota(&queueAnggota, createAnggota(namaAnggota, level));
            
//                     printf("Tambah anggota lagi? (y/n): ");
//                     scanf("%c", &lanjut); getchar(); // buang newline
//                 } while (lanjut == 'y' || lanjut == 'Y');
            
//                 sambungkanBukuDenganQueueByNama(&listBuku, namaBuku, &queueAnggota);
//                 printf("Queue berhasil disambungkan ke buku '%s'.\n", namaBuku);

//                 urutkanAntrianBerdasarLevel(&listBuku, namaBuku);

//                 prosesPeminjamanBuku(&listBuku, namaBuku, &queueAnggota);

//                 printList(listBuku);

//                 break;
//             }
//             case 4:
//                 getchar();
//                 char namaBuku[100];
//                 printf("Masukkan judul buku yang ingin dikembalikan ");
//                 fgets(namaBuku, sizeof(namaBuku), stdin);
//                 namaBuku[strcspn(namaBuku, "\n")] = '\0';
            
//                 addressBuku buku = cariBukuByNama(listBuku, namaBuku);
//                 if (buku == NULL) {
//                     printf("Buku tidak ditemukan.\n");
//                     break;
//                 }
//                 int jumlah;
            
//                 printf("Masukkan jumlah buku yg ingin dikembalikan: ");
//                 scanf("%d", &jumlah); getchar(); // buang newline setelah scanf
        
//                 prosesPengembalianBuku(&listBuku, namaBuku, jumlah);

//                 break;
//             case 5:
//                 printListBukuDanAntrian(listBuku);
//                 break;
//             case 6:
//                 printf("Keluar dari program...\n");
//                 break;
//             case 7:
//                 printf("Keluar dari program...\n");
//                 break;
//             default:
//                 printf("Pilihan tidak valid. Coba lagi.\n");
//         }
//     } while (choice != 7);

//     return 0;
// }


// int main() {
//     // Membuat buku
//     addressBuku buku1 = createBuku("The Hobbit", 3);
//     addressBuku buku2 = createBuku("Harry Potter", 2);

//     // Membuat anggota
//     addressAnggota anggota1 = createAnggota("Mad", 2);
//     addressAnggota anggota2 = createAnggota("Ken", 1);
//     addressAnggota anggota3 = createAnggota("Andressa", 1);
    
//     // Menambah anggota ke dalam antrian buku
//     Queue queueAnggota = { NULL, NULL };  // Membuat queue anggota
//     enqueueAnggota(&queueAnggota, createAnggota("Mad", 2));
//     enqueueAnggota(&queueAnggota, anggota2);
//     enqueueAnggota(&queueAnggota, anggota3);

//     // Daftar buku
//     buku1->nextBuku = buku2;

//     // Memproses peminjaman
//     prosesPeminjamanBuku(buku1, "The Hobbit", &queueAnggota, "2025-05-03");
//     prosesPeminjamanBuku(buku1, "The Hobbit", &queueAnggota, "2025-05-04");
//     prosesPeminjamanBuku(buku1, "Harry Potter", &queueAnggota, "2025-05-05");

//     // Mencetak riwayat peminjaman
//     printRiwayatPeminjamanByName(anggota1, "Mad");

//     printf("\nRiwayat Peminjaman untuk %s:\n", anggota2->name);
//     printRiwayatPeminjaman(anggota2);

//     printf("\nRiwayat Peminjaman untuk %s:\n", anggota3->name);
//     printRiwayatPeminjaman(anggota3);

//     return 0;
// }

// int main() {
//     addressBuku ListBuku = NULL;

//     ins_Awal_Buku(&ListBuku, createBuku("The Hobbit", 4));

//     printList(ListBuku);

//     Queue A;

//     createQueue(&A);

//     enqueueAnggota(&A, createAnggota("Mad", 2));
//     enqueueAnggota(&A, createAnggota("Ken", 1));
//     enqueueAnggota(&A, createAnggota("Andressa", 1));
//     enqueueAnggota(&A, createAnggota("Liam", 3));
//     enqueueAnggota(&A, createAnggota("Nadila", 3));

//     printQueueAnggota(A);

//     sambungkanBukuDenganQueueByNama(ListBuku, "The Hobbit", A);

//     printList(ListBuku);

//     urutkanAntrianBerdasarLevel(ListBuku, "The Hobbit");

//     printList(ListBuku);

//     prosesPeminjamanBuku(ListBuku, "The Hobbit");

//     printList(ListBuku);


//     // Queue A;
//     // createQueue(&A);

//     // enqueueAnggota(&A, createAnggota("Mad", 2));
//     // enqueueAnggota(&A, createAnggota("Ken", 1));
//     // enqueueAnggota(&A, createAnggota("Andressa", 1));
//     // enqueueAnggota(&A, createAnggota("Liam", 3));
//     // enqueueAnggota(&A, createAnggota("Nadila", 3));

//     // sambungUrutProsesAntrian(ListBuku, "The Hobbit", A);

//     // printList(ListBuku);



// }

// int main() {
//     // 1. Buat list buku dan tambahkan 1 buku
//     addressBuku ListBuku = NULL;
//     ins_Awal_Buku(&ListBuku, createBuku("The Hobbit", 4));

//     // 2. Buat list anggota (sebagai master list, bukan queue)
//     ListAnggota listAnggota;
//     listAnggota.first = NULL;

//     // 3. Tambah anggota ke master list
//     tambahAnggota(&listAnggota, "Ken", 1);
//     tambahAnggota(&listAnggota, "Mad", 2);
//     tambahAnggota(&listAnggota, "Andressa", 1);
//     tambahAnggota(&listAnggota, "Liam", 3);
//     tambahAnggota(&listAnggota, "Nadila", 3);

//     // 4. Buat queue anggota yang ingin meminjam
//     Queue A;
//     createQueue(&A);

//     // 5. Ambil anggota dari master list lalu masukkan ke queue
//     enqueueAnggota(&A, cariAnggotaListAnggota(listAnggota, "Ken"));
//     enqueueAnggota(&A, cariAnggotaListAnggota(listAnggota, "Mad"));
//     enqueueAnggota(&A, cariAnggotaListAnggota(listAnggota, "Andressa"));
//     enqueueAnggota(&A, cariAnggotaListAnggota(listAnggota, "Liam"));
//     enqueueAnggota(&A, cariAnggotaListAnggota(listAnggota, "Nadila"));

//     // 6. Print queue sebelum disambung ke buku
//     printf("\nIsi Queue Sebelum Disambung:\n");
//     printQueueAnggota(A);

//     // 7. Sambungkan queue ke buku "The Hobbit"
//     sambungkanQueueKeBuku(&ListBuku, "The Hobbit", A);

//     // 8. Cetak list buku dan antriannya (sebelum proses)
//     printf("\nList Buku (Sebelum Proses Peminjaman):\n");
//     printList(ListBuku);

//     // 9. Tampilkan history sebelum proses (semuanya kosong)
//     printHistoryByNameListAnggota(listAnggota, "Ken");

//     // 10. Urutkan antrian berdasarkan level tertinggi ke terendah
//     urutkanAntrianBerdasarLevel(ListBuku, "The Hobbit");

//     // 11. Proses peminjaman
//     prosesPeminjaman(ListBuku);

//     // 12. Tampilkan list buku & sisa antrian
//     printf("\nList Buku (Setelah Proses Peminjaman):\n");
//     printList(ListBuku);



//     return 0;
// }

