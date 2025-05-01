
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void createQueue(Queue *p) {
    Front(p) = NULL;
    Buku(p) = NULL;
}



void Ins_Akhir(address *p, address Pnew) {
    if (Pnew == NULL) return;

    Pnew->next = NULL;

    if (*p == NULL) {
        *p = Pnew;
    } else {
        address last = *p;
        while (Next(last) != NULL) {
            last = Next(last);
        }
        Next(last) = Pnew;
    }
}

void Del_Awal(address *p, char *x) {
    if (*p == NULL) {
        printf("List kosong, tidak bisa delete.\n");
    } else {
        address temp = *p;
        strcpy(x, Name(temp)); // Salin string dari node ke variabel x
        *p = Next(temp);       // Pindahkan head ke node berikutnya
        free(temp);            // Hapus node pertama
    }
}

void enqueueAnggota(Queue *queue_anggota, address anggota){
    Ins_Akhir(&Front(queue_anggota), anggota);
}




void printQueueAnggota(Queue q) {
    address p = q.front;
    if (p == NULL) {
        printf("Queue kosong.\n");
        return;
    }

    while (p != NULL) {
        printf("[ Name: %s, Value: %d, Tipe: %s ] -> ", Name(p), Value(p), Tipe(p) == TipeBuku ? "Buku" : "Anggota" );
        p = Next(p);
    }
    

    if (q.buku != NULL) {
        printf("Sedang mengantri %s\n", Name(q.buku));
    } else {
        printf("Belum ada buku yang dilayani.\n");
    }
    
}

int hitungQueue(Queue queueAnggota) {
    int count = 0;
    address curr = Front(&queueAnggota);
    while (curr != NULL) {
        count++;
        curr = Next(curr);
    }
    return count;
}



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


bool isEmpty(Queue q) {
    return Front(&q) == NULL;
}

void dequeueAnggota(Queue *q) {
    if (isEmpty(*q)) {
        printf("Queue kosong, tidak bisa dequeue.\n");
        return;
    }

    address hapus = Front(q);          // Simpan node yang akan dihapus
    Front(q) = Next(Front(q));         // Geser front ke node berikutnya
    free(hapus);                       // Bebaskan memori
}


void sambungkanBukuDenganQueue(Buku *listBuku, Queue queueAnggota) {
    address currBuku = *listBuku;
    address nextBuku = NULL;

    if (currBuku != NULL) {
        nextBuku = Next(currBuku); // Simpan next buku

        // Sambungkan anggota queue ke buku saat ini
        Next(currBuku) = Front(&queueAnggota);

        // Temukan anggota terakhir
        address lastAnggota = Front(&queueAnggota);
        while (lastAnggota != NULL && Next(lastAnggota) != NULL) {
            lastAnggota = Next(lastAnggota);
        }

        // Sambungkan akhir dari anggota ke buku berikutnya
        if (lastAnggota != NULL) {
            Next(lastAnggota) = nextBuku;
        }
    }
}


void prosesPeminjaman(address listGabungan) {
    address curr = listGabungan;

    while (curr != NULL) {
        if (Tipe(curr) == TipeBuku) {
            int jumlahAntrian = 0;
            address scan = Next(curr);

            // Hitung anggota setelah buku
            while (scan != NULL && Tipe(scan) == TipeAnggota) {
                jumlahAntrian++;
                scan = Next(scan);
            }

            // Kurangi stok buku
            Value(curr) -= jumlahAntrian;
            if (Value(curr) < 0) Value(curr) = 0;
        }

        curr = Next(curr);
    }
}

void prosesPeminjamanTerbatas(Buku listBuku, Queue queueAnggota) {
    address curr = listBuku;

    while (curr != NULL) {
        if (Tipe(curr) == TipeBuku) {
            while (Value(curr) > 1 && !isEmpty(queueAnggota)) {
                // Langsung pinjam (tanpa antre)
                Value(curr)--;
                dequeueAnggota(&queueAnggota); // hapus dari queue
            }

            if (Value(curr) == 1 && !isEmpty(queueAnggota)) {
                // Stok tinggal 1, mulai antre
                sambungkanBukuDenganQueue(&curr, queueAnggota);
                break; // antrean hanya sekali dihubungkan
            }
        }
        curr = Next(curr);
    }
}


void sambungkanBukuDenganQueueByNama(Buku *listBuku, const char *namaBuku, Queue queueAnggota) {
    address curr = *listBuku;

    // Cari buku berdasarkan nama
    while (curr != NULL) {
        if (Tipe(curr) == TipeBuku && strcmp(Name(curr), namaBuku) == 0) {
            // Simpan pointer ke buku berikutnya
            address nextBuku = Next(curr);

            // Ambil front dari queue
            address frontQueue = Front(&queueAnggota);

            // Jika antrian tidak kosong, sambungkan
            if (frontQueue != NULL) {
                Next(curr) = frontQueue;

                // Temukan anggota terakhir di antrian
                address lastAnggota = frontQueue;
                while (lastAnggota != NULL && Next(lastAnggota) != NULL) {
                    lastAnggota = Next(lastAnggota);
                }

                // Sambungkan akhir antrian ke next buku
                if (lastAnggota != NULL) {
                    Next(lastAnggota) = nextBuku;
                }
            }

            return;
        }
        curr = Next(curr);
    }

    printf("Buku '%s' tidak ditemukan!\n", namaBuku);
}

void urutkanAntrianBerdasarLevel(Buku *listBuku, char *namaBuku) {
    address curr = *listBuku;

    // Cari buku berdasarkan nama
    while (curr != NULL && strcmp(Name(curr), namaBuku) != 0) {
        curr = Next(curr);
    }

    if (curr != NULL && Tipe(curr) == TipeBuku) {
        address head = Next(curr);  // antrian pertama
        address tail = head;

        // Cari sampai node bukan anggota (akhir antrian)
        while (tail != NULL && Tipe(tail) == TipeAnggota) {
            tail = Next(tail);
        }

        // Lakukan bubble sort pointer dari head ke tail (eksklusif)
        int swapped;
        do {
            swapped = 0;
            address prev = NULL;
            address a = head;
            address b = (a != NULL) ? Next(a) : NULL;

            while (b != NULL && b != tail) {
                if (Value(a) > Value(b)) {
                    // Tukar a dan b
                    if (prev == NULL) {
                        Next(curr) = b;
                    } else {
                        Next(prev) = b;
                    }

                    Next(a) = Next(b);
                    Next(b) = a;

                    // Update pointer setelah swap
                    prev = b;
                    b = Next(a);
                    swapped = 1;
                } else {
                    prev = a;
                    a = b;
                    b = Next(b);
                }
            }
            head = Next(curr);
        } while (swapped);
    }
}


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

void prosesPeminjamanBuku(Buku *listBuku, char *namaBuku, Queue queueAnggota) {
    address currBuku = *listBuku;

    // Cari buku
    while (currBuku != NULL && strcmp(Name(currBuku), namaBuku) != 0) {
        currBuku = Next(currBuku);
    }

    if (currBuku != NULL) {
        address nextBuku = NULL;
        address currAnggota = Next(currBuku);
        int stok = Value(currBuku);

        if (stok > 1 && currAnggota != NULL) {
            int jumlahAntrian = 0;
            address temp = currAnggota;
            while (temp != NULL && Tipe(temp) == TipeAnggota) {
                jumlahAntrian++;
                temp = Next(temp);
            }

            nextBuku = temp;
            int bisaDilayani = (stok - 1 < jumlahAntrian) ? stok - 1 : jumlahAntrian;
            Value(currBuku) -= bisaDilayani;

            // Catat history untuk tiap anggota
            address iterAnggota = currAnggota;
            for (int i = 0; i < bisaDilayani && iterAnggota != NULL; i++) {
                if (Tipe(iterAnggota) == TipeAnggota) {
                    tambahHistory(namaBuku, Name(iterAnggota), 1, "Peminjaman");
                }
                iterAnggota = Next(iterAnggota);
            }

            // Lewati anggota yang sudah dilayani
            address iter = currAnggota;
            for (int i = 0; i < bisaDilayani && iter != NULL; i++) {
                iter = Next(iter);
            }

            // Sambungkan sisa antrian (jika masih ada)
            if (iter != NULL && Tipe(iter) == TipeAnggota) {
                Next(currBuku) = iter;
                address last = iter;
                while (last != NULL && Next(last) != NULL && Tipe(Next(last)) == TipeAnggota) {
                    last = Next(last);
                }
                if (last != NULL) {
                    Next(last) = nextBuku;
                }
            } else {
                Next(currBuku) = nextBuku;
            }
        } else if (stok == 1 && currAnggota != NULL && Tipe(currAnggota) == TipeAnggota) {
            address last = currAnggota;
            while (last != NULL && Next(last) != NULL && Tipe(Next(last)) == TipeAnggota) {
                last = Next(last);
            }
            if (last != NULL) {
                Next(last) = Next(last);  // sebenarnya tidak mengubah apapun
            }
        } else {
            Value(currBuku) = stok;
        }
    }
}

void prosesPengembalianBuku(Buku *listBuku, char *namaBuku, int jumlah) {
    address currBuku = *listBuku;

    // Cari buku
    while (currBuku != NULL && strcmp(Name(currBuku), namaBuku) != 0) {
        currBuku = Next(currBuku);
    }

    if (currBuku != NULL && Tipe(currBuku) == TipeBuku) {
        Value(currBuku) += jumlah;

        address curr = Next(currBuku);
        int stok = Value(currBuku);
        int bisaLangsungPinjam = stok - 1;
        address prev = currBuku;

        while (curr != NULL && Tipe(curr) == TipeAnggota && bisaLangsungPinjam > 0) {
            Next(prev) = Next(curr);
            free(curr); // jika pakai malloc
            curr = Next(prev);
            Value(currBuku)--; // kurangi stok karena langsung dipinjam
            bisaLangsungPinjam--;
        }

        // Tambahkan catatan pengembalian
        tambahHistory(namaBuku, NULL, jumlah, "Pengembalian");
    } else {
        printf("Buku '%s' tidak ditemukan!\n", namaBuku);
    }
}
