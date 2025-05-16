#include "linked.h"
#include <stdbool.h>

typedef address Queue;

bool isQueueEmpty(address p);

void create_Queue(address *p);

address createQueue(infotype x);

void enqueue(address *p, address PNew);

void dequeue(address *p, infotype *x);

void printQueue(address p);

