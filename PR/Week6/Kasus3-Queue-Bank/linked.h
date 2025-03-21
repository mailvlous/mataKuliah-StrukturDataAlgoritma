#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <malloc.h>
#include "boolean.h"
#include <stdbool.h>

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address  next;
	address prev;
} ElmtList;

bool isEmpty(address p);

address createList(address *p);

address createNode (infotype x);

void Ins_Awal(address *p, address PNew);

void Ins_Akhir (address *p, address PNew);

void Del_Awal (address *p, infotype *x);

void Del_Akhir (address *p, infotype *x);

void Tampil_List (address p);



#endif
