

#include <stdio.h>
#include <stdlib.h>

#define tablesize 10
#define nodesize sizeof(struct Node)

// Data Classes

struct DataItem {
    int key;
    int value;
};

struct Node {
    struct DataItem data;
    struct Node* next;
};

struct HashMap {
    struct Node* data[tablesize];
    int capacity;
};

// Constructors

void init(struct HashMap* map) {
    int i;
    for (i = 0; i < tablesize; i++) {
        map->data[i] = NULL;
    }
}

void destroy(struct Node** head) {
    struct Node* tmp = *head, *del;
    while (tmp != NULL) {
        del = tmp;
        tmp = tmp->next;
        free(del);
    }

    head = NULL;
}

void deinit(struct HashMap* map) {
    int i;
    for (i = 0; i < tablesize; i++) {
        destroy(&map->data[i]);
    }
}

// methods

int hashfn(int key) {
    return key % tablesize;
}

void insert(struct HashMap *map, struct DataItem data) {
    int hash = hashfn(data.key);

    struct Node* node = malloc(nodesize);
    node->data.key = data.key;
    node->data.value = data.value;

    struct Node *oldhead = map->data[hash];
    map->data[hash] = node;
    map->capacity += 1;
    node->next = oldhead;
}

void delete(struct HashMap *map, int key) {
    int hash = hashfn(key);

    struct Node *prev, *curr;
    prev = NULL;
    curr = map->data[hash];

    while (curr != NULL && curr->data.key != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
        return;

    if (prev == NULL) {
        map->data[hash] = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
    map->capacity -= 1;
}

struct DataItem* search(struct HashMap *map, int key) {
    int hash = hashfn(key);

    struct Node* head = map->data[hash];
    while (head != NULL && head->data.key != key) {
        head = head->next;
    }

    return head != NULL ? &head->data : NULL;
}

int main() {
    // Given an array, find the number which occurs only once while others 
    // occurs twice.
    int n = 9, i;
    int arr[] = {1,2,1,3,2,5,3,4,5};

    struct HashMap counter;
    init(&counter);
    for (i = 0; i < n; i++) {
        struct DataItem *data = search(&counter, arr[i]);

        if (data == NULL) {
            insert(&counter, (struct DataItem){arr[i], 1});
        } else {
            data->value += 1;
        }
    }

    int ans;
    for (i = 0; i < n; i++) {
        struct DataItem *data = search(&counter, arr[i]);
        if (data->value == 1) {
            ans = data->key;
            break;
        }
    }

    printf("The number which occurs only once is %d\n", ans);
    deinit(&counter);
}