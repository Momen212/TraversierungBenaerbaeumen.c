#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int maxi(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

binary_tree *create_node(int value)
{
    binary_tree *node = (binary_tree *)malloc(sizeof(binary_tree));
    node->value = value;
    node->left_child = NULL;
    node->right_child = NULL;
    node->height = 0;
    return node;
}

int get_height(binary_tree *node)
{
    if (node)
        return node->height;

    else
        return 0;
}

void update_height(binary_tree *node)
{
    if (node)
    {
        node->height = 1 + maxi(get_height(node->left_child), get_height(node->right_child));
    }
}

void add_to_tree(binary_tree *node, int value)
{
    if (value < node->value)
    {
        if (node->left_child == NULL)
        {
            node->left_child = create_node(value);
        }
        else
        {
            add_to_tree(node->left_child, value);
        }
    }
    else
    {
        if (node->right_child == NULL)
        {
            node->right_child = create_node(value);
        }
        else
        {
            add_to_tree(node->right_child, value);
        }
    }
    update_height(node);
}

binary_tree *create_tree_from_array(int *arr, int size)
{
    if (size == 0)
        return NULL;

    binary_tree *root = create_node(arr[0]);
    for (int i = 1; i < size; i++)
    {
        add_to_tree(root, arr[i]);
    }
    return root;
}

void in_order_traversal(binary_tree *node)
{
    if (node == NULL)
        return;
    in_order_traversal(node->left_child);
    printf("%d ", node->value);
    in_order_traversal(node->right_child);
}

void pre_order_traversal(binary_tree *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->value);
    pre_order_traversal(node->left_child);
    pre_order_traversal(node->right_child);
}

void post_order_traversal(binary_tree *node)
{
    if (node == NULL)
        return;
    post_order_traversal(node->left_child);
    post_order_traversal(node->right_child);
    printf("%d ", node->value);
}

// Speicherfreigabe
void free_tree(binary_tree *node)
{
    if (node != NULL)
    {
        free_tree(node->left_child);
        free_tree(node->right_child);
        free(node);
    }
}
