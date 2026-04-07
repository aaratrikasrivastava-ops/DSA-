#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int dfs(int node, int parent, int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {
            if (visited[i] == 0) {
                if (dfs(i, node, n))
                    return 1;
            }
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int n, i, j;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            visited[i] = 0;
        }
    }

    int hasCycle = 0;
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, -1, n)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}