#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

void count_sort(int A[], int n)
{
    int i, j, maxi = INT32_MIN, *C;

    for (i = 0; i < n; i++)
        maxi = max(maxi, A[i]);

    C = (int *)malloc(sizeof(int) * (maxi + 1));

    for (i = 0; i < maxi + 1; i++)
        C[i] = 0;

    for (i = 0; i < n; i++)
        C[A[i]]++;

    i = j = 0;
    while (j <= maxi)
        if (C[j] > 0)
            A[i++] = j, C[j]--;
        else
            j++;
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;

    count_sort(A, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
}