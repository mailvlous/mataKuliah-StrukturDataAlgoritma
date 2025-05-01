#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 100


// History Log
char historyLog[MAX_HISTORY][200];
int jumlahHistory = 0;

// Fungsi untuk menambahkan history
void tambahHistory(const char* action, const char* anggota, const char* buku) {
    if (jumlahHistory < MAX_HISTORY) {
        sprintf(historyLog[jumlahHistory++], "%s %s \"%s\"", anggota, action, buku);
    }
}

