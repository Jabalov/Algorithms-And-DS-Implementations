#include <stdio.h>
#include <stdlib.h>
using namespace std;

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void selection(int A[], int n)
{
    int i, j, pos;
    for (i = 0; i < n - 1; i++)
    {
        pos = i;
        for (j = i; j < n; j++)
            if (A[j] < A[pos])
                pos = j;

        swap(&A[i], &A[pos]);
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    selection(A, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
}