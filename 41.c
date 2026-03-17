#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Initialize queue
void init(Queue* q) {
    q->front = q->rear = NULL;
}

// Enqueue
void enqueue(Queue* q, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue
int dequeue(Queue* q) {
    if (q->front == NULL)
        return -1;

    Node* temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

// MAIN
int main() {
    Queue q;
    init(&q);

    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &x);
            enqueue(&q, x);
        }
        else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue(&q));
        }
    }

    return 0;
}