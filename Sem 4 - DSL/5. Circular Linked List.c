#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create() {
    int n, data;
    struct Node *newNode, *temp;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = data;
    head->next = head;
    temp = head;

    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = head;
        temp->next = newNode;
        temp = newNode;
    }

    printf("Circular linked list created successfully.\n");
}

void insertBegin() {
    int data;
    struct Node *newNode;
    if (head == NULL) {
        printf("The circular linked list is empty. Create a list first.\n");
        return;
    }

    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at the beginning.\n");
}

void insertEnd() {
    int data;
    struct Node *newNode, *temp;
    if (head == NULL) {
        printf("The circular linked list is empty. Create a list first.\n");
        return;
    }

    printf("Enter data to insert at the last: ");
    scanf("%d", &data);
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    printf("Node inserted at the last.\n");
}

void insertAtLocation() {
    int data, position;
    struct Node *newNode, *temp;
    if (head == NULL) {
        printf("The circular linked list is empty. Create a list first.\n");
        return;
    }

    printf("Enter data to insert: ");
    scanf("%d", &data);
    printf("Enter the position to insert: ");
    scanf("%d", &position);

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position exceeds the length of the list.\n");
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", position);
}

void deleteBegin() {
    struct Node *temp;
    if (head == NULL) {
        printf("The circular linked list is empty. Create a list first.\n");
        return;
    }

    temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    if (temp == head) {
        head = NULL;
    } else {
        temp->next = head->next;
        head = head->next;
    }
    free(temp);
    printf("Node from the beginning deleted.\n");
}

void deleteEnd() {
    struct Node *current, *prev;
    if (head == NULL) {
        printf("The circular linked list is empty. Create a list first.\n");
        return;
    }

    current = head;
    while (current->next != head) {
        prev = current;
        current = current->next;
    }
    if (current == head) {
        head = NULL;
    } else {
        prev->next = head;
    }
    free(current);
    printf("Node from the last deleted.\n");
}

void deleteAfterLocation() {
    int position;
    struct Node *current, *temp;
    if (head == NULL) {
        printf("The circular linked list is empty. Create a list first.\n");
        return;
    }

    printf("Enter the position after which to delete: ");
    scanf("%d", &position);

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    current = head;
    for (int i = 1; i < position; i++) {
        temp = current;
        current = current->next;
        if (current == head) {
            printf("Position exceeds the length of the list.\n");
            return;
        }
    }
    temp->next = current->next;
    free(current);
    printf("Node after position %d deleted.\n", position);
}

void reverse() {
    struct Node *prev, *current, *next;
    if (head == NULL) {
        printf("The circular linked list is empty. Create a list first.\n");
        return;
    }

    current = head;
    prev = NULL;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    head->next = prev;
    head = prev;
    printf("Circular linked list reversed.\n");
}

void concatenate() {
    int data;
    struct Node *newNode, *temp;
    if (head == NULL) {
        printf("The first circular linked list is empty. Create a list first.\n");
        return;
    }

    printf("Enter the number of nodes for the second list: ");
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes for the second list.\n");
        return;
    }

    printf("Enter data for the first node of the second list: ");
    scanf("%d", &data);
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;

    temp = newNode;

    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = head;
        temp->next = newNode;
        temp = newNode;
    }

    printf("Second circular linked list created and concatenated successfully.\n");
}

void display() {
    struct Node *current;
    if (head == NULL) {
        printf("The circular linked list is empty. Create a list first.\n");
        return;
    }

    printf("Circular Linked List: ");
    current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf(" (Back to head)\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Insert at the Beginning\n");
        printf("3. Insert at the Last\n");
        printf("4. Insert at Any Random Location\n");
        printf("5. Delete from the Beginning\n");
        printf("6. Delete from the Last\n");
        printf("7. Delete Node after Specified Location\n");
        printf("8. Reverse Circular Linked List\n");
        printf("9. Concatenate Circular Linked Lists\n");
        printf("10. Display Circular Linked List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insertBegin();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                insertAtLocation();
                break;
            case 5:
                deleteBegin();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                deleteAfterLocation();
                break;
            case 8:
                reverse();
                break;
            case 9:
                concatenate();
                break;
            case 10:
                display();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


