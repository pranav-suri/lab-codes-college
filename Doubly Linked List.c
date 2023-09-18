#include <stdio.h>
#include <stdlib.h>
// create menu for this program
// Ask user for input of data
// Ask user for location to add the node (beginning, end, or middle)

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *create_node(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

struct Node *start_node(struct Node *head, int data)
{
    struct Node *new_node = create_node(data);
    new_node->next = head;
    head->prev = new_node;
    return new_node;
}

void mid_node(struct Node *head, int data, int index)
{
    struct Node *new_node = create_node(data);
    struct Node *current = head;
    int pos = 0;
    if (index == 0)
    {
        start_node(&head, data);
    }
    else
    {
        while (pos != index - 1)
        {
            current = current->next;
            pos++;
        }
    }
    new_node->next = current->next;
    new_node->prev = current;
    new_node->next->prev = new_node;
    current->next = new_node;
}

void end_node(struct Node *head, int data)
{
    struct Node *new_node = create_node(data);
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void del_start(struct Node **head)
{
    struct Node *current = *head;
    *head = current->next;
    (*head)->prev = NULL;
    free(current);
}

void del_end(struct Node *head)
{
    struct Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void del_mid(struct Node *head, int index)
{
    struct Node *current = head;
    int pos = 0;
    if (index == 0)
    {
        del_start(&head);
    }
    else
    {
        while (pos != index - 1)
        {
            current = current->next;
            pos++;
        }
        struct Node *temp = current->next->next;
        free(current->next);
        current->next = temp;
        temp->prev = current;
    }
}

void display_list(struct Node *head)
{
    struct Node *current = head;
    while (current->next != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{
    struct Node *head = create_node(1);
    end_node(head, 2);
    end_node(head, 3);
    end_node(head, 5);
    head = start_node(head, 0);
    mid_node(head, 4, 1);
    display_list(head);
}
