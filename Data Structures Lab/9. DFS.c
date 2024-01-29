#include <stdio.h>
#include <stdlib.h>
#define v 5

int visited[5];
int adjMatrix[v][v] = {
    {0, 1, 1, 1, 0},
    {1, 0, 1, 0, 0},
    {1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0}};

void dfs(int start_vertex)
{

    printf("%d ", start_vertex);

    visited[start_vertex] = 1;

    for (int i = 0; i < v; i++)
    {
        if (adjMatrix[start_vertex][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    dfs(0);
    return 0;
}
