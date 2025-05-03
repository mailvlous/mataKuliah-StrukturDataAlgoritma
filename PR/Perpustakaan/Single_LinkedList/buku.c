#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "buku.h"

Buku createBuku(char *judul, int stok) {
    address newBuku = (address)malloc(sizeof(Node));

    if (newBuku == NULL) {
        printf("Alokasi gagal\n");
        return NULL;
    }

    Name(newBuku) = (char*)malloc(strlen(judul) + 1);
    if (Name(newBuku) == NULL) {
        printf("Alokasi nama gagal\n");
        free(newBuku);
        return NULL;
    }

    strcpy(Name(newBuku), judul);
    Value(newBuku) = stok;
    Tipe(newBuku) = TipeBuku;
    Next(newBuku) = NULL;

    return newBuku;
}


void ins_Awal_Buku(address *head, address buku) {
    if (buku == NULL) return;

    Next(buku) = *head;
    *head = buku;
}

address cariBukuByNama(Buku head, const char* nama) {
    address current = head;
    while (current != NULL) {
        if (Tipe(current) == TipeBuku && strcmp(Name(current), nama) == 0) {
            return current;
        }
        current = Next(current);
    }
    return NULL;
}


void printList(address node) {
    if (node == NULL) {
        printf("{}\n");
        return;
    }

    printf("List: { ");
    while (node != NULL) {
        if (Tipe(node) == TipeAnggota) {
            printf("[ %s | Anggota | Level: %d ]", Name(node), Value(node));
        } else {
            printf("[ %s | Buku | Stok: %d ]", Name(node), Value(node));
        }

        node = Next(node);
        if (node != NULL) {
            printf(" -> ");
        }
    }
    printf("}\n");

    printf("\n");
}

void printListTerfilter(address list) {
    if (list == NULL) {
        printf("{}\n");
        return;
    }

    printf("List: { ");

    while (list != NULL) {
        if (Tipe(list) == TipeBuku) {
            printf("[ %s | Buku | Stok: %d ]", Name(list), Value(list));

            // Hitung jumlah anggota setelah buku ini
            int stok_awal = Value(list);  // Misalnya ini stok setelah prosesPeminjaman
            address anggota = Next(list);
            int totalAnggota = 0;

            address temp = anggota;
            while (temp != NULL && Tipe(temp) == TipeAnggota) {
                totalAnggota++;
                temp = Next(temp);
            }

            int mulaiCetak = (stok_awal < totalAnggota) ? totalAnggota - stok_awal : 0;

            // Cetak hanya yang mengantri
            int i = 0;
            while (anggota != NULL && Tipe(anggota) == TipeAnggota) {
                if (i >= mulaiCetak) {
                    printf(" -> [ %s | Anggota | Level: %d ]", Name(anggota), Value(anggota));
                }
                i++;
                anggota = Next(anggota);
            }

            // Lanjutkan ke node berikutnya setelah anggota
            list = temp;
        } else {
            list = Next(list);
        }

        if (list != NULL && Tipe(list) == TipeBuku) {
            printf(" -> ");
        }
    }

    printf(" }\n");
    
}
