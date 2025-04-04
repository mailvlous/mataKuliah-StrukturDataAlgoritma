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
    char *nama_mhs;   
    address next;
    address prev;
} Mahasiswa;

// Deklarasi fungsi
address createMahasiswa(char *nama_mhs, nilai nilai_mhs);

void tampil_Mahasiswa_Nama(address p);

void tampil_Mahasiswa_Nilai(address p);

void Ins_Awal_Mahasiswa(address *p, address Pnew);

void hitung_Mahasiswa(address p);

void swap_Mahasiswa(address *head, address mahasiswaA, address mahasiswaB);

void sort_Nilai_Mahasiswa(address *head);

void sort_Nama_Mahasiswa(address *head);

void copy_Mahasiswa_Nilai_70(address p, address *q);

void delete_Mahasiswa(address *head, char *nama);

void delete_Similar_Name_Mahasiswa(address *head);

void delete_All_Mahasiswa(address *head);

#endif
