#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 100

typedef struct {
    int data[MAX_QUEUE];      // Menyimpan indeks anggota
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);

int isQueueEmpty(Queue q);

int isQueueFull(Queue q);

void enqueue(Queue *q, int idxAnggota);

int dequeue(Queue *q);


#endif
