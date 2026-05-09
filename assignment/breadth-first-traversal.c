#include <stdio.h>

#define MAX 7

// Queue for BFS
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    queue[++rear] = value;
}

int dequeue() {
    if (front == -1)
        return -1;

    int value = queue[front];

    if (front == rear)
        front = rear = -1;
    else
        front++;

    return value;
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

    int start = 0; // Start from H

    visited[start] = 1;
    enqueue(start);

    printf("BFT Traversal: ");

    while (front != -1) {

        int current = dequeue();

        printf("%c ", nodes[current]);

        for (int i = 0; i < MAX; i++) {

            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }

    return 0;
}