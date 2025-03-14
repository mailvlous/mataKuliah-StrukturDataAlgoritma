#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mahasiswa.h"



address createMahasiswa(char *nama_mhs, nilai nilai_mhs) {
    address P = (address)malloc(sizeof(Mahasiswa)); // Alokasi memori
    if (P != NULL) {
        Nilai(P) = nilai_mhs;
        Nama(P) = (char *)malloc(strlen(nama_mhs) + 1); // Alokasi memori untuk nama
        if (Nama(P) != NULL) {
            strcpy(Nama(P), nama_mhs); // Menyalin string nama
        }
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}

void Ins_Awal_Mahasiswa(address *p, address Pnew) {
    if (Pnew == NULL) return;

    Next(Pnew) = *p;
    *p = Pnew;
}

void tampil_Mahasiswa(address p) {
    while (p != Nil) {
        printf("Nama: %s, Nilai: %d\n", Nama(p), Nilai(p));
        p = Next(p);
    }
}