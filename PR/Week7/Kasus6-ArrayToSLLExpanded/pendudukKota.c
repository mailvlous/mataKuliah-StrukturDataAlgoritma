#include "pendudukKota.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// List Kota




// Kota dan Penduduk

Kota createKota(char *kota) {
    Kota K;

    NamaKota(K) = kota;
    ListPenduduk(K) = NULL; 
    return K;
}

address createPenduduk(char *nama, int umur) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P == NULL) {
        printf("Gagal mengalokasikan memori untuk penduduk!\n");
        return NULL;
    }

    Nama(P) = nama; 
    Umur(P) = umur;
    Next(P) = NULL;
    Prev(P) = NULL;
    return P;
}

void Ins_Penduduk(Kota *K, address penduduk) {
    if (Penduduk(K) == NULL) {
        Penduduk(K) = penduduk;
    } else {
        address temp = Penduduk(K);
        while (Next(temp) != NULL) {
            temp = Next(temp);
        }
        Next(temp) = penduduk;
        Prev(penduduk) = temp; 
    }
}


void printKota(Kota K) {
    printf("Nama Kota: %s\n", K.kt);
    
    if (K.penduduk == NULL) {
        printf("Tidak ada penduduk.\n");
        return;
    }

    printf("Penduduk:\n");
    address p = K.penduduk;
    while (p != NULL) {
        printf("Nama: %s, Umur: %d\n", p->nama, p->umur);
        p = p->next;
    }
}



void swap_Penduduk(Kota *K, address pendudukA, address pendudukB) {
    if (pendudukA == NULL || pendudukB == NULL || pendudukA == pendudukB) return;

    address prevA = Prev(pendudukA);
    address nextA = Next(pendudukA);
    address prevB = Prev(pendudukB);
    address nextB = Next(pendudukB);

    if (nextA == pendudukB) { // A di depan B
        Next(pendudukA) = nextB;
        Prev(pendudukB) = prevA;
        Next(pendudukB) = pendudukA;
        Prev(pendudukA) = pendudukB;

        if (nextB != NULL) Prev(nextB) = pendudukA;
        if (prevA != NULL) Next(prevA) = pendudukB;
    } 
    else if (nextB == pendudukA) { // B di depan A
        Next(pendudukB) = nextA;
        Prev(pendudukA) = prevB;
        Next(pendudukA) = pendudukB;
        Prev(pendudukB) = pendudukA;

        if (nextA != NULL) Prev(nextA) = pendudukB;
        if (prevB != NULL) Next(prevB) = pendudukA;
    } 
    else { // A dan B tidak bersebelahan
        if (prevA != NULL) Next(prevA) = pendudukB;
        if (nextA != NULL) Prev(nextA) = pendudukB;
        if (prevB != NULL) Next(prevB) = pendudukA;
        if (nextB != NULL) Prev(nextB) = pendudukA;

        Prev(pendudukA) = prevB;
        Next(pendudukA) = nextB;
        Prev(pendudukB) = prevA;
        Next(pendudukB) = nextA;
    }

    // Jika A atau B adalah kepala list, perbarui kepala
    if (Penduduk(K) == pendudukA) {
        Penduduk(K) = pendudukB;
    } else if (Penduduk(K) == pendudukB) {
        Penduduk(K) = pendudukA;
    }
}


void sort_Umur_Penduduk_Desc(Kota *K) {
    if (K == NULL || Penduduk(K) == NULL) return; 

    address x = Penduduk(K); 

    while (x != NULL) {
        address y = Prev(x); 

        while (y != NULL && Umur(x) > Umur(y)) {
            swap_Penduduk(K, x, y); 
            y = Prev(x); 
        }

        x = Next(x);
    }
}

void sort_Umur_Penduduk_Asc(Kota *K) {
    if (K == NULL || Penduduk(K) == NULL) return; 

    address x = Penduduk(K); 

    while (x != NULL) {
        address y = Prev(x); 

        while (y != NULL && Umur(x) < Umur(y)) {
            swap_Penduduk(K, x, y); 
            y = Prev(x); 
        }

        x = Next(x);
    }
}

void sort_Nama_Penduduk_From_ZtoA(Kota *K) {
    if (K == NULL || Penduduk(K) == NULL) return;

    address x = Penduduk(K);

    while (x != NULL) {
        address y = Prev(x);

        while (y != NULL && strcmp(Nama(x), Nama(y)) > 0) {
            swap_Penduduk(K, x, y);
            y = Prev(x);
        }

        x = Next(x);
    }
} 

void sort_Nama_Penduduk_From_AtoZ(Kota *K) {
    if (K == NULL || Penduduk(K) == NULL) return;

    address x = Penduduk(K);

    while (x != NULL) {
        address y = Prev(x);

        while (y != NULL && strcmp(Nama(x), Nama(y)) < 0) {
            swap_Penduduk(K, x, y);
            y = Prev(x);
        }

        x = Next(x);
    }
} 

void search_Nama(Kota *K, char *nama) {
    if (K == NULL || Penduduk(K) == NULL) return;

    address x = Penduduk(K);

    while (x != NULL) {
        if (Nama(x) == nama) {
            printf("%s Ditemukan", nama);
        }
        x = Next(x);
    }
} 

void delete_Penduduk(address *head, char *nama) {
    if (*head == NULL) return; 

    address current = *head;

    while (current != NULL && strcmp(Nama(current), nama) != 0) {
        current = Next(current);
    }

    if (current == NULL) return; 

    // Jika node yang dihapus adalah head
    if (current == *head) {
        *head = Next(current); // Geser head ke node berikutnya
        if (*head != NULL) Prev(*head) = NULL;
    } else {
        Next(Prev(current)) = Next(current); // Hubungkan prev dengan next
    }

    if (Next(current) != NULL) {
        Prev(Next(current)) = Prev(current); // Hubungkan next dengan prev
    }

    free(Nama(current)); 
    free(current);
}

void hapus_Penduduk(Kota *K, char *nama) {
    if (K == NULL || Penduduk(K) == NULL) return;

    address x = Penduduk(K);

    while (x != NULL) {
        if (strcmp(Nama(x), nama) == 0) {
            delete_Penduduk(&Penduduk(K), nama);
            return; 
        }
        x = Next(x);
    }
}


