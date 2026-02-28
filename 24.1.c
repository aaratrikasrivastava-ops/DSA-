#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node* next;
};

/* Create new node */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insert at end */
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Delete first occurrence of key */
struct Node* deleteKey(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;

    /* If head node itself holds key */
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    /* Search for key */
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    /* Key not found */
    if (temp == NULL)
        return head;

    /* Remove node */
    prev->next = temp->next;
    free(temp);

    return head;
}

/* Print list */
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, key, x;
    struct Node* head = NULL;

    /* Input list */
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    /* Input key */
    scanf("%d", &key);

    /* Delete key */
    head = deleteKey(head, key);

    /* Output */
    printList(head);

    return 0;
}