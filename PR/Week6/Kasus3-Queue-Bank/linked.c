#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

#define Info(P) (P)->info
#define Next(P) (P)->next

// typedef int infotype;
// typedef struct tElmtList *address;
// typedef struct tElmtList {
// 	infotype info;
// 	address  next;
//  } ElmtList;

boolean isEmpty(address p){
    return (p == NULL);
}

address createList(address *p){
    *p = NULL;
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

address createNode(infotype x) {
    address newNode = (address)malloc(sizeof(ElmtList));
    if (newNode == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        exit(1);
    }
    Info(newNode) = x;
    Next(newNode) = NULL;
    return newNode;
}

void Ins_Awal(address *p, address Pnew) {
    if (Pnew == NULL) return;

    Next(Pnew) = *p;
    *p = Pnew;
}

void Ins_Akhir(address *p, address Pnew) {
    if (Pnew == NULL) return;

    Pnew->next = NULL;

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


void Del_Awal(address *p, infotype *x) {
    if (*p == Nil) {
    /*
    jadi kalo delete tuh harus nyiapin address tambahan yaitu temp
    fungsinya untuk mutusin next dari node pertama(*p) dan buang info dari node pertama
    */
    } else {
        address temp = *p; // ambil alamat node pertama, jadi temp sekarng punya Next yang sama kayak *p yaitu nunjuk ke elemen kedua
        *x = Info(temp); // karena temp itu sekarng node pertama maka *x itu info dari node pertama
        *p = Next(temp);//*p atau *First nextnya akan di assign next dari node temp yaitu alamat *p
        free(temp);
    }
}

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
