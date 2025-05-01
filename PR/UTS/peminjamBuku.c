#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "peminjamBuku.h"


address createPeminjam(char *nama, int level) {
    address newNode = (address)malloc(sizeof(Peminjam));
    if (newNode == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        exit(1);
    }
    Nama(newNode) = nama;
    Level(newNode) = level;
    Next(newNode) = NULL;
    return newNode;
}


address createPeminjam(char *nama, infotype level) {
    address P = (address)malloc(sizeof(Peminjam));
    if (P == NULL) {
        printf("Gagal mengalokasikan memori untuk penduduk!\n");
        return NULL;
    }

    Nama(P) = nama; 
    (*P).level = level;
    Next(P) = NULL;
    Prev(P) = NULL;
    return P;
}

void Ins_PeminjamBuku (Buku *B, address peminjam) {
    // if (PeminjamBuku(B) == NULL) {
    //     PeminjamBuku(B) = peminjam;
    // } else {
        address temp = PeminjamBuku(B);
        while (Next(temp) != NULL) {
            temp = Next(temp);
        }
        Next(temp) = peminjam;
        Prev(peminjam) = temp; 
    // }
}


void printKota(Kota K) {
    printf("Nama Kota: %s\n", K.kt);
    
    if (K.penduduk == NULL) {
        printf("Tidak ada penduduk.\n");
        return;
    }

    printf("Penduduk:\n");
    address p = K.penduduk;
    while (p != NULL) {
        printf("Nama: %s, Umur: %d\n", p->nama, p->umur);
        p = p->next;
    }
}

boolean isEmpty(address p){
    if (p == NULL){
        return true;
    }
}

// Create Node

void Create_Node (address *p){
    *p = (address) malloc (sizeof(ElmtList));
    Next(*p) = NULL;
    if (*p != NULL){
        printf("Node berhasil dibuat\n");
        printf("\nAlamat Node : %p", *p);
    }
}

address createNode(infotype x){
    address newNode = (address)malloc(sizeof(ElmtList));
    if (newNode == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        exit(1);
    }
    Info(newNode) = x;
    Next(newNode) = NULL;
    return newNode;
}



// Insert Node

void Isi_Node (address *p, infotype x){
    Info(*p) = x;
}

void insertNode(address *p, infotype nilai){
    if (*p == NULL){
        Create_Node(p);
        Info(*p) = nilai;
        Next(*p) = NULL;
    } else {
        address q;
        Create_Node(&q);
        Info(q) = nilai;
        Next(q) = *p;
        *p = q;
    }
}

// Insert at first


void Ins_Awal(address *p, address Pnew) {
    if (Pnew == NULL) return;

    Next(Pnew) = *p;
    *p = Pnew;
}
// void Ins_Awal(address *p, address Pnew) {
//     if (*p == NULL) {
//         *p = Pnew;
//     } else {
//         Next(Pnew) = *p; //Pnew nunjuk ke *p 
//         *p = Pnew; // *p akan di assign Pnew
//     }
// }

// Insert at last

void Ins_Akhir(address *p, address Pnew) {
    if (Pnew == NULL) return;

    Next(Pnew) = NULL;

    if (*p == NULL) {
        *p = Pnew;
    } else {
        address last = *p;
        while (Next(last) != NULL) {
            last = Next(last);
        }
        Next(last) = Pnew;
    }
}

// void Ins_Akhir(address *p, address Pnew) {
//     if (*p == NULL) {
//         *p = Pnew;
//     } else {
//         Next(Pnew) = NULL;
//         address last = *p;
//         /*jadi ini bakal nyari node terakhir atau node yang nextnya itu null*/
//         while(Next(last) != NULL) { 
//             last = Next(last); 
//         }
//         Next(last) = Pnew; // kalo nextnya null, ini bakal di assign Pnew
//     }
// }

// Insert between/after

void InsertAfter(address *pBef, address Pnew) {
    if (*pBef == NULL) {
        *pBef = Pnew;
    } else {
        Next(Pnew) = Next(*pBef); // misal a->b->c. Misal mau nyisipin diantara a dan b
        Next(*pBef) = Pnew;
        /*
        Pnew akan menunjuk ke nextnya a(*pBef) yaitu b
        a sekarang menunjuk ke Pnew
        jadi a->Pnew->b->c->null
        */
    }
}

// Insert between/before

void InsertBefore(address *pAft, address Pnew) {
    if (*pAft == NULL) {
        *pAft = Pnew;
    } else {

    }
}

// Insert value/after

void InsertAfterValue(address *pBef, infotype nilai) {
    if (*pBef == NULL) {
        *pBef = createNode(nilai);
    } else {
        address Pnew = createNode(nilai);
        Next(Pnew) = Next(*pBef);
        Next(*pBef) = Pnew;
    }
}

// Insert value/before



// Search

address Search(address p, infotype nilai){
    if (p == NULL){
        return NULL;
    } else {
        if (Info(p) == nilai){
            return p;
        } else {
            while (Next(p) != NULL){
                p = Next(p);
                if (Info(p) == nilai){
                    return p;
                }
            }
        }
    }
}

// Modify at first
/*inimah sama kayak del awal*/
void Modify_Awal_Address(address *p, address *Pnew) {
    if (*p != NULL) {
        *Pnew = *p;  
        *p = Next(*p); 
        Next(*Pnew) = NULL; 
    }
}



// Modify at last
/*ini sama kayak del akhir*/
void Modify_Akhir_Address(address *p, address *Pnew) {
    if (*p == NULL) {
        *Pnew = NULL;
    } else {
        address last = *p;
        while(Next(last) != NULL) { 
            last = Next(last); 
        }
        *Pnew = last;
    }
}

// Modify between/after

void ModifyAfter(address *pBef, address *Pnew) {
    if (*pBef != NULL && Next(*pBef) != NULL) {
        *Pnew = Next(*pBef); 
        Next(*pBef) = Next(*Pnew);  
    } else {
        *Pnew = NULL;  
    }
}


// Modify between/before

void ModifyBefore(address *pAft, address *Pnew) {
    if (*pAft != NULL && Prev(*pAft) != NULL) {
        *Pnew = Prev(*pAft); 
        Prev(*pAft) = Prev(*Pnew);  
    } else {
        *Pnew = NULL;  
    }
}

// Modify value/after

void ModifyAfterValue(address *pBef, infotype *nilai) {
    if (*pBef != NULL && Next(*pBef) != NULL) {
        Info(Next(*pBef)) = *nilai;  
    }
}

// Modify value/before

void ModifyBeforeValue(address *p, address pAft, infotype *nilai) {
    if (*p == NULL || *p == pAft) {
        *nilai = -1;  // Tidak ada elemen sebelum pAft
        return;
    }

    address prev = NULL, curr = *p;
    while (curr != NULL && Next(curr) != pAft) {  
        prev = curr;
        curr = Next(curr);
    }

    if (curr == NULL) {
        *nilai = -1;  // pAft tidak ditemukan dalam list
    } else {
        Info(prev) = *nilai;  // Modify nilai sebelum pAft
    }
}

// Delete at first

/*ngehapus node tuh sebenernya cuma misahin gak disambungin aja*/
void Del_Awal(address *p, infotype *x) {
    if (*p == Nil) {

    } else {
        address temp = *p; // ambil alamat node pertama, jadi temp sekarng punya Next yang sama kayak *p yaitu nunjuk ke elemen kedua
        *x = Info(temp); // karena temp itu sekarng node pertama maka *x itu info dari node pertama
        *p = Next(temp);//*p atau *First nextnya akan di assign next dari node temp yaitu alamat *p
        free(temp);
    }
}

// Delete at last

void Del_Akhir(address *p, infotype *x) {
    if (*p == Nil) {

    } else if (Next(*p) == Nil) {
        *x = Info(*p);
        free(*p);
        *p = Nil;
    } else {
        address prev = Nil;
        address curr = *p;
        while (Next(curr) != Nil) { //selama belum mencapa nextnya null
            prev = curr;
            curr = Next(curr);
        }
        *x = Info(curr);
        Next(prev) = Nil;
        free(curr);
    }
}


// Delete between/after

void Del_After(address *pBef, infotype *x) {
    if (*pBef == Nil || Next(*pBef) == Nil) {

    } else {
        address temp = Next(*pBef);
        *x = Info(temp);
        Next(*pBef) = Next(temp);
        free(temp);
    }
}

// Delete between/before



// Delete value/after

void Del_After_Value(address *pHead, infotype nilai, infotype *x) {
    if (*pHead == NULL) return; // List kosong

    address curr = *pHead;

    // Cari elemen dengan nilai tertentu
    while (curr != NULL && Info(curr) != nilai) {
        curr = Next(curr);
    }

    // Jika elemen ditemukan dan memiliki elemen setelahnya
    if (curr != NULL && Next(curr) != NULL) {
        address temp = Next(curr);
        *x = Info(temp); // Simpan nilai yang akan dihapus
        Next(curr) = Next(temp); // Lewati node yang akan dihapus
        free(temp); // Hapus dari memori
    }
}

// Delete value/before



// Print

void Tampil_List(address p){
    if (p == NULL) {
        printf("{}");
        return;
    }

    printf("elemen List: ");
    printf("{");
    while (p != NULL) {
        printf("%d,", Info(p));
        p = Next(p);
    }
    printf("}");
    printf("\n");
}



void DeAlokasi(address *p) {
    address temp;
    while (*p != Nil) {
        /*selalu pake temp karena jika langsung free(*p), maka */
        temp = *p; 
        *p = Next(*p);
        free(temp); 

    }
}

int NbElement (address p) {
    int count = 0;
    while (p != Nil) {
        count++;
        p = Next(p);
    }
    return count;
}

infotype Min (address p) {
    infotype min = Info(p);
    while (Next(p) != Nil) {
        p = Next(p);
        if (Info(p) < min) {
            min = Info(p);
        }
    }
    return min;
}

infotype Rerata (address p) {
    int sum = 0;
    int count = 0;
    while (p != Nil) {
        sum = sum + Info(p);
        count++;
        p = Next(p);
    }
    return sum / count;
}

address BalikList(address p) {
    address curr = p;
    address prev = NULL;
    while (curr != NULL) {
        address next = Next(curr);
        Next(curr) = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

address createMahasiswa(char *nama_mhs, nilai nilai_mhs) {
    address P = (address)malloc(sizeof(Mahasiswa)); 
    if (P != NULL) {
        Nilai(P) = nilai_mhs;
        Nama(P) = (char *)malloc(strlen(nama_mhs) + 1); 
        if (Nama(P) != NULL) {
            strcpy(Nama(P), nama_mhs); 
        }
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}

void Ins_Awal_Mahasiswa(address *p, address Pnew) {
    if (Pnew == NULL) return;

    Next(Pnew) = *p;
    *p = Pnew;
}

void tampil_Mahasiswa(address p) {

    printf("Address Mahasiswa: %p\n", *p);
    while (p != Nil) {
        printf("[Nama: %s, Nilai: %d] - > ", Nama(p), Nilai(p));
        p = Next(p);

    }
    printf("NULL\n");
}


void hitung_Mahasiswa(address p) {
    int jumlah = 0;
    while (p != Nil) {
        jumlah++;
        p = Next(p);
    }
    printf("Jumlah Mahasiswa: %d\n", jumlah);
}

// void swap_Mahasiswa(address *head, address mahasiswaA, address mahasiswaB) {
//     if (mahasiswaA == Nil || mahasiswaB == Nil) {
//         return;
//     }

//     if (mahasiswaA == mahasiswaB) {
//         return;
//     }

//     if (mahasiswaA == *head) {
//         *head = mahasiswaB;
//     }

//     if (mahasiswaB == *head) {
//         *head = mahasiswaA;
//     }

//     address prevMahasiswaA = Prev(mahasiswaA);
//     address nextMahasiswaA = Next(mahasiswaA);
//     address prevMahasiswaB = Prev(mahasiswaB);
//     address nextMahasiswaB = Next(mahasiswaB);

//     /*
//         misal head <-> a <-> b <-> c <-> NULL
//     */

//     if (prevMahasiswaA != Nil) { // jika mahasiswaA bukan head
//         Next(prevMahasiswaA) = mahasiswaB;
//     }

//     if (prevMahasiswaB != Nil) { // jika mahasiswaB bukan head
//         Next(prevMahasiswaB) = mahasiswaA;
//     }

//     /*
//         misal head <-> a <-> b <-> c <-> NULL
//     */

//     Prev(mahasiswaA) = prevMahasiswaB;
//     Next(mahasiswaA) = nextMahasiswaB;

//     Prev(mahasiswaB) = prevMahasiswaA;
//     Next(mahasiswaB) = nextMahasiswaA;

//     if (nextMahasiswaA != Nil) {
//         Prev(nextMahasiswaA) = mahasiswaA;
//     }

//     if (nextMahasiswaB != Nil) {
//         Prev(nextMahasiswaB) = mahasiswaB;
//     }

// }

void swap_Mahasiswa(address *head, address mahasiswaA, address mahasiswaB) {
    if (mahasiswaA == Nil || mahasiswaB == Nil || mahasiswaA == mahasiswaB) {
        return; // Tidak perlu swap jika salah satu NULL atau sama
    }

    address prevA = Prev(mahasiswaA);
    address nextA = Next(mahasiswaA);
    address prevB = Prev(mahasiswaB);
    address nextB = Next(mahasiswaB);

    // Jika A dan B bersebelahan (A <-> B)
    if (nextA == mahasiswaB) { // A di depan B
        Next(mahasiswaA) = nextB;
        Prev(mahasiswaB) = prevA;
        Next(mahasiswaB) = mahasiswaA;
        Prev(mahasiswaA) = mahasiswaB;

        if (nextB != Nil) Prev(nextB) = mahasiswaA;
        if (prevA != Nil) Next(prevA) = mahasiswaB;

    } else if (nextB == mahasiswaA) { // B di depan A (B <-> A)
        Next(mahasiswaB) = nextA;
        Prev(mahasiswaA) = prevB;
        Next(mahasiswaA) = mahasiswaB;
        Prev(mahasiswaB) = mahasiswaA;

        if (nextA != Nil) Prev(nextA) = mahasiswaB;
        if (prevB != Nil) Next(prevB) = mahasiswaA;

    } else { // Jika A dan B tidak bersebelahan
        // Hubungkan prev dan next node dari A ke B
        if (prevA != Nil) Next(prevA) = mahasiswaB;
        if (nextA != Nil) Prev(nextA) = mahasiswaB;

        // Hubungkan prev dan next node dari B ke A
        if (prevB != Nil) Next(prevB) = mahasiswaA;
        if (nextB != Nil) Prev(nextB) = mahasiswaA;

        // Tukar prev dan next
        Prev(mahasiswaA) = prevB;
        Next(mahasiswaA) = nextB;
        Prev(mahasiswaB) = prevA;
        Next(mahasiswaB) = nextA;
    }

    // Perbarui head jika perlu
    if (*head == mahasiswaA) {
        *head = mahasiswaB;
    } else if (*head == mahasiswaB) {
        *head = mahasiswaA;
    }
}


void sort_Nilai_Mahasiswa(address *head) {
    if (*head == NULL || Next(*head) == NULL) return; 

    address current = Next(*head); 

    while (current != NULL) {
        address sorted = Prev(current); 

        while (sorted != NULL && Nilai(current) > Nilai(sorted)) {
            swap_Mahasiswa(head, sorted, current); 
            sorted = Prev(current); 
        }

        current = Next(current);
    }
}

void sort_Nama_Mahasiswa(address *head) {
    if (*head == NULL || Next(*head) == NULL) return; 

    address current = Next(*head); 

    while (current != NULL) {
        address sorted = Prev(current); 

        while (sorted != NULL && strcmp(Nama(current), Nama(sorted)) < 0) {
            swap_Mahasiswa(head, sorted, current); 
            sorted = Prev(current); 
        }

        current = Next(current);
    }
}

void copy_Mahasiswa_Nilai_70(address p, address *q) {
    while (p != Nil) {
        if (Nilai(p) >= 70) { 
            address Pnew = createMahasiswa(Nama(p), Nilai(p));
            if (Pnew != NULL) { // Prevent NULL pointer errors
                Ins_Awal_Mahasiswa(q, Pnew);
            }
        }
        p = Next(p); // Move to the next node in every iteration
    }
}

void delete_Mahasiswa(address *head, char *nama) {
    if (*head == NULL) return; 

    address current = *head;

    while (current != NULL && strcmp(Nama(current), nama) != 0) {
        current = Next(current);
    }

    if (current == NULL) return; 

    // Jika node yang dihapus adalah head
    if (current == *head) {
        *head = Next(current); // Geser head ke node berikutnya
        if (*head != NULL) Prev(*head) = NULL;
    } else {
        Next(Prev(current)) = Next(current); // Hubungkan prev dengan next
    }

    if (Next(current) != NULL) {
        Prev(Next(current)) = Prev(current); // Hubungkan next dengan prev
    }

    free(Nama(current)); 
    free(current);
}

void delete_Similar_Name_Mahasiswa(address *head) {
    address current = *head;
    
    while (current != NULL) {
        address next = Next(current);
        while (next != NULL) {
            address temp = Next(next); // Simpan node berikutnya sebelum hapus
            if (strcmp(Nama(current), Nama(next)) == 0) {
                delete_Mahasiswa(head, Nama(next)); // Hapus duplikat
            }
            next = temp; // Lanjut ke node berikutnya
        }
        current = Next(current);
    }
}

void delete_All_Mahasiswa(address *head) {
    address current = *head;
    while (current != NULL) {
        address temp = Next(current); 
        free(Nama(current)); 
        free(current); 
        current = temp; 
    }
    *head = NULL; 
}


// STACK

address createStack (infotype p) {
    return createNode(p);
}

void push (address *p, address PNew) {
    Ins_Awal(p, PNew);
}

void pop (address *p, infotype *x) {
    Del_Awal(p, x);
}

void printStack (address p) {
    Tampil_List(p);
}

void decimalToBiner (int num) {
    address Stack = NULL;

    while (num > 0) {
        address biner = createStack(num % 2);
        Ins_Awal(&Stack, biner);
        num /= 2;
    }

    printStack(Stack);
}

// QUEUE

bool isQueueEmpty(address p){
    isEmpty(p);
}

void create_Queue(address *p){
    createList(p);
}

address createQueue(infotype x){
    address PNew = createNode(x);
    return PNew;
}

void enqueue(address *p, address PNew){
    Ins_Akhir(p, PNew);
}

void dequeue(address *p, infotype *x){
    Del_Awal(p, x);
}

void printQueue(address p){
    Tampil_List(p);
}

// KOTA PENDUDUK


typedef int infotype;
typedef struct tElmtList* address;
typedef struct tElmtList {
    char *nama;
    infotype umur;
    address next;
    address prev;
} ElmtList;

typedef struct {
    char *kt;
    address penduduk; 
} Kota;

typedef struct tElmtKota* addrKota;
typedef struct tElmtKota {
    Kota data;
    addrKota next;
} ElmtKota;

typedef struct {
    addrKota head;
} ListKota;



Kota createKota(char *kota) {
    Kota K;

    NamaKota(K) = kota;
    ListPenduduk(K) = NULL; 
    return K;
}

address createPenduduk(char *nama, int umur) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P == NULL) {
        printf("Gagal mengalokasikan memori untuk penduduk!\n");
        return NULL;
    }

    Nama(P) = nama; 
    Umur(P) = umur;
    Next(P) = NULL;
    Prev(P) = NULL;
    return P;
}

void Ins_Penduduk(Kota *K, address penduduk) {
    if (Penduduk(K) == NULL) {
        Penduduk(K) = penduduk;
    } else {
        address temp = Penduduk(K);
        while (Next(temp) != NULL) {
            temp = Next(temp);
        }
        Next(temp) = penduduk;
        Prev(penduduk) = temp; 
    }
}


void printKota(Kota K) {
    printf("Nama Kota: %s\n", K.kt);
    
    if (K.penduduk == NULL) {
        printf("Tidak ada penduduk.\n");
        return;
    }

    printf("Penduduk:\n");
    address p = K.penduduk;
    while (p != NULL) {
        printf("Nama: %s, Umur: %d\n", p->nama, p->umur);
        p = p->next;
    }
}



void swap_Penduduk(Kota *K, address pendudukA, address pendudukB) {
    if (pendudukA == NULL || pendudukB == NULL || pendudukA == pendudukB) return;

    address prevA = Prev(pendudukA);
    address nextA = Next(pendudukA);
    address prevB = Prev(pendudukB);
    address nextB = Next(pendudukB);

    if (nextA == pendudukB) { // A di depan B
        Next(pendudukA) = nextB;
        Prev(pendudukB) = prevA;
        Next(pendudukB) = pendudukA;
        Prev(pendudukA) = pendudukB;

        if (nextB != NULL) Prev(nextB) = pendudukA;
        if (prevA != NULL) Next(prevA) = pendudukB;
    } 
    else if (nextB == pendudukA) { // B di depan A
        Next(pendudukB) = nextA;
        Prev(pendudukA) = prevB;
        Next(pendudukA) = pendudukB;
        Prev(pendudukB) = pendudukA;

        if (nextA != NULL) Prev(nextA) = pendudukB;
        if (prevB != NULL) Next(prevB) = pendudukA;
    } 
    else { // A dan B tidak bersebelahan
        if (prevA != NULL) Next(prevA) = pendudukB;
        if (nextA != NULL) Prev(nextA) = pendudukB;
        if (prevB != NULL) Next(prevB) = pendudukA;
        if (nextB != NULL) Prev(nextB) = pendudukA;

        Prev(pendudukA) = prevB;
        Next(pendudukA) = nextB;
        Prev(pendudukB) = prevA;
        Next(pendudukB) = nextA;
    }

    // Jika A atau B adalah kepala list, perbarui kepala
    if (Penduduk(K) == pendudukA) {
        Penduduk(K) = pendudukB;
    } else if (Penduduk(K) == pendudukB) {
        Penduduk(K) = pendudukA;
    }
}


void sort_Umur_Penduduk_Desc(Kota *K) {
    if (K == NULL || Penduduk(K) == NULL) return; 

    address x = Penduduk(K); 

    while (x != NULL) {
        address y = Prev(x); 

        while (y != NULL && Umur(x) > Umur(y)) {
            swap_Penduduk(K, x, y); 
            y = Prev(x); 
        }

        x = Next(x);
    }
}

void sort_Umur_Penduduk_Asc(Kota *K) {
    if (K == NULL || Penduduk(K) == NULL) return; 

    address x = Penduduk(K); 

    while (x != NULL) {
        address y = Prev(x); 

        while (y != NULL && Umur(x) < Umur(y)) {
            swap_Penduduk(K, x, y); 
            y = Prev(x); 
        }

        x = Next(x);
    }
}

void sort_Nama_Penduduk_From_ZtoA(Kota *K) {
    if (K == NULL || Penduduk(K) == NULL) return;

    address x = Penduduk(K);

    while (x != NULL) {
        address y = Prev(x);

        while (y != NULL && strcmp(Nama(x), Nama(y)) > 0) {
            swap_Penduduk(K, x, y);
            y = Prev(x);
        }

        x = Next(x);
    }
} 

void sort_Nama_Penduduk_From_AtoZ(Kota *K) {
    if (K == NULL || Penduduk(K) == NULL) return;

    address x = Penduduk(K);

    while (x != NULL) {
        address y = Prev(x);

        while (y != NULL && strcmp(Nama(x), Nama(y)) < 0) {
            swap_Penduduk(K, x, y);
            y = Prev(x);
        }

        x = Next(x);
    }
} 

void search_Nama(Kota *K, char *nama) {
    if (K == NULL || Penduduk(K) == NULL) return;

    address x = Penduduk(K);

    while (x != NULL) {
        if (Nama(x) == nama) {
            printf("%s Ditemukan", nama);
        }
        x = Next(x);
    }
} 

void delete_Penduduk(address *head, char *nama) {
    if (*head == NULL) return; 

    address current = *head;

    while (current != NULL && strcmp(Nama(current), nama) != 0) {
        current = Next(current);
    }

    if (current == NULL) return; 

    // Jika node yang dihapus adalah head
    if (current == *head) {
        *head = Next(current); // Geser head ke node berikutnya
        if (*head != NULL) Prev(*head) = NULL;
    } else {
        Next(Prev(current)) = Next(current); // Hubungkan prev dengan next
    }

    if (Next(current) != NULL) {
        Prev(Next(current)) = Prev(current); // Hubungkan next dengan prev
    }

    free(Nama(current)); 
    free(current);
}

void hapus_Penduduk(Kota *K, char *nama) {
    if (K == NULL || Penduduk(K) == NULL) return;

    address x = Penduduk(K);

    while (x != NULL) {
        if (strcmp(Nama(x), nama) == 0) {
            delete_Penduduk(&Penduduk(K), nama);
            return; 
        }
        x = Next(x);
    }
}

// LIST KOTA

void createListKota(ListKota *L) {
    HeadKota(L) = NULL;

}

addrKota createKotaElmt(char *kota) {
    addrKota K = (addrKota) malloc(sizeof(ElmtKota));
    K->data.kt = strdup(kota);       // Copy nama kota
    PendudukKota(K) = NULL;         // Awalnya belum ada penduduk
    NextKota(K) = NULL;
    return K;
}


void addKota(ListKota *L, addrKota K) {
    if (HeadKota(L) == NULL) {
        HeadKota(L) = K;
    } else {
        addrKota temp = HeadKota(L);
        while (NextKota(temp) != NULL) {
            temp = NextKota(temp);
        }
        NextKota(temp) = K;
    }
}

void printListKota(ListKota L) {
    addrKota temp = L.head;
    printf("Kota: ");
    while (temp != NULL) {
        printf(" -> %s", temp->data.kt);
        temp = temp->next; // Akses langsung tanpa NextKota()
    }
    printf("\n");
}

// void printSeluruhKota(ListKota L) {
//     addrKota temp = L.head;
//     printf("Kota: ");
//     while (temp != NULL) {
//         printf(" -> %s", temp->data.kt);
//         temp = temp->next; // Akses langsung tanpa NextKota()
//     }
//     printf("\n");
// }

void findKota(ListKota L, char *kota) {
    addrKota temp = L.head;
    while (temp != NULL) {
        if (strcmp(temp->data.kt, kota) == 0) {
            printf("\n");
            printKota(DataKota(temp));
        } 
        temp = temp->next; 
    }
}

void hapusKota(ListKota *L, char *kota) {
    addrKota temp = L->head;
    addrKota prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->data.kt, kota) == 0) {
            if (prev == NULL) {
                L->head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
