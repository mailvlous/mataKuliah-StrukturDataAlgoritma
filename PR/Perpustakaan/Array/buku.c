#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "queue.h"
#include "anggota.h"


void tambahBuku(char *judul, int stok) {
    strcpy(daftarBuku[jumlahBuku].judul, judul);
    daftarBuku[jumlahBuku].stok = stok;
    initQueue(&daftarBuku[jumlahBuku].antrian);
    jumlahBuku++;
}

void listBuku() {
    printf("\n=== Daftar Buku ===\n");
    for (int i = 0; i < jumlahBuku; i++) {
        Buku b = daftarBuku[i];
        printf("Judul: %s | Stok: %d\n", b.judul, b.stok);

        int jumlahAntri = 0;
        if (!isQueueEmpty(b.antrian)) {
            if (b.antrian.rear >= b.antrian.front)
                jumlahAntri = b.antrian.rear - b.antrian.front + 1;
            else
                jumlahAntri = MAX_QUEUE - b.antrian.front + b.antrian.rear + 1;
        }

        if (b.stok == 0 && jumlahAntri > 0) {
            printf("  Antrian:\n");
            int pos = b.antrian.front;
            int urutan = 1;
            while (1) {
                int idxAnggota = b.antrian.data[pos];
                Anggota a = daftarAnggota[idxAnggota];
                printf("    %d. %s (Level %d)\n", urutan, a.name, a.level);

                if (pos == b.antrian.rear) break;
                pos = (pos + 1) % MAX_QUEUE;
                urutan++;
            }
        }
    }
}



void pinjamBuku(int idxAnggota, int idxBuku, char *tanggal) {
    Anggota *a = &daftarAnggota[idxAnggota];
    Buku *b = &daftarBuku[idxBuku];

    if (a->indeksBuku != -1) {
        printf("Anggota sudah meminjam buku lain.\n");
        return;
    }

    if (b->stok > 0) {
        b->stok--;
        a->indeksBuku = idxBuku;

        // Tambah ke history
        addressHistory h = malloc(sizeof(History));
        strcpy(h->namaBuku, b->judul);
        strcpy(h->tanggalPinjam, tanggal);
        strcpy(h->tanggalKembali, "-");
        h->status = 0;
        h->next = a->history;
        a->history = h;

        printf("Buku berhasil dipinjam.\n");
    } else {
        enqueue(&b->antrian, idxAnggota);
        printf("Buku habis, anggota dimasukkan ke antrian.\n");
    }
}

void kembalikanBuku(int idxAnggota, char *tanggal) {
    Anggota *a = &daftarAnggota[idxAnggota];
    if (a->indeksBuku == -1) {
        printf("Tidak ada buku yang sedang dipinjam.\n");
        return;
    }

    Buku *b = &daftarBuku[a->indeksBuku];

    // Update history
    addressHistory h = a->history;
    while (h != NULL) {
        if (h->status == 0 && strcmp(h->namaBuku, b->judul) == 0) {
            strcpy(h->tanggalKembali, tanggal);
            h->status = 1;
            break;
        }
        h = h->next;
    }

    // Kembalikan stok atau berikan ke antrian
    if (!isQueueEmpty(b->antrian)) {
        int nextAnggota = dequeue(&b->antrian);
        daftarAnggota[nextAnggota].indeksBuku = a->indeksBuku;

        addressHistory h2 = malloc(sizeof(History));
        strcpy(h2->namaBuku, b->judul);
        strcpy(h2->tanggalPinjam, tanggal);
        strcpy(h2->tanggalKembali, "-");
        h2->status = 0;
        h2->next = daftarAnggota[nextAnggota].history;
        daftarAnggota[nextAnggota].history = h2;

        printf("Buku langsung diberikan ke anggota dari antrian.\n");
    } else {
        b->stok++;
    }

    a->indeksBuku = -1;
    printf("Buku dikembalikan.\n");
}


int cariIndeksBuku(char *judul) {
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(daftarBuku[i].judul, judul) == 0) {
            return i;
        }
    }
    return -1; // Tidak ditemukan
}

void pinjamBukuByNama(char *namaAnggota, char *namaBuku, char *tanggal) {
    int idxAnggota = cariIndeksAnggota(namaAnggota);
    int idxBuku = cariIndeksBuku(namaBuku);

    if (idxAnggota == -1) {
        printf("Anggota '%s' tidak ditemukan.\n", namaAnggota);
        return;
    }
    if (idxBuku == -1) {
        printf("Buku '%s' tidak ditemukan.\n", namaBuku);
        return;
    }

    pinjamBuku(idxAnggota, idxBuku, tanggal);
}
