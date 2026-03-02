#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node* next;
};

/* Create new node */
struct Node* createNode(int val) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

/* Insert at end */
struct Node* insert(struct Node* head, int val) {
    struct Node* newNode = createNode(val);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Rotate right by k places */
struct Node* rotateRight(struct Node* head, int k) {

    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int n = 1;

    /* Find length and last node */
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    /* Make circular list */
    temp->next = head;

    /* Handle k > n */
    k = k % n;

    int steps = n - k;
    struct Node* newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    /* New head */
    struct Node* newHead = newTail->next;

    /* Break circular link */
    newTail->next = NULL;

    return newHead;
}

/* Print list */
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Main function */
int main() {
    int n, x, k;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}