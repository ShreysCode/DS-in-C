#include <stdio.h>
#include <stdlib.h>

#define M 3

struct BTreeNode {
    int keys[M-1];
    struct BTreeNode* children[M];
    int n;
    int leaf;
};