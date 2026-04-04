#include <stdio.h>
#include <stdlib.h>
struct Node {
    int vertex;
    struct Node* next;
};
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void DFS(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while(temp != NULL) {
        if(!visited[temp->vertex]) {
            DFS(temp->vertex, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);
    
    struct Node* adj[n];
    for(int i = 0; i < n; i++) {
        adj[i] = NULL;
    }
    
    int u, v;
    printf("Enter edges (u v):\n");
    
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }
    
    int visited[n];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    int s;
    printf("Enter starting vertex: ");
    scanf("%d", &s);
    
    printf("DFS Traversal: ");
    DFS(s, adj, visited);
    
    return 0;
}