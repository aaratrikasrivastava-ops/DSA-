#include <stdio.h>
#include <string.h>
#define EMPTY -1
int hash(int key, int m) {
    return key % m;
}
void insert(int table[], int m, int key) {
    int i = 0;
    int index;
    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }
    printf("Hash table is full\n");
}

int search(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY)
            return 0; 

        if (table[index] == key)
            return 1; 

        i++;
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);

    int table[m];
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    scanf("%d", &q);

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(table, m, key);
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(table, m, key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}