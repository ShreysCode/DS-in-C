#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data, height;
    struct Node *left, *right;
};

int max(int a, int b) { return (a > b) ? a : b; }

int height(struct Node* n) {
    return n ? n->height : 0;
}

struct Node* createNode(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

// Right rotation
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
