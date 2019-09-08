#include <stdio.h>
#include <stdlib.h>
using namespace std;

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partitioning(int A[], int lo, int hi)
{
    int pivot = A[lo];
    int i = lo, j = hi;
    do
    {
        do
        {
            i++;
        } while (pivot >= A[i]);

        do
        {
            j--;
        } while (pivot < A[j]);

        if (j > i)
            swap(&A[i], &A[j]);
    } while (j > i);

    swap(&A[lo], &A[j]);
    return j;
}

void quick(int A[], int lo, int hi)
{
    int idx;
    if (lo < hi)
    {
        idx = partitioning(A, lo, hi);
        quick(A, lo, idx);
        quick(A, idx + 1, hi);
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;

    quick(A, 0, n);

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
}