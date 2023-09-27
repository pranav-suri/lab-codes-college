#include <stdio.h>
#include <stdlib.h>
// create menu for this program
// Ask user for input of data
// Ask user for location to add the node (beginning, end, or middle)

struct Node
{
    int data;
    struct Node *next;
};

struct Node *create_node(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void start_node(struct Node **head, int data)
{
    struct Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
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
}

void del_start(struct Node **head)
{
    struct Node *current = *head;
    *head = current->next;
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
    }
}

void remove_duplicates(struct Node *head)
{
    struct Node *current = head;

    while (current != NULL)
    {
        struct Node *p = current;

        while (p->next != NULL)
        {
            if (current->data == p->next->data)
            {
                struct Node *temp = p->next;
                p->next = p->next->next;
                free(temp);
            }
            else
            {
                p = p->next;
            }
        }
        current = current->next;
    }
}

/* void reverse(struct Node **head){
    struct Node *start = *head;
    struct Node *end = *head;
    struct Node *temp;
    int length = 0;
    while (end->next != NULL){
        length++;
        end = end->next;
    }
    int start_pos = 0, final_end = length;
    while (start_pos <= length / 2){
        end = start;
        int curr_pos = start_pos;
        while (curr_pos < final_end){
            curr_pos++;
            end = end->next;
        }
        temp = start->next;
        start->next = end->next;
        end->next = temp;
        if (start == *head){
            *head = end;
        }
        start = temp;
        start_pos++;
        final_end--;
    }
}
*/

void reverse(struct Node **head)
{
    struct Node *p = *head;
    struct Node *q = NULL;
    struct Node *r = p->next;

    while (p != NULL)
    {
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
    *head = q;
}

/* void reverse(struct Node *head){
    int final_pos, length = 0, start_pos = 0;
    struct Node *current = head;
    while(current -> next != NULL){
        current = current->next;
        length++;
    }
    current = head;
    final_pos = length;
    struct Node *end;
    for (start_pos = 0; start_pos < final_pos; start_pos++){
        end = current;
        for (int i = start_pos; i < final_pos; i++){
            end = end->next;
        }

        int temp = current->data;
        current->data = end->data;
        end->data = temp;

        final_pos--;
        current = current->next;
    }
}
*/

void concat(struct Node *head1, struct Node *head2)
{
    struct Node *curr1 = head1;
    while (curr1->next != NULL)
    {
        curr1 = curr1->next;
    }
    curr1->next = head2;
}

void union_ll(struct Node *head1, struct Node *head2)
{
    concat(head1, head2);
    remove_duplicates(head1);
}

void intersection(struct Node *head1, struct Node *head2)
{
    remove_duplicates(head1);
    remove_duplicates(head2);

    struct Node *curr1, *curr2;
    curr1 = head1;
    curr2 = head2;
    while (curr1 != NULL)
    {
        curr2 = head2;
        while (curr2 != NULL)
        {
            if (curr1->data == curr2->data)
            {
                printf("%d ", curr1->data);
                break;
            }
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
}

void display_list(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void bub_sort(struct Node *head)
{
    struct Node *i = head;
    struct Node *j;
    while (i != NULL)
    {
        j = i;
        while (j != NULL)
        {
            if (j->data < i->data)
            {
                int temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

int main()
{
    struct Node *head1 = create_node(1);
    end_node(head1, 2);
    end_node(head1, 3);
    end_node(head1, 4);
    display_list(head1);
    printf("\n");

    struct Node *head2 = create_node(1);
    end_node(head2, 3);
    end_node(head2, 4);
    display_list(head2);
    printf("\n");

    concat(head1, head2);
    bub_sort(head1);
    display_list(head1);
    printf("\n");

    reverse(head1);
    display_list(head1);
}
