#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}
void topologicalSort(int graph[MAX][MAX], int V) {
    int indegree[MAX] = {0};
    int result[MAX];
    int i, j, count = 0;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j] == 1)
                indegree[j]++;
        }
    }
    for (i = 0; i < V; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }
    while (front != -1 && front <= rear) {
        int node = dequeue();
        result[count++] = node;

        for (j = 0; j < V; j++) {
            if (graph[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0)
                    enqueue(j);
            }
        }
    }
    if (count != V) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }
    printf("Topological Order: ");
    for (i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}
int main() {
    int V = 6;
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    topologicalSort(graph, V);

    return 0;
}