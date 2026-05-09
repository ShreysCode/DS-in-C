#include <stdio.h>

#define V 9
#define INF 99999

int main() {

    // Graph represented as adjacency matrix
    int graph[V][V] = {

    //0  1  2  3  4  5  6  7  8
    { 0, 4, 0, 0, 0, 0, 0, 8, 0}, //0
    { 4, 0, 8, 0, 0, 0, 0,11, 0}, //1
    { 0, 8, 0, 7, 0, 4, 0, 0, 2}, //2
    { 0, 0, 7, 0, 9,14, 0, 0, 0}, //3
    { 0, 0, 0, 9, 0,10, 0, 0, 0}, //4
    { 0, 0, 4,14,10, 0, 2, 0, 0}, //5
    { 0, 0, 0, 0, 0, 2, 0, 1, 6}, //6
    { 8,11, 0, 0, 0, 0, 1, 0, 7}, //7
    { 0, 0, 2, 0, 0, 0, 6, 7, 0}  //8
    };

    int dist[V];
    int visited[V];

    // Initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[0] = 0; // Source node

    // Dijkstra Algorithm
    for (int count = 0; count < V - 1; count++) {

        int min = INF, u;

        // Find minimum distance vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update distances
        for (int v = 0; v < V; v++) {

            if (!visited[v] &&
                graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print shortest distances
    printf("Vertex\tDistance from Node 0\n");

    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }

    return 0;
}