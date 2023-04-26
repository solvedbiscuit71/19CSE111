#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

#define nodesize sizeof(struct Node)

void push(struct Node** sk, int value) {
    struct Node* nd = malloc(nodesize);
    nd->data = value;
    nd->next = NULL;

    if (*sk == NULL) {
        *sk = nd;
        return;
    }

    nd->next = *sk;
    *sk = nd;
}

void pop(struct Node **sk) {
    if (*sk == NULL)
        return;

    if ((*sk)->next == NULL) {
        free(*sk);
        *sk = NULL;
        return;
    }

    struct Node* del = *sk;
    *sk = (*sk)->next;
    free(del);
}

int* top(struct Node *sk) {
    if (sk == NULL)
        return NULL;
    
    return &sk->data;
}

int empty(struct Node *sk) {
    return sk == NULL;
}

int main()
{
    struct Node *sk;
    sk = NULL;

    // To print the given array in reverse order
    int i;
    int arr[] = {1, 2, 3, 4, 5};
    for (i = 0; i < 5; i++) {
        push(&sk, arr[i]);
    }

    while (!empty(sk)) {
        printf("%d ", *top(sk));
        pop(&sk);
    }
    printf("\n");
}