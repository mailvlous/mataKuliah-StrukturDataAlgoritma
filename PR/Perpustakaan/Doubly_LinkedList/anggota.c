#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "buku.h"
#include "history.h"
#include "anggota.h"
#include "queue.h"


addressAnggota createAnggota(const char *name, int level) {
    addressAnggota newNode = malloc(sizeof(Anggota));
    if (!newNode) return NULL;

    newNode->name = strdup(name);  // aman: salin ke memori baru
    // if (!newNode->name) {
    //     free(newNode);
    //     return NULL;
    // }

    newNode->level = level;
    newNode->nextQueue = NULL;
    newNode->history = NULL;
    newNode->buku = NULL;
    return newNode;
}


void tambahAnggota(ListAnggota *LA, char *nama, int level) {
    addressAnggota baru = (addressAnggota) malloc(sizeof(Anggota));
    strcpy(baru->name, nama);
    baru->level = level;
    baru->buku = NULL;
    baru->next = NULL;
    baru->nextQueue = NULL;

    if (LA->first == NULL) {
        LA->first = baru;
    } else {
        addressAnggota p = LA->first;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = baru;
    }
}

addressAnggota cariAnggotaListAnggota(ListAnggota LA, char *nama) {
    addressAnggota p = LA.first;
    while (p != NULL) {
        if (strcmp(p->name, nama) == 0) return p;
        p = p->next;
    }
    return NULL;
}

// Fungsi untuk mencari anggota berdasarkan nama
addressAnggota cariAnggotaByName(addressAnggota head, const char *nama) {
    addressAnggota current = head;
    while (current != NULL) {
        if (strcmp(current->name, nama) == 0) {
            return current; // Ditemukan
        }
        current = current->nextQueue;
    }
    return NULL; // Tidak ditemukan
}

void tampilkanRiwayatPeminjaman(addressAnggota anggotaList, const char *namaAnggota) {
    addressAnggota anggota = cariAnggotaByName(anggotaList, namaAnggota);
    
    if (anggota == NULL) {
        printf("Anggota dengan nama '%s' tidak ditemukan.\n", namaAnggota);
        return;
    }

    if (anggota->history == NULL) {
        printf("Tidak ada riwayat peminjaman untuk anggota '%s'.\n", namaAnggota);
        return;
    }

    addressHistory current = anggota->history;
    while (current != NULL) {
        printf("Buku: %s | Tanggal Pinjam: %s | Status: %s\n", 
               current->namaBuku, 
               current->tanggalPinjam,
               current->status == 0 ? "Dipinjam" : "Dikembalikan");
        current = current->next;
    }
}



// Fungsi untuk mencetak riwayat peminjaman berdasarkan nama anggota




// void enqueue(QueueAnggota *Q, addressAnggota anggota) {
//     anggota->nextQueue = NULL;
//     if (Q->front == NULL) {
//         Q->front = Q->rear = anggota;
//     } else {
//         Q->rear->nextQueue = anggota;
//         Q->rear = anggota;
//     }
// }

// void dequeue(QueueAnggota *Q) {
//     if (Q->front == NULL) return;
//     addressAnggota temp = Q->front;
//     Q->front = Q->front->nextQueue;
//     if (Q->front == NULL) Q->rear = NULL;
//     temp->nextQueue = NULL;  // tidak di-free karena masih dipakai
// }

