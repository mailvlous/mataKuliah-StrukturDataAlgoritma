#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <stdio.h>
#include <stdlib.h> // Gunakan <stdlib.h> bukan <malloc.h>
#include "boolean.h"

#define Nil NULL
#define Nilai(P) (P)->nilai_mhs
#define Nama(P) (P)->nama_mhs  // Perbaikan: Menghilangkan indeks [50]
#define Next(P) (P)->next
#define Prev(P) (P)->prev

typedef int nilai;

// Definisi struct Mahasiswa
typedef struct tMahasiswa *address;
typedef struct tMahasiswa {
    nilai nilai_mhs;
    char *nama_mhs;   // Perbaikan: Gunakan char* langsung
    address next;
    address prev;
} Mahasiswa;

// Deklarasi fungsi
address createMahasiswa(char *nama_mhs, nilai nilai_mhs);

void tampil_Mahasiswa(address p);

void Ins_Awal_Mahasiswa(address *p, address Pnew);

#endif
