#include "queue.h"
#include "linked.h"
#include <stdbool.h>

bool isQueueEmpty(address p){
    isE mpty(p);
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