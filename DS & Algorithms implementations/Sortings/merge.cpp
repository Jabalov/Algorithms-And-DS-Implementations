#include <stdio.h>
#include <stdlib.h>
using namespace std;

void merge(int A[], int lo, int mid, int hi)
{
    int i = lo, j = mid + 1, k = lo;
    int B[100];

    while (i <= mid && j <= hi)
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];

    for (; i <= mid; i++)
        B[k++] = A[i];

    for (; j <= hi; j++)
        B[k++] = A[j];

    for (i = lo; i <= hi; i++)
        A[i] = B[i];
}

void iterative_merge_sort(int A[], int n)
{
    int p, l, h, mid, i;
    for (p = 2; p <= n; p *= 2)
        for (i = 0; i + p - 1 <= n; i += p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) >> 1;
            merge(A, l, mid, h);
        }

    if (p / 2 < n)
        merge(A, 0, p / 2 - 1, n);
}

void recursive_merge_sort(int A[], int lo, int hi)
{
    int mid;
    if (lo < hi)
    {
        mid = (lo + hi) >> 1;
        recursive_merge_sort(A, lo, mid);
        recursive_merge_sort(A, mid + 1, hi);
        merge(A, lo, mid, hi);
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;

    iterative_merge_sort(A, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
}