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

struct Array *Union(struct Array *a1, struct Array *a2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *a3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < a1->length && j < a2->length)
    {
        if (a2->A[i] < a2->A[j])
            a3->A[k++] = a2->A[i++];

        else if (a2->A[j] < a2->A[i])
            a3->A[k++] = a2->A[j++];

        else
            a3->A[k++] = a2->A[i++],
            j++;
    }

    for (; i < a1->length; i++)
        a3->A[k++] = a1->A[i];
    for (; j < a2->length; j++)
        a3->A[k++] = a2->A[j];

    a3->length = k;
    a3->size = 10;

    return a3;
}

struct Array *intersection(struct Array *a1, struct Array *a2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *a3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < a1->length && j < a2->length)
    {
        if (a1->A[i] < a2->A[j])
            i++;
        else if (a1->A[i] > a2->A[j])
            j++;
        else if (a1->A[i] == a2->A[j])
            a3->A[k++] = a1->A[i++], j++;
    }
    a3->length = k;
    a3->size = 10;
    return a3;
}

struct Array *Difference(struct Array *a1, struct Array *a2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *a3 = (struct Array *)malloc(sizeof(struct Array));
    while (i < a1->length && j < a2->length)
    {
        if (a1->A[i] < a2->A[j])
            a3->A[k++] = a1->A[i++];
        else if (a2->A[j] < a1->A[i])
            j++;
        else
            i++, j++;
    }
    for (; i < a1->length; i++)
        a3->A[k++] = a1->A[i];
    a3->length = k;
    a3->size = 10;

    return a3;
}

int main()
{
    struct Array arr1 = {{2, 9, 21, 28, 35}, 10, 5};
    struct Array arr2 = {{2, 3, 9, 18, 28}, 10, 5};
    struct Array *arr3;
    arr3 = Union(&arr1, &arr2);
    Display(*arr3);

    return 0;
}