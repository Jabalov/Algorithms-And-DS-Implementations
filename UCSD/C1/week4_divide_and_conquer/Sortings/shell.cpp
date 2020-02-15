#include <stdio.h>
#include <stdlib.h>
using namespace std;

void shell_sort(int A[], int n)
{
    int i, j, gap, x;

    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            x = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > x)
                A[j + gap] = A[j], j -= gap;

            A[j + gap] = x;
        }
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    shell_sort(A, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
}