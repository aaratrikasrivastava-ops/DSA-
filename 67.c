#include <stdio.h>

#define MAX 100

int adj[MAX][MAX]; 
int visited[MAX];   
int stack[MAX];     
int top = -1;
void push(int v) {
    stack[++top] = v;
}
void dfs(int v, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }
    push(v);
}
void topologicalSort(int n) {
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i, n);
        }
    }

    printf("Topological Ordering: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}
int main() {
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v) for u -> v:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort(n);

    return 0;
}