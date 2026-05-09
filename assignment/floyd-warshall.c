#include <stdio.h>

#define INF 99999

int main() {

    int n = 6;

    // Adjacency Matrix
    int dist[6][6] = {
        {0, 5, 9, 11, INF, INF},
        {5, 0, INF, INF, 3, INF},
        {9, INF, 0, 4, 3, INF},
        {11, INF, 4, 0, INF, 14},
        {INF, 3, 3, INF, 0, 7},
        {INF, INF, INF, 14, 7, 0}
    };

    // Floyd Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

            }
        }
    }

    // Print shortest path matrix
    printf("Shortest Path Matrix:\n\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);

        }
        printf("\n");
    }

    return 0;
}