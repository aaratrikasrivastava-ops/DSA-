#include <stdio.h>
#include <limits.h>
#define MAX 100
int n, m;
int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int minDistance() {
    int min = INT_MAX, index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int src) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 1; count <= n; count++) {
        int u = minDistance();
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; 
    }

    int source;
    scanf("%d", &source);

    dijkstra(source);
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}