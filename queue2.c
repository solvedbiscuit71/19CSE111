#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxsize 100

struct Node {
    int data;
    struct Node* next;
};

#define nodesize sizeof(struct Node)

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue *que, int value) {
    struct Node* nd = malloc(nodesize);
    nd->data = value;
    nd->next = NULL;

    if (que->rear == NULL) {
        que->front = nd;
        que->rear = nd;
    } else {
        que->rear->next = nd;
        que->rear = nd;
    }
}

void dequeue(struct Queue *que) {
    if (que->front == NULL)
        return;

    if (que->front == que->rear) {
        free(que->front);
        que->front = NULL;
        que->rear = NULL;
    } else {
        struct Node* del = que->front;
        que->front = que->front->next;
        free(del);
    }
}

int* front(struct Queue *que) {
    if (que->front == NULL)
        return NULL;

    return &que->front->data;
}

int* rear(struct Queue *que) {
    if (que->rear == NULL)
        return NULL;

    return &que->rear->data;
}

int empty(struct Queue *que) {
    return que->front == NULL;
}

int main()
{
    struct Queue que;
    que.front = NULL;
    que.rear = NULL;

    // sum of number raises to n until user enter 0
    // we use queue, because x1^n + x2^n + .. + xn^n != (x1 + x2 + .. + xn) ^ n
    int i, n;
    scanf("%d", &i);
    while (i != 0) {
        enqueue(&que, i);
        scanf("%d", &i);
    }

    printf("Enter n: ");
    scanf("%d", &n);

    i = 0;
    while (!empty(&que)) {
        i += pow(*front(&que), n);
        dequeue(&que);
    }

    printf("Sum = %d\n", i);
}

