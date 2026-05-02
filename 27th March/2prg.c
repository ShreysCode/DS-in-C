#include <stdio.h>
#define SIZE 6

int queue[SIZE];
int front = -1, rear = -1;

// Check if full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Enqueue (only odd numbers allowed)
void enqueue(int value) {
    if (value % 2 == 0) {
        printf("Even number %d not allowed\n", value);
        return;
    }

    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    printf("%d inserted\n", value);
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d removed\n", queue[front]);

    if (front == rear) {
        front = rear = -1;  // reset
    } else {
        front = (front + 1) % SIZE;
    }
}

// Display
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    printf("Queue elements: ");

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
