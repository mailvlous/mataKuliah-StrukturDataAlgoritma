#ifndef stack_H
#define stack_H
#include "linked.h"
#include <stdbool.h>

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev

address createStack(infotype p);

void push(address *p, address PNew);

void pop(address *p, infotype *x);

void printStack(address p);

void decimalToBiner(int num);

#endif