#ifndef HISTORY_H
#define HISTORY_H

typedef struct tHistory *addressHistory;

typedef struct tHistory {
    char namaBuku[100];
    char tanggalPinjam[15];
    char tanggalKembali[15]; // kosong jika belum dikembalikan
    int status;
    addressHistory next;
} History;

void tampilkanHistory(int idxAnggota);

void tampilkanHistoryByNama(char *namaAnggota);



#endif