#include "binarytree.h"
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

address Queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;

void enqueue(address n);

address dequeue();

int isEmpty();