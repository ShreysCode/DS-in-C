#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Insert at end
struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    // First node
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    struct Node* last = head->prev;

    last->next = newNode;
    newNode->prev = last;

    newNode->next = head;
    head->prev = newNode;

    return head;
}

// Display list
void display(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;

    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(circular)\n");
}

// Reverse list
struct Node* reverse(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* current = head;
    struct Node* temp = NULL;

    do {
        temp = current->next;

        current->next = current->prev;
        current->prev = temp;

        current = temp;
    } while (current != head);

    head = head->next; // new head

    return head;
}

int main() {
    struct Node* head = NULL;
    int value;

    // Fixed number of nodes = 5
    for (int i = 0; i < 5; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        head = insert(head, value);
    }

    printf("\nOriginal List:\n");
    display(head);

    head = reverse(head);

    printf("\nReversed List:\n");
    display(head);

    return 0;
}