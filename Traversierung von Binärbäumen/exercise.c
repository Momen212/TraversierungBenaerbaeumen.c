#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.c"

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Error: length of the input array < 1\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    binary_tree *root = create_tree_from_array(arr, n);

    printf("Hoehe des Baums: %d\n", root->height);

    printf("In-Order: ");
    in_order_traversal(root);
    printf("\n");

    printf("Pre-Order: ");
    pre_order_traversal(root);
    printf("\n");

    printf("Post-Order: ");
    post_order_traversal(root);
    printf("\n");

    free_tree(root);
    free(arr);
    return 0;
}
