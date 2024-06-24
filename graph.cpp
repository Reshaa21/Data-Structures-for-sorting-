#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100 


struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    struct Node* adjList[MAX_VERTICES];
    int numVertices;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    
 
    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
    }
    
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {

    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}


void shortestPath(struct Graph* graph, int src, int dest) {
    int parent[MAX_VERTICES]; 
    bool visited[MAX_VERTICES] = {false}; 
    int distance[MAX_VERTICES]; 
    

    for (int i = 0; i < graph->numVertices; ++i) {
        parent[i] = -1; 
        distance[i] = -1; 
    }
    

    struct Node* queue = NULL;
    visited[src] = true;
    distance[src] = 0;
    queue = createNode(src);
    

    while (queue != NULL) {
        int u = queue->vertex;
        queue = queue->next;
        
        struct Node* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->vertex;
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                distance[v] = distance[u] + 1;
                queue = createNode(v);
            }
            temp = temp->next;
        }
    }
    

    printf("Shortest path from %d to %d: ", src, dest);
    int path[MAX_VERTICES];
    int pathLength = 0;
    int step = dest;
    while (step != -1) {
        path[pathLength++] = step;
        step = parent[step];
    }
    

    for (int i = pathLength - 1; i >= 0; --i) {
        printf("%d ", path[i]);
    }
    printf("\n");
}
int main() {
    int V = 6; // Number of vertices
    struct Graph* graph = createGraph(V);
    
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    
    int src = 0;
    int dest = 5; 
    shortestPath(graph, src, dest);
    
    return 0;
}

