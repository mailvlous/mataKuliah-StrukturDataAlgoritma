#ifndef listPeminjamanBuku_H
#define listPeminjamanBuku_H

#include "peminjamBuku.h" // "."
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NextBuku(B) (*B).next
#define PeminjamBuku(B) (*B).dataBuku.peminjam
#define DataBuku(B) (*B).dataBuku

#define HeadBuku(B) (*B).head

typedef struct tElmtBuku* addrBuku;
typedef struct tElmtBuku {
    Buku dataBuku;
    addrBuku next;
} ElmtBuku;

typedef struct {
    addrBuku head;
} ListPeminjamanBuku;

#endif