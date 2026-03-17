#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Initialize
void init(Deque *dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

// Check empty
int empty(Deque *dq) {
    return dq->size == 0;
}

// Check full
int isFull(Deque *dq) {
    return dq->size == MAX;
}

// Size
int getSize(Deque *dq) {
    return dq->size;
}

// Push front
void push_front(Deque *dq, int x) {
    if (isFull(dq)) return;

    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->arr[dq->front] = x;
    dq->size++;

    if (dq->size == 1)
        dq->rear = dq->front;
}

// Push back
void push_back(Deque *dq, int x) {
    if (isFull(dq)) return;

    dq->rear = (dq->rear + 1) % MAX;
    dq->arr[dq->rear] = x;
    dq->size++;

    if (dq->size == 1)
        dq->front = dq->rear;
}

// Pop front
int pop_front(Deque *dq) {
    if (empty(dq)) return -1;

    int val = dq->arr[dq->front];
    dq->front = (dq->front + 1) % MAX;
    dq->size--;

    if (dq->size == 0) {
        dq->front = 0;
        dq->rear = -1;
    }

    return val;
}

// Pop back
int pop_back(Deque *dq) {
    if (empty(dq)) return -1;

    int val = dq->arr[dq->rear];
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;

    if (dq->size == 0) {
        dq->front = 0;
        dq->rear = -1;
    }

    return val;
}

// Front element
int front(Deque *dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->front];
}

// Back element
int back(Deque *dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->rear];
}

// Clear
void clear(Deque *dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

// Display
void display(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    int i = dq->front;
    for (int count = 0; count < dq->size; count++) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// MAIN FUNCTION
int main() {
    Deque dq;
    init(&dq);

    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(&dq, x);
        }
        else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(&dq, x);
        }
        else if (strcmp(op, "pop_front") == 0) {
            printf("%d\n", pop_front(&dq));
        }
        else if (strcmp(op, "pop_back") == 0) {
            printf("%d\n", pop_back(&dq));
        }
        else if (strcmp(op, "front") == 0) {
            printf("%d\n", front(&dq));
        }
        else if (strcmp(op, "back") == 0) {
            printf("%d\n", back(&dq));
        }
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", getSize(&dq));
        }
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", empty(&dq));
        }
        else if (strcmp(op, "clear") == 0) {
            clear(&dq);
        }
        else if (strcmp(op, "display") == 0) {
            display(&dq);
        }
    }

    return 0;
}