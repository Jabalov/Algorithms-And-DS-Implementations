#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void bfs(int A[][7], int start, int n)
{
    int u = start, v;
    int visited[7] = {};

    printf("%d", u);
    visited[u] = 1;
    enqueue(u);

    while (!is_empty())
    {
        u = dequeue();
        for (v = 1; v < n; v++)
            if (A[u][v] == 1 && visited[v] == 0)
            {
                printf(" %d", v);
                visited[v] = 1;
                enqueue(v);
            }
    }
}

void dfs(int A[][7], int start, int n)
{
}

int main()
{
    int A[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    bfs(A, 4, 7);

    return 0;
}