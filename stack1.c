#include <stdio.h>

#define maxsize 100

struct Stack {
    int data[maxsize];
    int top;
};

void push(struct Stack *sk, int value) {
    if (sk->top == maxsize - 1)
        return;

    sk->data[sk->top + 1] = value;
    sk->top++;
}

void pop(struct Stack *sk) {
    if (sk->top == -1)
        return;
    
    sk->top--;
}

int* top(struct Stack *sk) {
    if (sk->top == -1)
        return NULL;

    return &sk->data[sk->top];
}

int empty(struct Stack *sk) {
    return sk->top == -1 ? 1 : 0;
}

int main()
{
    struct Stack sk;
    sk.top = -1;

    // To print the given array in reverse order
    int i;
    int arr[] = {1, 2, 3, 4, 5};
    for (i = 0; i < 5; i++) {
        push(&sk, arr[i]);
    }

    while (!empty(&sk)) {
        printf("%d ", *top(&sk));
        pop(&sk);
    }
    printf("\n");
}