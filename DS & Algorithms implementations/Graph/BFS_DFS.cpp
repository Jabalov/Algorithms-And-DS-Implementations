#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void bfs(int A[][7], int start, int n)
{
    int i = start, j;
    int visited[7] = {};

    printf("%d", i);
    visited[i] = 1;
    enqueue(i);

    while (!is_empty())
    {
        i = dequeue();
        for (j = 1; j < n; j++)
            if (A[i][j] == 1 && visited[j] == 0)
            {
                printf(" %d", j);
                visited[j] = 1;
                enqueue(j);
            }
    }
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