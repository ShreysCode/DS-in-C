#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 3

struct Node {
    int key;
    struct Node *prev, *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

int size = 0;

void moveToFront(struct Node *node) {

    if(node == head)
        return;

    // Remove node
    if(node->prev)
        node->prev->next = node->next;

    if(node->next)
        node->next->prev = node->prev;

    if(node == tail)
        tail = node->prev;

    // Move to front
    node->next = head;
    node->prev = NULL;

    if(head)
        head->prev = node;

    head = node;

    if(tail == NULL)
        tail = head;
}

void insert(int key) {

    struct Node *temp = head;

    // Check if already exists
    while(temp) {

        if(temp->key == key) {
            moveToFront(temp);
            return;
        }

        temp = temp->next;
    }

    // Create new node
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->key = key;
    newNode->prev = NULL;
    newNode->next = head;

    if(head)
        head->prev = newNode;

    head = newNode;

    if(tail == NULL)
        tail = newNode;

    if(size < CAPACITY) {
        size++;
    }
    else {

        // Remove least recently used
        struct Node *del = tail;

        tail = tail->prev;

        if(tail)
            tail->next = NULL;

        free(del);
    }
}

void display() {

    struct Node *temp = head;

    while(temp) {
        printf("%d ", temp->key);
        temp = temp->next;
    }

    printf("\n");
}

int main() {

    insert(1);
    insert(2);
    insert(3);

    display();

    insert(2);

    display();

    insert(4);

    display();

    return 0;
}