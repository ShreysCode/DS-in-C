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