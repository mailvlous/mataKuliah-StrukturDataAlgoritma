#include "buku.h"
#include "anggota.h"
#include "queue.h"
#include "history.h"
#include "buku.c"
#include "queue.c"
#include "anggota.c"

#include "history.c"

#include "array.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
    array();

    return 0;
}

void array() {
    int pilihan;
    char nama[100], judul[100], tanggal[20];
    int level;

    while (1) {
        printf("\n=== MENU PERPUSTAKAAN ===\n");
        printf("1. Tambah Anggota\n");
        printf("2. Tambah Buku\n");
        printf("3. Pinjam Buku\n");
        printf("4. Kembalikan Buku\n");
        printf("5. Lihat Daftar Buku\n");
        printf("6. Lihat Riwayat Peminjaman\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // menghindari masalah newline di scanf

        switch (pilihan) {
            case 1:
                printf("Nama Anggota: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                printf("Level : ");
                scanf("%d", &level);
                getchar();
                tambahAnggota(nama, level);
                printf("Anggota berhasil ditambahkan.\n");
                break;
            case 2:
                printf("Judul Buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;
                printf("Stok Awal: ");
                scanf("%d", &level);
                getchar();
                tambahBuku(judul, level);
                printf("Buku berhasil ditambahkan.\n");
                break;
            case 3:
                printf("Nama Anggota: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                printf("Judul Buku: ");
                fgets(judul, sizeof(judul), stdin);
                judul[strcspn(judul, "\n")] = 0;
                printf("Tanggal Pinjam (YYYY-MM-DD): ");
                fgets(tanggal, sizeof(tanggal), stdin);
                tanggal[strcspn(tanggal, "\n")] = 0;
                pinjamBukuByNama(nama, judul, tanggal);
                break;
            case 4:
                printf("Nama Anggota: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                printf("Tanggal Kembali (YYYY-MM-DD): ");
                fgets(tanggal, sizeof(tanggal), stdin);
                tanggal[strcspn(tanggal, "\n")] = 0;
                kembalikanBukuByNama(nama, tanggal);
                break;
            case 5:
                listBuku();
                break;
            case 6:
                printf("Nama Anggota: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                tampilkanHistoryByNama(nama);
                break;
            case 0:
                printf("Terima kasih!\n");
                return;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }
}

// int main() {
//     tambahBuku("Algoritma dan Struktur Data", 1);
//     tambahBuku("Dasar Pemrograman", 2);

//     tambahAnggota("Andi", 1);
//     tambahAnggota("Budi", 2);
//     tambahAnggota("Citra", 1);

//     pinjamBukuByNama("Andi", "Algoritma dan Struktur Data", "2025-05-01");
//     pinjamBukuByNama("Budi", "Algoritma dan Struktur Data", "2025-05-01");

//     listBuku();

//     kembalikanBukuByNama("Andi", "25-05-02");
//     kembalikanBukuByNama("Budi", "25-05-02");

//     listBuku();

//     return 0;
// }
