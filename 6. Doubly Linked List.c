#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void traversal(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

struct Node *start_insert(struct Node *head, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node *between_insert(struct Node *head, int data, int index)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *end_insert(struct Node *head, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    ptr->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct Node *start_delete(struct Node *head)
{

    struct Node *ptr = head;

    head = head->next;
    free(ptr);
    return head;
}

struct Node *between_delete(struct Node *head, int index)
{

    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

struct Node *end_delete(struct Node *head)
{

    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

void reverse(struct Node *head)
{

    struct Node *prev, *current;

    if (head != NULL)
    {
        prev = head;
        current = head->next;
        head = head->next;

        prev->next = NULL; // Make first node as last node

        while (head != NULL)
        {
            head = head->next;
            current->next = prev;

            prev = current;
            current = head;
        }

        head = prev; // Make last node as head
    }
}

void concat(struct Node *a, struct Node *b)
{

    if (a != NULL && b != NULL)
    {
        if (a->next == NULL)
        {
            a->next = b;
        }

        else
        {
            concat(a->next, b);
        }
    }

    else
    {
        printf("Either a or b is NULL \n");
    }
}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocating memory for nodes in the linked list in Heap (Dynamic):
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 2;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 6;
    third->next = NULL;

    printf("Linked list before any operation: \n");
    traversal(head);

    int choice;
    printf("------- Doubly Linked List Menu -------- \n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at a certain Index\n");
    printf("3. Insert at the end\n");
    printf("4. Delete at the beginning\n");
    printf("5. Delete at a certain index\n");
    printf("6. Delete at the end\n");
    printf("7. Reverse the Linked List\n");
    printf("8. Concatenate the Linked List\n");
    printf("--------------------------------------------- \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        int n;
        printf("Enter the data of the node: ");
        scanf("%d", &n);
        head = start_insert(head, n);
        printf("\nLinked list after insertion: \n");
        traversal(head);

        break;
    }

    case 2:
    {
        int n, i;
        printf("Enter the data of the node and the index at which it is to be inserted: ");
        scanf("%d %d", &n, &i);

        head = between_insert(head, n, i);
        printf("\nLinked list after insertion: \n");
        traversal(head);

        break;
    }

    case 3:
    {
        int n;
        printf("Enter the data of the node: ");
        scanf("%d", &n);
        head = end_insert(head, n);
        printf("\nLinked list after insertion: \n");
        traversal(head);
        break;
    }

    case 4:
    {
        head = start_delete(head);
        printf("\nDoubly linked list after deletion: \n");
        traversal(head);

        break;
    }

    case 5:
    {
        int i;
        printf("Enter the index at which node is to be deleted: ");
        scanf("%d", &i);
        head = between_delete(head, i);
        printf("\nDoubly linked list after insertion: \n");
        traversal(head);

        break;
    }

    case 6:
    {
        head = end_delete(head);
        printf("\nDoubly linked list after deletion: \n");
        traversal(head);

        break;
    }

    case 7:
    {
        printf("Doubly Linked List Initially: \n");
        traversal(head);

        printf("Doubly Linked List Reversed: \n");
        reverse(head);
        traversal(head);

        break;
    }

    case 8:
    {
        struct Node *another_head = (struct Node *)malloc(sizeof(struct Node));
        struct Node *another_second = (struct Node *)malloc(sizeof(struct Node));
        struct Node *another_third = (struct Node *)malloc(sizeof(struct Node));

        another_head->data = 1;
        another_head->next = another_second;

        another_second->data = 3;
        another_second->next = another_third;

        another_third->data = 5;
        another_third->next = NULL;

        printf("First Linked List: \n");
        traversal(head);

        printf("Second Linked List: \n");
        traversal(another_head);

        printf("Concatenated Linked List: \n");
        concat(head, another_head);
        traversal(head);

        break;
    }

    default:
        printf("Invalid Option.");

        break;
    }

    return 0;
}
