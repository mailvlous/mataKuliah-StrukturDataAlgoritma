#include <stdio.h>
#include "dataPenduduk.h"
#include "dataPenduduk.c"
#include <stdlib.h>
#include <string.h>

int main(){
    Kota A[5];
    A[0].kt = strdup("Bandung");
    A[1].kt = strdup("Jakarta");
    A[2].kt = strdup("Semarang");
    A[3].kt = strdup("Surabaya");
    A[4].kt = strdup("Jayapura");


    A[0].penduduk = NULL;
    A[1].penduduk = NULL;
    A[2].penduduk = NULL;
    A[3].penduduk = NULL;
    A[4].penduduk = NULL;
    
    addPenduduk(&A[0], createPenduduk("Amir"));
    addPenduduk(&A[0], createPenduduk("Wahab"));
    addPenduduk(&A[0], createPenduduk("Yahya"));
    
    addPenduduk(&A[1], createPenduduk("Badu"));
    addPenduduk(&A[1], createPenduduk("Hasan"));

    addPenduduk(&A[2], createPenduduk("Budi"));
    addPenduduk(&A[2], createPenduduk("Caca"));

    addPenduduk(&A[3], createPenduduk("Dedi"));

    addPenduduk(&A[4], createPenduduk("Eko"));
    
    printPendudukKota(&A[0]);
    printPendudukKota(&A[1]);
    printPendudukKota(&A[2]);
    printPendudukKota(&A[3]);
    printPendudukKota(&A[4]);

    DeleteKota(&A[0]);
    printPendudukKota(&A[0]);

    return 0;

}