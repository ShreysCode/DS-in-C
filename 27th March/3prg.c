#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

// Check if full
int isFull() {
    return (top == SIZE - 1);
}

// Check if empty
int isEmpty() {
    return (top == -1);
}

// Push (only even numbers allowed)
void push(int value) {
    if (value % 2 != 0) {
        printf("Odd number %d not allowed\n", value);
        return;
    }

    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;
    printf("%d pushed\n", value);
}

// Pop
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }

    printf("%d popped\n", stack[top--]);
}

// Peek
void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

// Display
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Main
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
                printf("Invalid choice\n");
        }
    }
}
