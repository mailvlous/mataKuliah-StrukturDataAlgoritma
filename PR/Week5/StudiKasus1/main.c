#include "mahasiswa.h"
#include "mahasiswa.c"
#include <stdlib.h>
#include <stdio.h>

int main() {
    address mhs = Nil;

    mhs = createMahasiswa("Asep", 100);

    tampil_Mahasiswa(mhs);
    return 0;
}