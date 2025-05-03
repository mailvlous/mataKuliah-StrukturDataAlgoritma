#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "queue.h"

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(Queue q) {
    return q.front == -1;
}

int isQueueFull(Queue q) {
    return (q.rear + 1) % MAX_QUEUE == q.front;
}

void enqueue(Queue *q, int idxAnggota) {
    if (isQueueFull(*q)) return;
    if (isQueueEmpty(*q)) q->front = q->rear = 0;
    else q->rear = (q->rear + 1) % MAX_QUEUE;
    q->data[q->rear] = idxAnggota;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(*q)) return -1;
    int val = q->data[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front = (q->front + 1) % MAX_QUEUE;
    return val;
}
