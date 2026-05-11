// Binary Search Tree Insertion + Inorder Traversal

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int value) {
    struct Node* temp = malloc(sizeof(struct Node));

    temp->data = value;
    temp->left = temp->right = NULL;

    return temp;
}

struct Node* insert(struct Node* root, int value) {

    if(root == NULL)
        return create(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {

    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    inorder(root);

    return 0;
}