#include "mahasiswa.h"
#include "mahasiswa.c"
#include <stdlib.h>
#include <stdio.h>


int main() {
    address L1 = NULL;
    address L2 = NULL;

    Ins_Awal_Mahasiswa(&L1, createMahasiswa("Budi", 80));
    Ins_Awal_Mahasiswa(&L1, createMahasiswa("Budi", 80));
    Ins_Awal_Mahasiswa(&L1, createMahasiswa("Asep", 90));
    Ins_Awal_Mahasiswa(&L1, createMahasiswa("Ucok", 85));
    Ins_Awal_Mahasiswa(&L1, createMahasiswa("Dedi", 60));
    Ins_Awal_Mahasiswa(&L1, createMahasiswa("Caca", 50));

    tampil_Mahasiswa(L1);

    swap_Mahasiswa(&L1, L1, Next(L1));

    tampil_Mahasiswa(L1);

    sort_Nilai_Mahasiswa(&L1);

    tampil_Mahasiswa(L1);

    sort_Nama_Mahasiswa(&L1);

    tampil_Mahasiswa(L1);

    hitung_Mahasiswa(L1);

    /*
    copy mahasiswa tuh error gatau kenapa, kalo dijalanin program suka ngecrash
    laptop saya tiba tiba error
    jadi dicomment dulu ya pak
    */

    // copy_Mahasiswa_Nilai_70(L1, &L2); 

    // tampil_Mahasiswa(L1);
    // tampil_Mahasiswa(L2);

    delete_Similar_Name_Mahasiswa(&L2);

    tampil_Mahasiswa(L2);

    // delete_All_Mahasiswa(&L1);

    // delete_All_Mahasiswa(&L2);


}