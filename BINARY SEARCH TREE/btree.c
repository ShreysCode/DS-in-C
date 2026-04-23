#include <stdio.h>
#include <stdlib.h>

#define M 3

struct BTreeNode {
    int keys[M-1];
    struct BTreeNode* children[M];
    int n;
    int leaf;
};

struct BTreeNode* createNode(int leaf) {
    struct BTreeNode* node = malloc(sizeof(struct BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    for (int i = 0; i < M; i++)
        node->children[i] = NULL;
    return node;
}

void traverse(struct BTreeNode* root) {
    if (root) {
        for (int i = 0; i < root->n; i++) {
            if (!root->leaf)
                traverse(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf)
            traverse(root->children[root->n]);
    }
}