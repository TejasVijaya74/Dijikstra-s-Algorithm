/*Design and implement C/C++ Program to find shortest paths from a given vertex in a weighted connected graph to other V using Dijkstra's algorithm*/

#include <stdio.h>
#include <limits.h>

#define MAX 50

void dijkstra(int graph[MAX][MAX], int src, int V) {
    int dist[MAX], visited[MAX];
    
    // Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, min_index;
        
        // Find the vertex with minimum distance
        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] < min) {
                min = dist[v];
                min_index = v;
            }
        }

        visited[min_index] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[min_index][v] && 
                dist[min_index] != INT_MAX && 
                dist[min_index] + graph[min_index][v] < dist[v]) {
                dist[v] = dist[min_index] + graph[min_index][v];
            }
        }
    }

    // Print the result
    printf("Vertex \tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t%d\n", i, dist[i]);
    }
}

int main() {
    int V, graph[MAX][MAX], source;

    printf("Input the number of vertices: ");
    scanf("%d", &V);

    printf("Input the adjacency matrix for the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Input the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source, V);

    return 0;
}