#ifndef LOUDON_BTREE_H
#define LOUDON_BTREE_H

#include <stdlib.h>

typedef struct BTreeNode_ {
    void *data;
    struct BTreeNode_ *left;
    struct BTreeNode_ *right;
} BTreeNode;

typedef struct BTree_ {
    int size;
    int (*compare)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    BTreeNode *root;
} BTree;

void btree_init(BTree *tree, void (*destroy)(void *data));
void btree_destroy(BTree *tree);


#endif
