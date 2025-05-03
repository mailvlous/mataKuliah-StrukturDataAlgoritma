#ifndef CATATAN_H
#define CATATAN_H

typedef struct {
    char namaBuku[100];
    char namaAnggota[100];
    int jumlah; // Jumlah buku yang dipinjam atau dikembalikan
    char tipeTransaksi[20]; // "Peminjaman" atau "Pengembalian"
    char tanggal[20]; // Tanggal transaksi
} History;

History historyList[100]; // Array untuk menyimpan catatan transaksi
int historyCount = 0; // Untuk menghitung jumlah transaksi

void tambahHistory(char *namaBuku, char *namaAnggota, int jumlah, char *tipeTransaksi);

void tampilkanHistory();

#endif // !CATATAN_H

