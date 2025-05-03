#ifndef BUKU_H
#define BUKU_H



// #define Judul(B) (B)->judul
// #define Stok(B) (B)->stok
// #define NextBuku(B) (B)->nextBuku

// typedef struct tBuku *address;

// typedef struct tBuku {
//     char *judul;
//     int stok;
//     address nextBuku;
// }Buku;

// #define Nama(A) (A)->nama
// #define Level(A) (A)->level
// #define Next(A) (A)->next

// typedef struct tAnggota {
//     char *nama;
//     int level;
//     address next; // ini tuh bisa nunjuk buku juga
// }Anggota;

#define Name(P) (P)->name
#define Value(P) (P)->value
#define Tipe(P) (P)->tipe
#define Next(P) (P)->next 

typedef enum {
    TipeAnggota,
    TipeBuku
}Tipe;

typedef struct tNode *address;

typedef struct tNode{
    char *name;
    int value;
    Tipe tipe;
    address next;
}Node;

typedef Node* Buku;

Buku createBuku(char *judul, int stok);

void ins_Awal_Buku(address *head, address buku);

address cariBukuByNama(Buku head, const char* nama);

void printList(address node);

void printListTerfilter(address list);



// void enqueue_AnggotaToBuku(address *head, char namaBuku,  address anggota){
//     if (anggota == NULL) return;

//     Next(anggota) = NULL;

//     if (Tipe(*head) == TipeBuku) {
//         Next(anggota) = *head;
//         *head = anggota;
//         return;
//     }
//     else 
//     {
//         address temp = *head;
//         while (Next(temp) != NULL && Tipe(Next(temp)) != TipeBuku && Value(Next(temp)) != namaBuku) {
//             temp = Next(temp);
//         }
//         Next(temp) = anggota;
//     }
// }






#endif // 
