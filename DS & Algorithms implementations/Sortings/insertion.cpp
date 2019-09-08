#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void insertion(int A[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        // tmp_i = i;
        x = A[i];
        while (j >= 0 && A[j] > x)
            A[j + 1] = A[j], j--; // swap(&A[tmp_i--], &A[j--]); without the line down there.

        A[j + 1] = x;
    }
}
int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;

    insertion(A, n);

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
}