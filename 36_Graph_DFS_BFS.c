#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src - 1];
    graph->adjLists[src - 1] = newNode;

    // Since undirected graph, add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest - 1];
    graph->adjLists[dest - 1] = newNode;
}

void DFS(struct Graph* graph, int vertex) {
    graph->visited[vertex - 1] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjLists[vertex - 1];
    while (temp) {
        if (!graph->visited[temp->vertex - 1]) {
            DFS(graph, temp->vertex);
        }
        temp = temp->next;
    }
}

void BFS(struct Graph* graph, int startVertex) {
    int queue[100];
    int front = 0, rear = 0;

    graph->visited[startVertex - 1] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = graph->adjLists[current - 1];
        while (temp) {
            if (!graph->visited[temp->vertex - 1]) {
                graph->visited[temp->vertex - 1] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices, edges, startVertex;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    printf("DFS traversal: ");
    for (int i = 0; i < vertices; i++) graph->visited[i] = 0;
    DFS(graph, startVertex);
    printf("\n");

    printf("BFS traversal: ");
    for (int i = 0; i < vertices; i++) graph->visited[i] = 0;
    BFS(graph, startVertex);
    printf("\n");

    // Free memory (optional)
    for (int i = 0; i < vertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);

    return 0;
}






