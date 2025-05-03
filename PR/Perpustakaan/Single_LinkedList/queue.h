#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "buku.h"
#include "anggota.h"
#include "catatan.h"

#define Front(P) (P)->front
#define Buku(P) (P)->buku

typedef struct{
    address front;
    address buku;
}Queue;

void createQueue(Queue *p);


void Ins_Akhir(address *p, address Pnew);

void Del_Awal(address *p, char *x);

void enqueueAnggota(Queue *queue_anggota, address anggota);
void printQueueAnggota(Queue q);

int hitungQueue(Queue queueAnggota);


// void sambungkanBukuDenganQueue(Buku *listBuku, Queue queueAnggota) {
//     address currBuku = *listBuku;
//     address nextBuku = NULL;

//     if (currBuku != NULL) {
//         nextBuku = Next(currBuku); // Simpan next buku

//         // Sambungkan anggota queue ke buku saat ini
//         Next(currBuku) = Front(&queueAnggota);
        

//         // Temukan anggota terakhir
//         address lastAnggota = Front(&queueAnggota);
//         while (lastAnggota != NULL && Next(lastAnggota) != NULL) {
//             lastAnggota = Next(lastAnggota);
//         }

//         // Sambungkan akhir dari anggota ke buku berikutnya
//         if (lastAnggota != NULL) {
//             Next(lastAnggota) = nextBuku;
//         }
//     }
// }


bool isEmpty(Queue q);

void dequeueAnggota(Queue *q);

void sambungkanBukuDenganQueue(Buku *listBuku, Queue queueAnggota);

void prosesPeminjaman(address listGabungan);

void prosesPeminjamanTerbatas(Buku listBuku, Queue queueAnggota);

void sambungkanBukuDenganQueueByNama(Buku *listBuku, const char *namaBuku, Queue queueAnggota);

void urutkanAntrianBerdasarLevel(Buku *listBuku, char *namaBuku);


// void prosesPeminjamanBuku(Buku *listBuku, char *namaBuku, Queue queueAnggota) {
//     address currBuku = *listBuku;

//     // Cari buku
//     while (currBuku != NULL && strcmp(Name(currBuku), namaBuku) != 0) {
//         currBuku = Next(currBuku);
//     }

//     if (currBuku != NULL) {
//         address nextBuku = NULL;
//         address currAnggota = Next(currBuku); // Karena sebelumnya sudah disambung
//         int stok = Value(currBuku);

//         if (stok > 1 && currAnggota != NULL) {
//             // Hitung anggota antrian
//             int jumlahAntrian = 0;
//             address temp = currAnggota;
//             while (temp != NULL && Tipe(temp) == TipeAnggota) {
//                 jumlahAntrian++;
//                 temp = Next(temp);
//             }

//             nextBuku = temp; // Simpan pointer ke node setelah antrian

//             int bisaDilayani = (stok - 1 < jumlahAntrian) ? stok - 1 : jumlahAntrian;
//             Value(currBuku) -= bisaDilayani;

//             // Lewati anggota yang sudah dilayani
//             address iter = currAnggota;
//             for (int i = 0; i < bisaDilayani && iter != NULL; i++) {
//                 iter = Next(iter);
//             }

//             // Sambungkan sisa antrian (jika masih ada)
//             if (iter != NULL && Tipe(iter) == TipeAnggota) {
//                 Next(currBuku) = iter;

//                 address last = iter;
//                 while (last != NULL && Next(last) != NULL && Tipe(Next(last)) == TipeAnggota) {
//                     last = Next(last);
//                 }

//                 if (last != NULL) {
//                     Next(last) = nextBuku;
//                 }
//             } else {
//                 // Tidak ada antrian tersisa
//                 Next(currBuku) = nextBuku;
//             }
//         } else if (stok == 1 && currAnggota != NULL && Tipe(currAnggota) == TipeAnggota) {
//             // Stok tinggal 1 dan antrian masih ada, biarkan sambungan
//             address last = currAnggota;
//             while (last != NULL && Next(last) != NULL && Tipe(Next(last)) == TipeAnggota) {
//                 last = Next(last);
//             }

//             if (last != NULL) {
//                 Next(last) = Next(last);  // sambungkan ke nextBuku kalau ada
//             }
//         } else {
//             // Tidak ada antrian atau stok cukup tapi tidak disambungkan
//             Value(currBuku) = stok; // tetap
//         }
//     }
// }

// void prosesPengembalianBuku(Buku *listBuku, char *namaBuku, int jumlah) {
//     address currBuku = *listBuku;

//     // Cari buku
//     while (currBuku != NULL && strcmp(Name(currBuku), namaBuku) != 0) {
//         currBuku = Next(currBuku);
//     }

//     if (currBuku != NULL && Tipe(currBuku) == TipeBuku) {
//         Value(currBuku) += jumlah;

//         address curr = Next(currBuku);  // antrian anggota
//         int stok = Value(currBuku);
//         int bisaLangsungPinjam = stok - 1;

//         address prev = currBuku;

//         while (curr != NULL && Tipe(curr) == TipeAnggota && bisaLangsungPinjam > 0) {
//             // Hapus anggota dari list (karena sudah pinjam)
//             Next(prev) = Next(curr);
//             free(curr); // jika alokasi dinamis
//             curr = Next(prev);
//             Value(currBuku)--; // stok turun
//             bisaLangsungPinjam--;
//         }
//     } else {
//         printf("Buku '%s' tidak ditemukan!\n", namaBuku);
//     }
// }

void prosesPeminjamanBuku(Buku *listBuku, char *namaBuku, Queue queueAnggota);

void prosesPengembalianBuku(Buku *listBuku, char *namaBuku, int jumlah);

#endif // !QUEUE_H


