#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct binary_tree
{
    int value;
    int height;
    struct binary_tree *left_child;
    struct binary_tree *right_child;
} binary_tree;

binary_tree *create_tree_from_array(int *arr, int size);
void add_to_tree(binary_tree *node, int value);
void in_order_traversal(binary_tree *node);
void pre_order_traversal(binary_tree *node);
void post_order_traversal(binary_tree *node);
void free_tree(binary_tree *node);

#endif
