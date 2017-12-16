#include <stdlib.h>
#include <string.h>

#include <loudon/btree.h>

void btree_init(BTree *tree, void (*destroy)(void *data)) {
    tree->size = 0;
    tree->destroy = destroy;
    tree->root = NULL;
    return;
}

void btree_destroy(BTree *tree) {
    btree_rem_left(tree, NULL);
    memset(tree, 0, sizeof(BTree));
}

int btree_ins_left(BTree *tree, BTreeNode *node, const void *data) {
    BTreeNode  *new_node, 
              **position;
    if (node == NULL) {
        if (btree_size(tree) > 0)
            return -1;
        position = &tree->root;    
    }
    else {
        if (btree_left(node) != NULL)
            return -1;
        position = &node->left;    
    }
    if ((new_node = (BTreeNode *)malloc(sizeof(BTreeNode))) == NULL)
        return -1;
    new_node->data = (void *)data;
    new_node->left = NULL;
    new_node->right = NULL;
    *position = new_node;
    tree->size++;
    return 0;
}

int btree_ins_right(BTree *tree, BTreeNode *node, const void *data) {
    BTreeNode  *new_node,
              **position;
    if (node == NULL) {
        if (btree_size(tree) > 0)
            return -1;
        position = &tree->root;
    }  
    else {
        if (btree_right(node) != NULL)
            return -1;
        position = &node->right;
    }
    if ((new_node = (BTreeNode *)malloc(sizeof(BTreeNode))) == NULL)
        return -1;
    new_node->data = (void *)data;
    new_node->left = NULL;
    new_node->right = NULL;
    *position = new_node;
    tree->size++;
    return 0;
}

void btree_rem_left(BTree *tree, BTreeNode *node) {
    BTreeNode **position;
    if (btree_size(tree) == 0)
        return;
    if (node == NULL)
        position = &tree->root;
    else
        position = &node->left;
    if (*position != NULL) {
        btree_rem_left(tree, *position);
        btree_rem_right(tree, *position);
        if (tree->destroy != NULL)
            tree->destroy((*position)->data);
        free(*position);
        *position = NULL;
        tree->size--;
    }
    return;
}

void btree_rem_right(BTree *tree, BTreeNode *node) {
    BTreeNode **position;
    if (btree_size(tree) == 0)
        return;
    if (node == NULL)
        position = &tree->root;
    else
        position = &node->right;
    if (*position != NULL) {
        btree_rem_left(tree, *position);
        btree_rem_right(tree, *position);
        if (tree->destroy != NULL)
            tree->destroy((*position)->data);
        free(*position);
        *position = NULL;
        tree->size--;
    }
    return;
}

int btree_merge(BTree *merge, BTree *left, BTree *right, const void *data) {
    btree_init(merge, left->destroy);
    if (btree_ins_left(merge, NULL, data) != 0) {
        btree_destroy(merge);
        return -1;
    }
    btree_root(merge)->left = btree_root(left);
    btree_root(merge)->right = btree_root(right);
    merge->size = merge->size + btree_size(left) + btree_size(right);
    left->root = NULL;
    left->size = 0;
    right->root = NULL;
    right->size = 0;
    return 0;
}
