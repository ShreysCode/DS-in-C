#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct Node* temp = malloc(sizeof(struct Node));

    temp->data = value;
    temp->next = NULL;

    if(rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue() {
    if(front == NULL) {
        printf("Queue Empty\n");
        return;
    }

    struct Node* temp = front;

    printf("Deleted: %d\n", front->data);

    front = front->next;

    free(temp);
}