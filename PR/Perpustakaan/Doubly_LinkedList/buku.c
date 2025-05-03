#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "buku.h"
#include "anggota.h"
#include "history.h"
#include "catatan.h"


addressBuku createBuku(char *judul, int stok) {
    addressBuku newBuku = (addressBuku)malloc(sizeof(Buku));

    if (newBuku == NULL) {
        printf("Alokasi gagal\n");
        return NULL;
    }

    newBuku->judul = strdup(judul);   // fix: salin string, bukan pointer
    newBuku->stok = stok;
    newBuku->nextBuku = NULL;
    newBuku->antrian.front = NULL;
    newBuku->antrian.rear = NULL;

    return newBuku;
}



void ins_Awal_Buku(addressBuku *head, addressBuku buku) {
    if (buku == NULL) return;

    NextBuku(buku) = *head;
    *head = buku;
}

void printList(addressBuku listBuku) {
    addressBuku currBuku = listBuku;
    
    if (currBuku == NULL) {
        printf("Tidak ada buku dalam daftar.\n");
        return;
    }
    
    printf("\n=== Daftar Buku ===\n");
    while (currBuku != NULL) {
        printf("Judul: %s, Stok: %d\n", currBuku->judul, currBuku->stok);
        
        // Tampilkan antrian anggota
        if (currBuku->antrian.front != NULL) {
            printf("Antrian anggota:\n");
            addressAnggota anggota = currBuku->antrian.front;
            while (anggota != NULL) {
                printf("  - %s (Level %d)\n", anggota->name, anggota->level);
                anggota = anggota->nextQueue;
            }
        }
        currBuku = currBuku->nextBuku;
    }
}



addressBuku cariBuku(addressBuku listBuku, const char *namaBuku) {
    addressBuku current = listBuku;
    while (current != NULL) {
        // Bandingkan judul buku dengan nama yang dicari
        if (strcmp(current->judul, namaBuku) == 0) {
            return current;    // Buku ditemukan
        }
        current = current->nextBuku;
    }
    return NULL;  // Buku tidak ditemukan
}

// void prosesPeminjaman(addressBuku buku) {
//     int stok = buku->stok;
//     addressAnggota current = buku->antrian.front;

//     int processed = 0;

//     // Proses peminjaman sebanyak stok
//     while (current != NULL && processed < stok) {
//         printf("Dipinjam: %s -> %s\n", current->name, buku->judul);
//         current->buku = buku;

//         current = current->nextQueue;
//         processed++;
//     }

//     // Kurangi stok sesuai jumlah yang diproses
//     buku->stok -= processed;

//     // Hapus dari antrian sebanyak yang diproses
//     for (int i = 0; i < processed; i++) {
//         char nama[100];  // buffer untuk nama (tidak digunakan, tapi dibutuhkan oleh Del_Awal)
//         Del_Awal(&buku->antrian.front, nama);

//         // Update rear jika antrian habis
//         if (buku->antrian.front == NULL) {
//             buku->antrian.rear = NULL;
//         }
//     }

//     // Tampilkan sisa antrian (yang belum diproses karena stok habis)
//     if (buku->antrian.front != NULL) {
//         printf("Sisa Antrian \"%s\":\n", buku->judul);
//         int no = 1;
//         current = buku->antrian.front;
//         while (current != NULL) {
//             printf("  %d. %s (Level %d)\n", no++, current->name, current->level);
//             current = current->nextQueue;
//         }
//     } else {
//         printf("Tidak ada sisa antrian untuk \"%s\".\n", buku->judul);
//     }
// }

// void prosesPeminjamanBuku(addressBuku listBuku, char *namaBuku) {
//     addressBuku currBuku = listBuku;

//     // Cari buku berdasarkan nama
//     while (currBuku != NULL && strcmp(currBuku->judul, namaBuku) != 0) {
//         currBuku = currBuku->nextBuku;
//     }

//     if (currBuku == NULL) {
//         printf("Buku '%s' tidak ditemukan.\n", namaBuku);
//         return;
//     }

//     int stok = currBuku->stok;
//     Queue *antrian = &currBuku->antrian;

//     if (stok <= 0) {
//         printf("Stok buku habis, peminjaman ditunda.\n");
//         return;
//     }

//     int processed = 0;
//     addressAnggota current = antrian->front;

//     while (current != NULL && processed < stok) {
//         printf("Dipinjam: %s -> %s\n", current->name, currBuku->judul);
//         current->buku = currBuku;

//         // Tambahkan history (jika kamu punya fungsi ini)
//         // tambahHistory(currBuku->judul, current->name, 0, "Peminjaman");

//         current = current->nextQueue;
//         processed++;
//     }

//     currBuku->stok -= processed;

//     // Hapus sebanyak yang diproses dari antrian
//     for (int i = 0; i < processed; i++) {
//         char tempNama[100]; // untuk buffer Del_Awal
//         Del_Awal(&antrian->front, tempNama);

//         // Update rear jika antrian kosong
//         if (antrian->front == NULL) {
//             antrian->rear = NULL;
//         }
//     }

//     // Tampilkan sisa antrian
//     if (antrian->front != NULL) {
//         printf("Sisa Antrian \"%s\":\n", currBuku->judul);
//         current = antrian->front;
//         int no = 1;
//         while (current != NULL) {
//             printf("  %d. %s (Level %d)\n", no++, current->name, current->level);
//             current = current->nextQueue;
//         }
//     } else {
//         printf("Tidak ada sisa antrian untuk \"%s\".\n", currBuku->judul);
//     }
// }
void prosesPeminjamanBuku(addressBuku *listBuku, char *judulBuku, Queue *q, char *tanggalPinjam) {
    addressBuku buku = cariBukuByNama(*listBuku, judulBuku);
    if (buku == NULL) {
        printf("Buku \"%s\" tidak ditemukan.\n", judulBuku);
        return;
    }

    while (buku->stok > 0 && !isEmptyQueue(*q)) {
        addressAnggota peminjam = dequeueAnggota(q);

        // Cek apakah anggota sedang meminjam buku
        if (peminjam->buku != NULL) {
            printf("Anggota %s sedang meminjam buku lain, tidak bisa meminjam lagi.\n", peminjam->name);
            continue;
        }

        // Kurangi stok buku
        buku->stok--;

        // Tandai bahwa anggota ini sedang meminjam buku ini
        peminjam->buku = buku;

        tambahCatatan(judulBuku, peminjam->name, 1, "Peminjaman");


        // Tambahkan ke riwayat
        addressHistory h = (addressHistory) malloc(sizeof(History));
        h->namaBuku = strdup(judulBuku);
        h->tanggalPinjam = strdup(tanggalPinjam);
        h->tanggalKembali = NULL;
        h->status = 0;
        h->next = NULL;

        // Sisipkan ke awal riwayat (bisa juga di akhir kalau mau)
        h->next = peminjam->history;
        peminjam->history = h;

        printf("Buku \"%s\" berhasil dipinjam oleh %s.\n", judulBuku, peminjam->name);
    }

    if (buku->stok == 0 && !isEmptyQueue(*q)) {
        printf("Stok habis. Beberapa anggota belum kebagian buku.\n");
    }
}





// void prosesPeminjaman(addressBuku buku) {
//     if (buku->stok > 0) {
//         // Jika stok buku > 0, peminjaman langsung tanpa antrian
//         addressAnggota current = buku->antrian.front;
//         if (current != NULL) {
//             // Peminjaman langsung kepada anggota yang ada di depan antrian
//             printf("Peminjaman langsung: %s -> %s\n", current->name, buku->judul);
//             current->buku = buku;  // Tandai buku yang dipinjam oleh anggota

//             // Tambahkan riwayat peminjaman untuk anggota
//             tambahRiwayatPeminjaman(current, buku->judul, "2025-05-03"); // Gantilah tanggal sesuai kebutuhan

//             buku->stok--;  // Kurangi stok buku setelah peminjaman

//             // Hapus anggota yang sudah diproses (dequeue)
//             dequeueAnggota(&buku->antrian);
//         }
//     } else {
//         // Jika stok buku 0, proses antrian
//         int stok = buku->stok;
//         addressAnggota current = buku->antrian.front;

//         int processed = 0;

//         // Urutkan antrian berdasarkan level anggota sebelum peminjaman
//         urutkanAntrianBerdasarkanLevel(&(buku->antrian.front));

//         // Proses peminjaman untuk anggota yang ada di antrian
//         while (current != NULL && processed < stok) {
//             printf("Dipinjam: %s -> %s\n", current->name, buku->judul);
//             current->buku = buku;  // Tandai buku yang dipinjam oleh anggota
            
//             // Tambahkan riwayat peminjaman untuk anggota
//             tambahRiwayatPeminjaman(current, buku->judul, "2025-05-03"); // Gantilah tanggal sesuai kebutuhan

//             current = current->nextQueue;
//             processed++;
//         }

//         buku->stok -= processed;  // Kurangi stok buku sesuai jumlah anggota yang dipinjam

//         // Hapus anggota yang sudah diproses (di-dequeue)
//         for (int i = 0; i < processed; i++) {
//             dequeueAnggota(&buku->antrian);
//         }

//         // Tampilkan sisa antrian jika masih ada anggota yang belum diproses
//         if (buku->antrian.front != NULL) {
//             printf("Sisa Antrian \"%s\":\n", buku->judul);
//             int no = 1;
//             current = buku->antrian.front;
//             while (current != NULL) {
//                 printf("  %d. %s (Level %d)\n", no++, current->name, current->level);
//                 current = current->nextQueue;
//             }
//         } else {
//             printf("Tidak ada anggota dalam antrian untuk buku \"%s\".\n", buku->judul);
//         }
//     }
// }


// void printRiwayatPeminjaman(addressAnggota anggota) {
//     if (anggota == NULL || anggota->history == NULL) {
//         printf("Tidak ada riwayat peminjaman untuk anggota ini.\n");
//         return;
//     }

//     addressHistory current = anggota->history;
//     while (current != NULL) {
//         printf("Buku: %s | Tanggal Pinjam: %s | Status: %s\n", 
//                current->namaBuku, 
//                current->tanggalPinjam,
//                current->status == 0 ? "Dipinjam" : "Dikembalikan");
//         current = current->next;
//     }
// }

void lihatListBuku(addressBuku listBuku) {
    // Misalnya, listBuku adalah pointer ke kepala linked list buku
    addressBuku curr = listBuku;
    if (curr == NULL) {
        printf("Tidak ada buku di perpustakaan.\n");
        return;
    }

    printf("Daftar Buku:\n");
    while (curr != NULL) {
        printf("Judul: %s | Stok: %d\n", curr->judul, curr->stok);
        curr = curr->nextBuku;
    }
}

void tambahBuku(addressBuku *listBuku) {
    addressBuku newBuku = (addressBuku) malloc(sizeof(Buku));
    int stok;

    // Masukkan nama buku
    getchar(); // Buang newline sisa dari input sebelumnya
    printf("Judul buku: ");
    scanf("%99[^\n]", newBuku->judul); getchar();

    // Masukkan stok buku
    printf("Jumlah stok: ");
    scanf("%d", &stok); getchar();

    // Inisialisasi antrian
    newBuku->antrian.front = NULL;
    newBuku->antrian.rear = NULL;

    // Menyambungkan buku ke daftar buku (linked list)
    newBuku->nextBuku = *listBuku;
    *listBuku = newBuku;  // Buku baru menjadi head dari listBuku

    printf("Buku '%s' berhasil ditambahkan dengan stok %d.\n", newBuku->judul, newBuku->stok);
}

void tambahAnggotaKeAntrian(addressBuku listBuku, const char *namaBuku) {
    addressBuku currBuku = listBuku;

    // Cari buku terlebih dahulu
    while (currBuku != NULL) {
        if (strcmp(currBuku->judul, namaBuku) == 0) {
            // Buku ditemukan, kita akan menambahkan anggota ke antrian
            addressAnggota newAnggota = (addressAnggota)malloc(sizeof(Anggota));
            if (newAnggota == NULL) {
                printf("Alokasi memori gagal.\n");
                return;
            }

            newAnggota->name = (char *)malloc(100 * sizeof(char));
            if (newAnggota->name == NULL) {
                printf("Gagal mengalokasikan memori untuk nama anggota.\n");
                free(newAnggota);
                return;
            }

            printf("Masukkan nama anggota: ");
            scanf(" %[^\n]%*c", newAnggota->name); // Menggunakan " %[^\n]%*c" untuk menangani spasi

            printf("Masukkan level anggota (1=biasa, 2=prioritas): ");
            scanf("%d", &newAnggota->level);

            newAnggota->buku = NULL;
            newAnggota->history = NULL;
            newAnggota->nextQueue = NULL;

            // Tambahkan ke antrian
            if (currBuku->antrian.front == NULL) {
                currBuku->antrian.front = newAnggota;
                currBuku->antrian.rear = newAnggota;
            } else {
                currBuku->antrian.rear->nextQueue = newAnggota;
                currBuku->antrian.rear = newAnggota;
            }

            printf("Anggota '%s' berhasil ditambahkan ke antrian buku '%s'.\n", newAnggota->name, currBuku->judul);
            return;
        }
        currBuku = currBuku->nextBuku;
    }

    printf("Buku '%s' tidak ditemukan!\n", namaBuku);
}




void prosesPeminjaman(addressBuku listBuku, const char *namaBuku) {
    addressBuku currBuku = listBuku;
    int stok = 0;

    // Cari buku berdasarkan nama
    while (currBuku != NULL) {
        if (strcmp(currBuku->judul, namaBuku) == 0) {
            stok = currBuku->stok;  // Ambil stok buku
            break;
        }
        currBuku = currBuku->nextBuku;
    }

    // Jika buku tidak ditemukan
    if (currBuku == NULL) {
        printf("Buku dengan judul '%s' tidak ditemukan.\n", namaBuku);
        return;
    }

    // Jika stok buku ada
    if (stok > 0) {
        addressAnggota current = currBuku->antrian.front;
        int peminjamCount = 0;

        // Proses peminjaman untuk anggota yang ada di antrian
        while (current != NULL && peminjamCount < stok) {
            printf("Anggota '%s' dipinjamkan buku '%s'.\n", current->name, currBuku->judul);

            // Catat riwayat peminjaman anggota
            tambahHistory(currBuku->judul, current->name, 0, "Peminjaman", &currBuku->antrian);

            // Setelah peminjaman, pindahkan anggota dari antrian
            addressAnggota temp = current;
            current = current->nextQueue;

            // Hapus anggota yang dipinjam dari antrian
            free(temp);

            peminjamCount++;
        }

        // Update stok buku setelah peminjaman
        currBuku->stok -= peminjamCount;

        printf("%d buku '%s' berhasil dipinjam.\n", peminjamCount, currBuku->judul);
        printf("Sisa stok buku '%s': %d\n", currBuku->judul, currBuku->stok);
    }
    // Jika stok buku tidak cukup, tampilkan antrian yang tersisa
    else {
        printf("Stok buku '%s' sudah habis.\n", namaBuku);
        if (currBuku->antrian.front != NULL) {
            printf("Sisa antrian:\n");
            int no = 1;
            addressAnggota current = currBuku->antrian.front;
            while (current != NULL) {
                printf("  %d. %s (Level %d)\n", no++, current->name, current->level);
                current = current->nextQueue;
            }
        }
    }
}

addressBuku cariBukuByNama(addressBuku listBuku, const char *namaBuku) {
    addressBuku currBuku = listBuku;
    
    while (currBuku != NULL) {
        if (strcmp(currBuku->judul, namaBuku) == 0) {
            return currBuku;  // Buku ditemukan
        }
        currBuku = currBuku->nextBuku;
    }
    
    return NULL;  // Buku tidak ditemukan
}
