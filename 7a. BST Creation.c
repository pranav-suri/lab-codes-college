
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create_node(int data)
{

    // Creating a node pointer
    struct Node *n;

    // Allocating memory in the heap:
    n = (struct Node *)malloc(sizeof(struct Node));

    // Setting node data = user input data:
    n->data = data;

    // Setting the left and right children to NULL:
    n->left = NULL;
    n->right = NULL;

    return n;
}

int main()
{

    struct Node *head = create_node(2);

    struct Node *a = create_node(1);
    struct Node *b = create_node(4);

    struct Node *c = create_node(11);
    struct Node *d = create_node(12);

    struct Node *e = create_node(3);

    // Linking head node with a and b on its left and right side respectively:
    head->left = a;
    head->right = b;

    // Linking a with c and d on its left and right side respectively:
    a->left = c;
    a->right = d;

    // Linking b with NULL and e on its left and right side respectively:
    b->left = NULL;
    b->right = e;

    return 0;
}
