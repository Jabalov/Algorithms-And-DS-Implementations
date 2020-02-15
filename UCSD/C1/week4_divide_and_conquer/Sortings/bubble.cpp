#include <stdio.h>
#include <stdlib.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int A[], int n)
{
    int i, j, f = 0;
    for (i = 0; i < n - 1; i++)
    {
        f = 0;
        for (j = i + 1; j <= n - 1; j++)
            if (A[j] < A[i])
                swap(&A[i], &A[j]), f = 1;

        if (!f)
            break;
    }
}

void a_bit_faster_bubble(int A[], int n)
{
    int i, j, flag = 0;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]), flag = 1;

        if (flag == 0)
            break;
    }
}
int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;

    a_bit_faster_bubble(A, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
}