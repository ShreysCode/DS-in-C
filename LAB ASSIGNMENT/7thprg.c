#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Insert at end
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
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(circular)\n");
}

// Delete ALL occurrences (FIXED)
struct Node* deleteAll(struct Node* head, int key) {
    if (head == NULL) return NULL;

    struct Node* current = head;
    int flag = 0; // track if any deletion happened

    // Count total nodes first (important!)
    int count = 0;
    struct Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    // Traverse exactly 'count' times
    for (int i = 0; i < count; i++) {
        struct Node* nextNode = current->next;

        if (current->data == key) {
            flag = 1;

            // Single node case
            if (current->next == current) {
                free(current);
                return NULL;
            }

            // Adjust links
            current->prev->next = current->next;
            current->next->prev = current->prev;

            // Update head if needed
            if (current == head)
                head = nextNode;

            free(current);
        }

        current = nextNode;
    }

    if (!flag)
        printf("Value not found.\n");

    return head;
}

int main() {
    struct Node* head = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nOriginal List:\n");
    display(head);

    printf("\nEnter value to delete: ");
    scanf("%d", &key);

    head = deleteAll(head, key);

    printf("\nUpdated List:\n");
    display(head);

    return 0;
}