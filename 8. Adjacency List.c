#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 20

int graph[MAX_NODES][MAX_NODES] = {0};
int numNodes = 0;

void insertNode() {
    if (numNodes >= MAX_NODES) {
        printf("Graph is full. Cannot insert more nodes.\n");
        return;
    }

    numNodes++;
    printf("Node %d has been inserted.\n", numNodes);
}

void deleteNode(int node) {
    if (node < 1 || node > numNodes) {
        printf("Invalid node number.\n");
        return;
    }
    for (int i = node - 1; i < numNodes - 1; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = graph[i + 1][j];
            graph[j][i] = graph[j][i + 1];
        }
    }

    numNodes--;
    printf("Node %d has been deleted.\n", node);
}

void printGraph() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice, node;

    while (1) {
        printf("\n1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Print Graph\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertNode();
                break;
            case 2:
                printf("Enter the node number to delete: ");
                scanf("%d", &node);
                deleteNode(node);
                break;
            case 3:
                printGraph();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

