#include <stdio.h>

#define MAX 7

void DFT(int graph[MAX][MAX], int visited[], char nodes[], int vertex) {

    visited[vertex] = 1;

    printf("%c ", nodes[vertex]);

    for (int i = 0; i < MAX; i++) {

        if (graph[vertex][i] == 1 && !visited[i]) {
            DFT(graph, visited, nodes, i);
        }
    }
}

int main() {

    // Adjacency Matrix
    int graph[MAX][MAX] = {

    //H R S T N M P
    {0,1,0,1,0,0,0}, // H
    {1,0,0,0,0,1,0}, // R
    {0,1,0,1,1,0,0}, // S
    {1,0,0,0,0,1,0}, // T
    {1,0,0,0,0,1,1}, // N
    {0,1,0,1,1,0,1}, // M
    {0,0,0,0,1,1,0}  // P
    };

    int visited[MAX] = {0};

    char nodes[MAX] = {'H','R','S','T','N','M','P'};

    printf("DFT Traversal: ");

    DFT(graph, visited, nodes, 0); // Start from H

    return 0;
}