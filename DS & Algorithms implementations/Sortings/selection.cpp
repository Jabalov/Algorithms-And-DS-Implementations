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
    int i, j, tmp_i;
    for (i = 0; i < n - 1; i++)
    {
        tmp_i = i;
        for (j = i; j < n; j++)
            if (A[j] < A[tmp_i])
                tmp_i = j;

        swap(&A[i], &A[tmp_i]);
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    selection(A, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
}