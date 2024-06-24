#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Deque {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = -1;
    deque->rear = 0;
    deque->size = 0;
    return deque;
}

int isFull(Deque* deque) {
    return deque->size == MAX;
}

int isEmpty(Deque* deque) {
    return deque->size == 0;
}

void insertFront(Deque* deque, int item) {
    if (isFull(deque)) {
        printf("Deque is full\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX - 1;
    } else {
        deque->front = deque->front - 1;
    }
    deque->arr[deque->front] = item;
    deque->size++;
}

void insertRear(Deque* deque, int item) {
    if (isFull(deque)) {
        printf("Deque is full\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX - 1) {
        deque->rear = 0;
    } else {
        deque->rear = deque->rear + 1;
    }
    deque->arr[deque->rear] = item;
    deque->size++;
}

void deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = 0;
    } else if (deque->front == MAX - 1) {
        deque->front = 0;
    } else {
        deque->front = deque->front + 1;
    }
    deque->size--;
}

void deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = 0;
    } else if (deque->rear == 0) {
        deque->rear = MAX - 1;
    } else {
        deque->rear = deque->rear - 1;
    }
    deque->size--;
}

int main() {
    Deque* deque = createDeque();

    insertRear(deque, 5);
    insertFront(deque, 10);
    deleteFront(deque);
    deleteRear(deque);

    free(deque);
    return 0;
}
