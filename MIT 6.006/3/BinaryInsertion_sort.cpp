#include <bits/stdc++.h>
using namespace std;

int BS(int A[], int tmp, int lo, int hi)
{
    if (hi <= lo)
        return (tmp > A[lo]) ? (lo + 1) : lo;

    int mid = (lo + hi) >> 1;

    if (tmp == A[mid])
        return mid + 1;

    if (tmp > A[mid])
        BS(A, tmp, mid + 1, hi);
    else
        BS(A, tmp, lo, mid - 1);
}

void insertion_sort(int A[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int j = i - 1;
        int x = A[i];
        int idx = BS(A, x, 0, j);

        while (j >= idx)
            A[j + 1] = A[j], j--;

        A[j + 1] = x;
    }
}

int main()
{
    int A[] = {37, 23, 0, 406, 100, 88, 54};
    int n = sizeof(A) / sizeof(A[0]);

    insertion_sort(A, n);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
}