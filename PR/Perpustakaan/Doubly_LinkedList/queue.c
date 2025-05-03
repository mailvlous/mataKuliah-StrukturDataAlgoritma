#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "queue.h"

int isQueueEmpty(Queue Q) {
    return (Q.front == NULL);
}

bool isEmptyQueue(Queue q) {
    return q.front == NULL;
}


void createQueue(Queue *p) {
    Front(p) = NULL;
    Rear(p) = NULL;
}

void Ins_Akhir(addressAnggota *p, addressAnggota Pnew) {
    if (Pnew == NULL) return;

    Pnew->nextQueue = NULL;

    if (*p == NULL) {
        *p = Pnew;
    } else {
        addressAnggota last = *p;
        while (last->nextQueue != NULL) {
            last = last->nextQueue;
        }
        last->nextQueue = Pnew;
    }
}

void Del_Awal(addressAnggota *p, char *x) {
    if (*p == NULL) {
        printf("List kosong, tidak bisa delete.\n");
    } else {
        addressAnggota temp = *p;
        strcpy(x, Nama(temp)); // Salin string dari node ke variabel x
        *p = temp->nextQueue;       // Pindahkan head ke node berikutnya
        free(temp);            // Hapus node pertama
    }
}

// void enqueueAnggota(Queue *queue_anggota, addressAnggota anggota){
//     Ins_Akhir(&Front(queue_anggota), anggota);
// }

void enqueueAnggota(Queue *queue_anggota, addressAnggota anggota){
    Ins_Akhir(&Front(queue_anggota), anggota);
}




void printQueueAnggota(Queue q) {
    addressAnggota p = q.front;
    if (p == NULL) {
        printf("Queue kosong.\n");
        return;
    }

    printf("List Anggota Queue:");

    while (p != NULL) {
        printf("[ Name: %s | Level: %d ] -> ", Nama(p), Level(p) );
        p = p->nextQueue;
    }
    
}

addressAnggota dequeueAnggota(Queue *q) {
    if (q->front == NULL) {
        return NULL; // Queue kosong
    }

    addressAnggota temp = q->front;
    q->front = q->front->nextQueue;

    if (q->front == NULL) {
        q->rear = NULL; // Antrian jadi kosong
    }

    temp->nextQueue = NULL; // Putuskan hubungan agar aman
    return temp;
}




void sambungkanQueueKeBuku(addressBuku *ListBuku, char *judul, Queue q) {
    addressBuku p = *ListBuku;
    while (p != NULL && strcmp(p->judul, judul) != 0) {
        p = p->nextBuku;
    }
    if (p != NULL) {
        // Inisialisasi queue kosong di buku
        p->antrian.front = NULL;
        p->antrian.rear = NULL;

        // Salin isi queue q ke p->antrian
        addressAnggota current = q.front;
        while (current != NULL) {
            // Salin node anggota ke antrian buku
            // Penting: jangan buat node baru, cukup referensikan anggota-nya
            enqueueAnggota(&p->antrian, current);
            current = current->nextQueue;
        }
    }
}

void sambungkanBukuDenganQueueByNama(addressBuku *listBuku, const char *namaBuku, Queue *queueAnggota) {
    // Cari buku berdasarkan nama
    addressBuku buku = *listBuku;
    while (buku != NULL) {
        if (strcmp(buku->judul, namaBuku) == 0) {
            // Ambil anggota pertama dari queue
            addressAnggota frontQueue = queueAnggota->front;

            // Jika antrian anggota tidak kosong, sambungkan ke buku
            if (frontQueue != NULL) {
                // Sambungkan anggota pertama ke buku
                buku->antrian.front = frontQueue;  // Buku akan menghubungkan ke anggota pertama dari antrian
                buku->antrian.rear = queueAnggota->rear; // Rear akan mengarah ke anggota terakhir antrian

                // Sambungkan anggota terakhir di antrian ke buku berikutnya (jika ada)
                addressAnggota lastAnggota = frontQueue;
                while (lastAnggota != NULL && lastAnggota->nextQueue != NULL) {
                    lastAnggota = lastAnggota->nextQueue;
                }

                // Sambungkan akhir antrian ke buku berikutnya jika ada
                if (lastAnggota != NULL) {
                    lastAnggota->nextQueue = NULL; // Akhir antrian tidak terhubung ke anggota lain
                }
            }

            printf("Buku '%s' berhasil disambungkan dengan antrian anggota.\n", namaBuku);
            return;
        }
        buku = buku->nextBuku;
    }

    printf("Buku dengan nama '%s' tidak ditemukan!\n", namaBuku);
}




void urutkanAntrianBerdasarLevel(addressBuku *listBuku, const char *namaBuku) {
    addressBuku buku = cariBukuByNama(*listBuku, namaBuku);
    if (buku == NULL) {
        printf("Buku '%s' tidak ditemukan.\n", namaBuku);
        return;
    }
    
    // Jika antrian tidak kosong
    if (buku->antrian.front != NULL) {
        addressAnggota sorted = NULL;
        addressAnggota current = buku->antrian.front;
        
        // Menggunakan insertion sort untuk urutkan antrian berdasarkan level
        while (current != NULL) {
            addressAnggota next = current->nextQueue;
            
            // Tempatkan anggota dalam urutan yang tepat berdasarkan level
            if (sorted == NULL || sorted->level > current->level) {
                current->nextQueue = sorted;
                sorted = current;
            } else {
                addressAnggota temp = sorted;
                while (temp->nextQueue != NULL && temp->nextQueue->level <= current->level) {
                    temp = temp->nextQueue;
                }
                current->nextQueue = temp->nextQueue;
                temp->nextQueue = current;
            }
            
            current = next;
        }
        
        buku->antrian.front = sorted;
    }
}


// void prosesPeminjamanBuku(addressBuku listBuku, const char *namaBuku) {
//     addressBuku curr = listBuku;

//     // Cari buku
//     while (curr != NULL && strcmp(curr->judul, namaBuku) != 0) {
//         curr = curr->nextBuku;
//     }

//     if (curr == NULL) {
//         printf("Buku '%s' tidak ditemukan!\n", namaBuku);
//         return;
//     }

//     int stok = curr->stok;

//     if (stok <= 0) {
//         printf("Stok buku '%s' habis.\n", namaBuku);
//         return;
//     }

//     int peminjamDilayani = 0;
//     while (stok > 0 && curr->antrian.front != NULL) {
//         addressAnggota anggota = curr->antrian.front;

//         // Cek apakah sedang meminjam buku lain
//         if (anggota->buku != NULL) {
//             printf("%s sedang meminjam buku lain. Dilewati.\n", anggota->name);
//             dequeueAnggota(&(curr->antrian));
//             continue;
//         }

//         // Tandai bahwa anggota meminjam buku ini
//         anggota->buku = curr;

//         // Tambah ke history
//         addressHistory newHistory = malloc(sizeof(History));
//         if (newHistory == NULL) {
//             fprintf(stderr, "Gagal alokasi memori untuk history.\n");
//             exit(1);
//         }

//         newHistory->namaBuku = strdup(namaBuku);
//         newHistory->tanggalPinjam = strdup("2025-05-03"); // hardcoded untuk sekarang
//         newHistory->tanggalKembali = NULL;
//         newHistory->status = 0;
//         newHistory->next = anggota->history;
//         anggota->history = newHistory;

//         // Update stok dan antrian
//         curr->stok--;
//         stok--;
//         peminjamDilayani++;

//         dequeueAnggota(&(curr->antrian));
//     }

//     printf("%d anggota telah meminjam buku '%s'.\n", peminjamDilayani, namaBuku);
// }

void printHistory(addressAnggota anggota) {
    printf("Riwayat Peminjaman untuk %s:\n", anggota->name);
    if (anggota->history == NULL) {
        printf("  Tidak ada riwayat.\n");
        return;
    }

    addressHistory h = anggota->history;
    int i = 1;
    while (h != NULL) {
        printf("  %d. Buku: %s | Tanggal Pinjam: %s | ", i++, h->namaBuku, h->tanggalPinjam);
        if (h->tanggalKembali != NULL)
            printf("Tanggal Kembali: %s | Status: Dikembalikan\n", h->tanggalKembali);
        else
            printf("Status: Masih Dipinjam\n");
        h = h->next;
    }
}




void printHistoryQueue(Queue Q) {
    addressAnggota temp = Q.front;
    while (temp != NULL) {
        printHistory(temp);
        temp = temp->nextQueue;
    }
}

addressAnggota cariAnggota(Queue Q, const char* nama) {
    addressAnggota temp = Q.front;
    while (temp != NULL) {
        if (strcmp(temp->name, nama) == 0) {
            return temp;
        }
        temp = temp->nextQueue;
    }
    return NULL; // Jika tidak ditemukan
}

void printHistoryByName(Queue Q, char *nama) {
    addressAnggota temp = Q.front;
    while (temp != NULL) {
        if (strcmp(temp->name, nama) == 0) {
            addressHistory H = temp->history;
            printf("History Peminjaman %s:\n", nama);
            while (H != NULL) {
                printf(" - Buku: %s, Tgl Pinjam: %s, Tgl Kembali: %s, Status: %s\n",
                       H->namaBuku, H->tanggalPinjam,
                       (H->tanggalKembali != NULL) ? H->tanggalKembali : "Belum dikembalikan",
                       (H->status == 0) ? "Dipinjam" : "Dikembalikan");
                H = H->next;
            }
            return;
        }
        temp = temp->nextQueue;
    }
    printf("Anggota %s tidak ditemukan.\n", nama);
}


addressAnggota cariAnggotaDiQueue(Queue A, const char* nama) {
    addressAnggota current = A.front;
    while (current != NULL) {
        if (strcmp(current->name, nama) == 0) {
            return current;
        }
        current = current->nextQueue;
    }
    return NULL; // Anggota tidak ditemukan
}

void printHistoryByNameListAnggota(ListAnggota LA, char *nama) {
    addressAnggota anggota = cariAnggotaListAnggota(LA, nama);
    if (anggota == NULL) {
        printf("Anggota %s tidak ditemukan.\n", nama);
        return;
    }

    printf("Riwayat Peminjaman untuk %s:\n", anggota->name);
    if (anggota->buku != NULL) {
        printf(" - Buku: %s, Tgl Pinjam: 2025-05-03, Tgl Kembali: Belum dikembalikan, Status: Dipinjam\n",
               anggota->buku->judul);
    } else {
        printf("  Tidak ada riwayat.\n");
    }
}





// void sambungUrutProsesAntrian(addressBuku listBuku, const char *namaBuku, Queue q) {
//     addressBuku buku = cariBuku(listBuku, namaBuku);
//     if (buku == NULL) {
//         printf("Buku '%s' tidak ditemukan!\n", namaBuku);
//         return;
//     }

//     // Salin antrian dari q ke buku->antrian
//     addressAnggota temp = q.front;
//     while (temp != NULL) {
//         enqueueAnggota(&(buku->antrian), temp);
//         temp = temp->nextQueue;
//     }

//     // Urutkan antrian di dalam buku
//     urutkanAntrianBerdasarLevel(listBuku, namaBuku);

//     // Proses peminjaman sesuai stok
//     prosesPeminjamanDariAntrian(buku);
// }

addressAnggota findAnggotaByName(Queue *queue, const char *namaAnggota) {
    // Mulai pencarian dari front (anggota pertama)
    addressAnggota current = queue->front;

    // Loop untuk mencari anggota berdasarkan nama
    while (current != NULL) {
        // Bandingkan nama anggota dengan nama yang dicari
        if (strcmp(current->name, namaAnggota) == 0) {
            // Jika nama cocok, kembalikan alamat anggota
            return current;
        }

        // Lanjutkan ke anggota berikutnya
        current = current->nextQueue;
    }

    // Jika tidak ditemukan, kembalikan NULL
    return NULL;
}

void tambahHistory(char *namaBuku, char *namaAnggota, int status, const char *aksi, Queue *queueAnggota) {
    // Mencari anggota berdasarkan nama
    addressAnggota anggota = findAnggotaByName(queueAnggota, namaAnggota); 

    if (anggota != NULL) {
        // Jika anggota ditemukan, tambahkan history
        addressHistory newHistory = (addressHistory)malloc(sizeof(History));
        if (newHistory == NULL) {
            printf("Gagal mengalokasikan memori untuk history.\n");
            return;
        }

        newHistory->namaBuku = strdup(namaBuku);
        newHistory->tanggalPinjam = strdup("21/12/2021"); // Gunakan tanggal sesuai kebutuhan
        newHistory->tanggalKembali = NULL;  // Belum kembali
        newHistory->status = status;
        newHistory->next = anggota->history;
        anggota->history = newHistory;

        printf("Riwayat peminjaman berhasil ditambahkan untuk %s.\n", namaAnggota);
    } else {
        printf("Anggota dengan nama '%s' tidak ditemukan.\n", namaAnggota);
    }
}

// void tambahHistory(char *namaBuku, char *namaAnggota, int status, const char *aksi, Queue *queueAnggota) {
//     // Mencari anggota berdasarkan nama
//     addressAnggota anggota = findAnggotaByName(queueAnggota, namaAnggota); 

//     if (anggota != NULL) {
//         // Jika anggota ditemukan, tambahkan history
//         addressHistory newHistory = (addressHistory)malloc(sizeof(History));
//         if (newHistory == NULL) {
//             printf("Gagal mengalokasikan memori untuk history.\n");
//             return;
//         }

//         newHistory->namaBuku = strdup(namaBuku);
//         newHistory->tanggalPinjam = strdup("21/12/2021"); // Gunakan tanggal sesuai kebutuhan
//         newHistory->tanggalKembali = NULL;  // Belum kembali
//         newHistory->status = status;
//         newHistory->next = anggota->history;
//         anggota->history = newHistory;

//         printf("Riwayat peminjaman berhasil ditambahkan untuk %s.\n", namaAnggota);
//     } else {
//         printf("Anggota dengan nama '%s' tidak ditemukan.\n", namaAnggota);
//     }
// }


void prosesPengembalianBuku(addressBuku *listBuku, const char *namaBuku, int jumlah) {
    // Cari buku berdasarkan nama
    addressBuku curr = *listBuku;
    while (curr != NULL && strcmp(curr->judul, namaBuku) != 0) {
        curr = curr->nextBuku;
    }

    if (curr == NULL) {
        printf("Buku '%s' tidak ditemukan.\n", namaBuku);
        return;
    }

    // Tambahkan stok buku
    curr->stok += jumlah;

    printf("Buku '%s' berhasil dikembalikan sebanyak %d.\n", namaBuku, jumlah);
    printf("Stok sekarang: %d\n", curr->stok);

    // (Optional) Tambah ke history umum atau log (jika ingin)
    // Jika kamu ingin menambahkan riwayat ke masing-masing anggota, 
    // kamu perlu tahu siapa yang mengembalikan — bisa diminta input juga.

    // Contoh input tambahan untuk nama anggota yang mengembalikan:
    /*
    char namaAnggota[100];
    printf("Masukkan nama anggota yang mengembalikan buku: ");
    scanf(" %[^\n]%*c", namaAnggota);
    tambahHistory(namaBuku, namaAnggota, 1, "Pengembalian", &curr->antrian);
    */
}

void printListBukuDanAntrian(addressBuku listBuku) {
    if (listBuku == NULL) {
        printf("Tidak ada buku dalam perpustakaan.\n");
        return;
    }

    printf("\n=== Daftar Buku ===\n");

    addressBuku currBuku = listBuku;
    while (currBuku != NULL) {
        printf("Judul: %s, Stok: %d\n", currBuku->judul, currBuku->stok);

        // Cetak antrian anggota jika stok habis
        if (currBuku->stok == 0 && currBuku->antrian.front != NULL) {
            printf("Antrian anggota:\n");

            addressAnggota currAnggota = currBuku->antrian.front;
            while (currAnggota != NULL) {
                printf("  - %s (Level %d)\n", currAnggota->name, currAnggota->level);
                currAnggota = currAnggota->nextQueue;
            }
        }

        currBuku = currBuku->nextBuku;
    }
}

void printRiwayatPeminjaman(addressAnggota anggota) {
    if (anggota == NULL || anggota->history == NULL) {
        printf("Belum ada riwayat peminjaman.\n");
        return;
    }

    addressHistory curr = anggota->history;
    int i = 1;
    while (curr != NULL) {
        printf("%d. Buku: %s\n", i, curr->namaBuku);
        printf("   Tanggal Pinjam: %s\n", curr->tanggalPinjam);
        if (curr->tanggalKembali != NULL)
            printf("   Tanggal Kembali: %s\n", curr->tanggalKembali);
        else
            printf("   Tanggal Kembali: (Belum dikembalikan)\n");
        printf("   Status: %s\n", curr->status == 1 ? "Dikembalikan" : "Dipinjam");
        curr = curr->next;
        i++;
    }
}

void printRiwayatPeminjamanByName(addressBuku listBuku, char *namaAnggota) {
    addressBuku currentBuku = listBuku;

    while (currentBuku != NULL) {
        // Cek setiap anggota di antrian buku ini
        addressAnggota currAnggota = currentBuku->antrian.front;
        while (currAnggota != NULL) {
            if (strcmp(currAnggota->name, namaAnggota) == 0) {
                printf("\nRiwayat Peminjaman untuk %s:\n", currAnggota->name);
                printRiwayatPeminjaman(currAnggota);
                return;
            }
            currAnggota = currAnggota->nextQueue;
        }

        // Cek juga apakah buku sedang dipinjam oleh anggota (karena bisa saja sudah diambil dari queue)
        if (currentBuku->stok < 1 && currentBuku->antrian.front == NULL && currentBuku->antrian.rear == NULL) {
            addressAnggota peminjam = currentBuku->antrian.front; // bisa disesuaikan sesuai implementasi proses peminjamanmu
            if (peminjam != NULL && strcmp(peminjam->name, namaAnggota) == 0) {
                printf("\nRiwayat Peminjaman untuk %s:\n", peminjam->name);
                printRiwayatPeminjaman(peminjam);
                return;
            }
        }

        currentBuku = currentBuku->nextBuku;
    }

    printf("Anggota dengan nama '%s' tidak ditemukan dalam antrian atau daftar peminjam.\n", namaAnggota);
}
