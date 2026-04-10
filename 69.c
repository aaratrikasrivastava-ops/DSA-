#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};
struct Graph {
    int V;
    struct Node* adj[MAX];
};
struct MinHeapNode {
    int vertex;
    int dist;
};
struct MinHeap {
    int size;
    struct MinHeapNode heap[MAX];
};
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->weight = w;
    node->next = graph->adj[u];
    graph->adj[u] = node;
}
void swap(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(struct MinHeap* mh, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < mh->size && mh->heap[left].dist < mh->heap[smallest].dist)
        smallest = left;

    if (right < mh->size && mh->heap[right].dist < mh->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&mh->heap[i], &mh->heap[smallest]);
        heapify(mh, smallest);
    }
}
struct MinHeapNode extractMin(struct MinHeap* mh) {
    struct MinHeapNode root = mh->heap[0];
    mh->heap[0] = mh->heap[mh->size - 1];
    mh->size--;
    heapify(mh, 0);
    return root;
}
void decreaseKey(struct MinHeap* mh, int v, int dist) {
    for (int i = 0; i < mh->size; i++) {
        if (mh->heap[i].vertex == v) {
            mh->heap[i].dist = dist;
            while (i && mh->heap[(i - 1) / 2].dist > mh->heap[i].dist) {
                swap(&mh->heap[i], &mh->heap[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
            break;
        }
    }
}
int isInMinHeap(struct MinHeap* mh, int v) {
    for (int i = 0; i < mh->size; i++)
        if (mh->heap[i].vertex == v)
            return 1;
    return 0;
}
void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[MAX];

    struct MinHeap mh;
    mh.size = V;
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        mh.heap[i].vertex = i;
        mh.heap[i].dist = INT_MAX;
    }
    dist[src] = 0;
    mh.heap[src].dist = 0;
    for (int i = (mh.size - 1)/2; i >= 0; i--)
        heapify(&mh, i);

    while (mh.size > 0) {
        struct MinHeapNode minNode = extractMin(&mh);
        int u = minNode.vertex;

        struct Node* temp = graph->adj[u];

        while (temp != NULL) {
            int v = temp->vertex;

            if (isInMinHeap(&mh, v) && dist[u] != INT_MAX &&
                dist[u] + temp->weight < dist[v]) {

                dist[v] = dist[u] + temp->weight;
                decreaseKey(&mh, v, dist[v]);
            }
            temp = temp->next;
        }
    }
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}
int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 4, 3, 2);
    addEdge(graph, 3, 2, 4);
    addEdge(graph, 2, 3, 6);

    int source = 0;
    dijkstra(graph, source);

    return 0;
}