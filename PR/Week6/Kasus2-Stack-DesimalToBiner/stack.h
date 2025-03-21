#ifndef stack_H
#define stack_H
#include <stdio.h>
#include <malloc.h>
#include "boolean.h"

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

address createStack (infotype p);

void push (address *p, address PNew);

void pop (address *p, infotype *x);

void printStack (address p);

int decimalToBiner (int num);

#endif