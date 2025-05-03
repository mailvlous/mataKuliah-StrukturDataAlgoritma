#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "history.h"
#include "anggota.h"
#include "queue.h"

char* tanggal_sekarang() {
    return "03-05-2025"; // Bisa diganti dengan tanggal dinamis
}

addressHistory createHistory(char *namaBuku, char *tanggalPinjam, char *tanggalKembali, int status) {
    addressHistory H = (addressHistory)malloc(sizeof(History));
    H->namaBuku = strdup(namaBuku); // gunakan strdup agar tidak share pointer
    H->tanggalPinjam = strdup(tanggalPinjam);
    H->tanggalKembali = (tanggalKembali != NULL) ? strdup(tanggalKembali) : NULL;
    H->status = status;
    H->next = NULL;
    return H;
}





void tambahHistoryAnggota(addressAnggota anggota, addressHistory H) {
    if (anggota->history == NULL) {
        anggota->history = H;
    } else {
        addressHistory temp = anggota->history;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = H;
    }
}

void tambahRiwayatPeminjaman(addressAnggota anggota, const char *namaBuku, const char *tanggalPinjam) {
    if (anggota == NULL) return;

    // Membuat riwayat peminjaman baru
    addressHistory newHistory = (addressHistory)malloc(sizeof(History));
    if (newHistory == NULL) {
        printf("Gagal alokasi memori untuk riwayat peminjaman.\n");
        return;
    }

    // Salin data peminjaman
    newHistory->namaBuku = strdup(namaBuku); // Salin nama buku
    newHistory->tanggalPinjam = strdup(tanggalPinjam); // Salin tanggal pinjam
    newHistory->tanggalKembali = NULL; // Belum dikembalikan
    newHistory->status = 0; // 0 berarti dipinjam
    newHistory->next = NULL;

    // Tambahkan riwayat ke dalam linked list history anggota
    if (anggota->history == NULL) {
        anggota->history = newHistory;  // Jika history kosong, set sebagai head
    } else {
        // Cari akhir dari linked list history dan tambahkan riwayat baru
        addressHistory current = anggota->history;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newHistory;
    }

    printf("Riwayat peminjaman '%s' telah ditambahkan untuk anggota %s.\n", namaBuku, anggota->name);
}

// void printRiwayatPeminjamanByName(addressAnggota head, const char *namaAnggota) {
//     addressAnggota anggota = cariAnggotaByName(head, namaAnggota);

//     if (anggota == NULL) {
//         printf("Anggota dengan nama '%s' tidak ditemukan.\n", namaAnggota);
//         return;
//     }

//     if (anggota->history == NULL) {
//         printf("Tidak ada riwayat peminjaman untuk anggota '%s'.\n", namaAnggota);
//         return;
//     }

//     printf("\nRiwayat Peminjaman untuk %s:\n", namaAnggota);

//     // Jika anggota ditemukan, cetak riwayat peminjamannya
//     addressHistory current = anggota->history;
//     while (current != NULL) {
//         printf("Buku: %s | Tanggal Pinjam: %s | Status: %s\n", 
//                current->namaBuku, 
//                current->tanggalPinjam,
//                current->status == 0 ? "Dipinjam" : "Dikembalikan");
//         current = current->next;
//     }
// }
