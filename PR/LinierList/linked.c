#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

#define Info(P) (P)->info
#define Next(P) (P)->next

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address  next;
 } ElmtList;

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
    address *p = malloc(sizeof(ElmtList));
    Info(*p) = x;
    Next(*p) = NULL;
    return *p;
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
    if (*p == NULL) {
        *p = Pnew;
    } else {
        Next(Pnew) = *p; //Pnew nunjuk ke *p 
        *p = Pnew; // *p akan di assign Pnew
    }
}

// Insert at last

void Ins_Akhir(address *p, address Pnew) {
    if (*p == NULL) {
        *p = Pnew;
    } else {
        Next(Pnew) = NULL;
        address last = *p;
        /*jadi ini bakal nyari node terakhir atau node yang nextnya itu null*/
        while(Next(last) != NULL) { 
            last = Next(last); 
        }
        Next(last) = Pnew; // kalo nextnya null, ini bakal di assign Pnew
    }
}

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
        printf("Linked list kosong.\n");
        return;
    }

    printf("Isi Linked List: ");
    while (p != NULL) {
        printf("[%d] -> ", Info(p));
        p = Next(p);
    }
    printf("NULL\n");
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