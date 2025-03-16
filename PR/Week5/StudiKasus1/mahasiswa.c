#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mahasiswa.h"



address createMahasiswa(char *nama_mhs, nilai nilai_mhs) {
    address P = (address)malloc(sizeof(Mahasiswa)); 
    if (P != NULL) {
        Nilai(P) = nilai_mhs;
        Nama(P) = (char *)malloc(strlen(nama_mhs) + 1); 
        if (Nama(P) != NULL) {
            strcpy(Nama(P), nama_mhs); 
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

    printf("Address Mahasiswa: %p\n", *p);
    while (p != Nil) {
        printf("[Nama: %s, Nilai: %d] - > ", Nama(p), Nilai(p));
        p = Next(p);

    }
    printf("NULL\n");
}


void hitung_Mahasiswa(address p) {
    int jumlah = 0;
    while (p != Nil) {
        jumlah++;
        p = Next(p);
    }
    printf("Jumlah Mahasiswa: %d\n", jumlah);
}

// void swap_Mahasiswa(address *head, address mahasiswaA, address mahasiswaB) {
//     if (mahasiswaA == Nil || mahasiswaB == Nil) {
//         return;
//     }

//     if (mahasiswaA == mahasiswaB) {
//         return;
//     }

//     if (mahasiswaA == *head) {
//         *head = mahasiswaB;
//     }

//     if (mahasiswaB == *head) {
//         *head = mahasiswaA;
//     }

//     address prevMahasiswaA = Prev(mahasiswaA);
//     address nextMahasiswaA = Next(mahasiswaA);
//     address prevMahasiswaB = Prev(mahasiswaB);
//     address nextMahasiswaB = Next(mahasiswaB);

//     /*
//         misal head <-> a <-> b <-> c <-> NULL
//     */

//     if (prevMahasiswaA != Nil) { // jika mahasiswaA bukan head
//         Next(prevMahasiswaA) = mahasiswaB;
//     }

//     if (prevMahasiswaB != Nil) { // jika mahasiswaB bukan head
//         Next(prevMahasiswaB) = mahasiswaA;
//     }

//     /*
//         misal head <-> a <-> b <-> c <-> NULL
//     */

//     Prev(mahasiswaA) = prevMahasiswaB;
//     Next(mahasiswaA) = nextMahasiswaB;

//     Prev(mahasiswaB) = prevMahasiswaA;
//     Next(mahasiswaB) = nextMahasiswaA;

//     if (nextMahasiswaA != Nil) {
//         Prev(nextMahasiswaA) = mahasiswaA;
//     }

//     if (nextMahasiswaB != Nil) {
//         Prev(nextMahasiswaB) = mahasiswaB;
//     }

// }

void swap_Mahasiswa(address *head, address mahasiswaA, address mahasiswaB) {
    if (mahasiswaA == Nil || mahasiswaB == Nil || mahasiswaA == mahasiswaB) {
        return; // Tidak perlu swap jika salah satu NULL atau sama
    }

    address prevA = Prev(mahasiswaA);
    address nextA = Next(mahasiswaA);
    address prevB = Prev(mahasiswaB);
    address nextB = Next(mahasiswaB);

    // Jika A dan B bersebelahan (A <-> B)
    if (nextA == mahasiswaB) { // A di depan B
        Next(mahasiswaA) = nextB;
        Prev(mahasiswaB) = prevA;
        Next(mahasiswaB) = mahasiswaA;
        Prev(mahasiswaA) = mahasiswaB;

        if (nextB != Nil) Prev(nextB) = mahasiswaA;
        if (prevA != Nil) Next(prevA) = mahasiswaB;

    } else if (nextB == mahasiswaA) { // B di depan A (B <-> A)
        Next(mahasiswaB) = nextA;
        Prev(mahasiswaA) = prevB;
        Next(mahasiswaA) = mahasiswaB;
        Prev(mahasiswaB) = mahasiswaA;

        if (nextA != Nil) Prev(nextA) = mahasiswaB;
        if (prevB != Nil) Next(prevB) = mahasiswaA;

    } else { // Jika A dan B tidak bersebelahan
        // Hubungkan prev dan next node dari A ke B
        if (prevA != Nil) Next(prevA) = mahasiswaB;
        if (nextA != Nil) Prev(nextA) = mahasiswaB;

        // Hubungkan prev dan next node dari B ke A
        if (prevB != Nil) Next(prevB) = mahasiswaA;
        if (nextB != Nil) Prev(nextB) = mahasiswaA;

        // Tukar prev dan next
        Prev(mahasiswaA) = prevB;
        Next(mahasiswaA) = nextB;
        Prev(mahasiswaB) = prevA;
        Next(mahasiswaB) = nextA;
    }

    // Perbarui head jika perlu
    if (*head == mahasiswaA) {
        *head = mahasiswaB;
    } else if (*head == mahasiswaB) {
        *head = mahasiswaA;
    }
}


void sort_Nilai_Mahasiswa(address *head) {
    if (*head == NULL || Next(*head) == NULL) return; 

    address current = Next(*head); 

    while (current != NULL) {
        address sorted = Prev(current); 

        while (sorted != NULL && Nilai(current) > Nilai(sorted)) {
            swap_Mahasiswa(head, sorted, current); 
            sorted = Prev(current); 
        }

        current = Next(current);
    }
}

void sort_Nama_Mahasiswa(address *head) {
    if (*head == NULL || Next(*head) == NULL) return; 

    address current = Next(*head); 

    while (current != NULL) {
        address sorted = Prev(current); 

        while (sorted != NULL && strcmp(Nama(current), Nama(sorted)) < 0) {
            swap_Mahasiswa(head, sorted, current); 
            sorted = Prev(current); 
        }

        current = Next(current);
    }
}

void copy_Mahasiswa_Nilai_70(address p, address *q) {
    while (p != Nil) {
        address Pnew = createMahasiswa(Nama(p), Nilai(p));
        if (Nilai(p) >= 70) {
            Ins_Awal_Mahasiswa(q, Pnew);
            p = Next(p);
        }

    }
}