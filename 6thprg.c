#include <stdio.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

// Check if full
int isFull() {
    return top == SIZE - 1;
}

// Check if empty
int isEmpty() {
    return top == -1;
}

// Push operation
void push(int value) {
    if (value % 2 != 0) {
        printf("Odd number discarded!\n");
        return;
    }

    if (isFull()) {
        printf("Stack is FULL!\n");
        return;
    }

    top++;
    stack[top] = value;

    printf("Pushed: %d\n", value);
}

// Pop operation
void pop() {
    if (isEmpty()) {
        printf("Stack is EMPTY!\n");
        return;
    }

    printf("Popped: %d\n", stack[top]);
    top--;
}

// Peek operation
void peek() {
    if (isEmpty()) {
        printf("Stack is EMPTY!\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

// Display stack
void display() {
    if (isEmpty()) {
        printf("Stack is EMPTY!\n");
        return;
    }

    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}