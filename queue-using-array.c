#include <stdio.h>
#include <stdlib.h>

// --------------------------
// Structure
// --------------------------

struct Queue {
    int* data;
    int front;
    int rear;
    int size;
};

// --------------------------
// Constructor
// --------------------------

struct Queue initQueue(int size) {
    return (struct Queue){malloc(sizeof(int) * 100), 0, 0, size};
}

void deinitQueue(struct Queue* que) {
    free(que->data);
}

// --------------------------
// Methods
// --------------------------

void enqueue(struct Queue* que, int value) {
    if (que->rear == que->size)
        return;

    que->data[que->rear] = value;
    que->rear += 1;
}

void dequeue(struct Queue* que) {
    if (que->front == que->rear)
        return;
    
    que->front += 1;
}

int* front(struct Queue* que) {
    if (que->front == que->rear)
        return NULL;
    
    return &que->data[que->front];
}

int* rear(struct Queue* que) {
    if (que->front == que->rear)
        return NULL;
    
    return &que->data[que->rear-1];
}


// --------------------------
// Main
// --------------------------

int main() {
    struct Queue que = initQueue(100);
    
    enqueue(&que, 3);
    enqueue(&que, 1);
    enqueue(&que, 2);
    enqueue(&que, 4);
    
    while (front(&que) != NULL) {
        printf("%d ", *front(&que));
        dequeue(&que);
    }
    printf("\n");

    deinitQueue(&que);
}

