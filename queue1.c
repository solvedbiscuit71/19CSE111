#include <stdio.h>
#include <math.h>

#define maxsize 100

struct Queue {
    int data[maxsize];
    int front;
    int rear;
};

void enqueue(struct Queue *que, int value) {
    if (que->rear == maxsize - 1)
        return;

    que->data[que->rear + 1] = value;
    que->rear++;
}

void dequeue(struct Queue *que) {
    if (que->front > que->rear)
        return;

    que->front++;
}

int* front(struct Queue *que) {
    if (que->front > que->rear)
        return NULL;

    return &que->data[que->front];
}

int* rear(struct Queue *que) {
    if (que->front > que->rear)
        return NULL;

    return &que->data[que->rear];
}

int empty(struct Queue *que) {
    return que->front > que->rear;
}

int main()
{
    struct Queue que;
    que.front = 0;
    que.rear = -1;

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

