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
int btree_ins_left(BTree *tree, BTreeNode *node, const void *data);
int btree_ins_right(BTree *tree, BTreeNode *node, const void *data);
void btree_rem_left(BTree *tree, BTreeNode *node);
void btree_rem_right(BTree *tree, BTreeNode *node);
int btree_merge(BTree *merge, BTree *left, BTree *right, const void *data);

#define btree_size(tree) ((tree)->size)
#define btree_root(tree) ((tree)->root)
#define btree_is_eob(node) ((node) == NULL)
#define btree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)
#define btree_data(node) ((node)->data)
#define btree_left(node) ((node)->left)
#define btree_right(node) ((node)->right)

#endif
