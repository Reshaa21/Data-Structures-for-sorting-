#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100


struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};


struct AdjList {
    struct AdjListNode* head;
};


struct Graph {
    int V;
    struct AdjList* array;
};


struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// A utility function to print the path array
void printPath(int path[], int path_len) {
    for (int i = 0; i < path_len; i++)
        printf("%d ", path[i]);
    printf("\n");
}

// A utility function to do DFS from the given vertex u
void DFSUtil(struct Graph* graph, int u, int d, int visited[], int path[], int path_len) {
    visited[u] = 1;
    path[path_len] = u;
    path_len++;

    if (u == d) {
        printPath(path, path_len);
    } else {
        struct AdjListNode* crawl = graph->array[u].head;
        while (crawl) {
            if (!visited[crawl->dest]) {
                DFSUtil(graph, crawl->dest, d, visited, path, path_len);
            }
            crawl = crawl->next;
        }
    }

    path_len--;
    visited[u] = 0;
}

// Function to print all paths from source to destination
void printAllPaths(struct Graph* graph, int s, int d) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    int* path = (int*)malloc(graph->V * sizeof(int));
    int path_len = 0;

    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    DFSUtil(graph, s, d, visited, path, path_len);

    free(visited);
    free(path);
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    int s = 0, d = 4;
    printf("Following are all different paths from %d to %d:\n", s, d);
    printAllPaths(graph, s, d);

    return 0;
}

