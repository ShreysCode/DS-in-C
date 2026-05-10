#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Insert at end (for initial creation)
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

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

// Display
void display(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(circular)\n");
}

// Insert BEFORE a given value
struct Node* insertBefore(struct Node* head, int target, int value) {
    if (head == NULL) return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;

    do {
        if (temp->data == target) {

            struct Node* prevNode = temp->prev;

            // Linking new node
            newNode->next = temp;
            newNode->prev = prevNode;

            prevNode->next = newNode;
            temp->prev = newNode;

            // If inserting before head → update head
            if (temp == head)
                head = newNode;

            return head;
        }

        temp = temp->next;

    } while (temp != head);

    printf("Target value not found.\n");
    free(newNode);
    return head;
}

int main() {
    struct Node* head = NULL;
    int n, value, target;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input.\n");
        return 0;
    }

    // Create list
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nOriginal List:\n");
    display(head);

    printf("\nEnter value to insert: ");
    scanf("%d", &value);

    printf("Enter the node value BEFORE which to insert: ");
    scanf("%d", &target);

    head = insertBefore(head, target, value);

    printf("\nUpdated List:\n");
    display(head);

    return 0;
}