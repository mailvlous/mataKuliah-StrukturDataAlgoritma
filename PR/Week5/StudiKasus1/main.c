#include "mahasiswa.h"
#include "mahasiswa.c"
#include <stdlib.h>
#include <stdio.h>


int main() {
    address L1 = Nil;
    address L2 = Nil;

    L1 = createMahasiswa("Asep", 50);
    Ins_Awal_Mahasiswa(&L1, createMahasiswa("Budi", 90));
    Ins_Awal_Mahasiswa(&L1, createMahasiswa("Caca", 100));
    Ins_Awal_Mahasiswa(&L1, createMahasiswa("Dedi", 100));

    tampil_Mahasiswa_Nama(L1);
    tampil_Mahasiswa_Nilai(L1);

    hitung_Mahasiswa(L1);

    nilai_70_Mahasiswa(L1);

    copy_Mahasiswa(L1, &L2);
    tampil_Mahasiswa_Nama(L2);
    return 0;
}