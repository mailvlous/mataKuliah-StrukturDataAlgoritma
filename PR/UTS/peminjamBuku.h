#ifndef peminjamBuku_H
#define peminjamBuku_H
#include <stdio.h>
#include <malloc.h>
#include "boolean.h"

#define Nil NULL

#define Nama(P) (*P).nama
#define Level(P) (*P).level
#define Next(P) (*P).next
#define Prev(P) (*P).prev

#define NamaBuku(B) B.nmBuku
#define Peminjam(B) (*B).peminjam
#define StokBuku(B) B.stok

typedef int infotype;
typedef char *infochar;
typedef struct tPeminjam* address;

typedef struct tPeminjam {
	infochar nama;
	infotype level;
	address next;
	address prev;
} Peminjam;

typedef struct {
    char *nmBuku;
	infotype stok;
    address peminjam; 
} Buku;

address createPeminjam(char *nama, int level);

boolean isEmpty(address p);

void Create_Node (address *p);

void Isi_Node (address *p , infotype nilai);

void Tampil_List (address p);

void Ins_Awal (address *p, address PNew);

void Ins_Akhir (address *p, address PNew);

address Search (address p, infotype nilai);

void InsertAfter (address * pBef, address PNew);

void Del_Awal (address * p, infotype * X);

void Del_Akhir (address * p, infotype * X);

void Del_After (address * pBef, infotype * X);

void DeAlokasi (address * p);

int NbElmt (address p);

infotype Min (address p);

infotype Rerata (address p);

address BalikList (address p);



#endif

