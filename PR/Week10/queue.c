#include "queue.h"
#include <stdbool.h>

void enqueue(address n) {
    address temp = Queue[front];
    front++;
    return temp;
}

address dequeue() {
    return Queue[front++];
}

int isEmpty() {
    return front == rear;
}
