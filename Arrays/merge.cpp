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

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

struct Array *Merge(struct Array *a1, struct Array *a2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *a3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < a1->length && j < a2->length)
    {
        if (a1->A[i] < a2->A[j])
            a3->A[k++] = a1->A[i++];
        else
            a3->A[k++] = a2->A[j++];
    }
    for (; i < a1->length; i++)
        a3->A[k++] = a1->A[i];

    for (; j < a2->length; j++)
        a3->A[k++] = a2->A[j];

    a3->length = a1->length + a2->length;
    a3->size = 10;

    return a3;
}

int main()
{
    struct Array arr1 = {{2, 9, 21, 28, 35}, 10, 5};
    struct Array arr2 = {{2, 3, 16, 18, 28}, 10, 5};
    struct Array *arr3;
    arr3 = Merge(&arr1, &arr2);
    Display(*arr3);

    return 0;
}