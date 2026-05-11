// DFS Traversal of Graph ; Implement Depth First Search using adjacency matrix.

#include <stdio.h>

int graph[5][5] = {
    {0,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,1,1},
    {0,1,1,0,0},
    {0,0,1,0,0}
};

int visited[5];

void dfs(int node) {

    visited[node] = 1;

    printf("%d ", node);

    for(int i=0; i<5; i++) {
        if(graph[node][i] && !visited[i])
            dfs(i);
    }
}

int main() {
    dfs(0);
    return 0;
}