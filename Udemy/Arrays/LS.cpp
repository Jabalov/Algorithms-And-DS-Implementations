#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LS(struct Array *arr, int x)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == x)
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int main()
{
    struct Array arr1 = {{2, 23, 14, 5, 6, 9, 8, 12}, 10, 8};
    printf("%d", LS(&arr1, 14));
    return 0;
}