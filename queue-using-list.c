#include <stdio.h>
#include <stdlib.h>

// --------------------------
// Structure
// --------------------------

struct Node {
    int value;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

// --------------------------
// Constructor
// --------------------------

struct Queue initQueue() {
    return (struct Queue){NULL, NULL};
}

void deinitQueue(struct Queue* que) {
    struct Node *node = que->front, *temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

// --------------------------
// Methods
// --------------------------

void enqueue(struct Queue* que, int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    
    if (que->rear == NULL) {
        que->front = node;
        que->rear = node;
    }
    
    que->rear->next = node;
    que->rear = que->rear->next;
}

void dequeue(struct Queue* que) {
    if (que->front == NULL)
        return;

    struct Node* temp = que->front;
    if (que->front->next == NULL) {
        que->front = NULL;
        que->rear = NULL;
    } else {
        que->front = que->front->next;
    }
    
    free(temp);
}

int* front(struct Queue* que) {
    if (que->front == NULL)
        return NULL;
    return &que->front->value;
}

int* rear(struct Queue* que) {
    if (que->rear == NULL)
        return NULL;
    return &que->rear->value;
}


// --------------------------
// Main
// --------------------------

int main() {
    struct Queue que = initQueue();
    
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

