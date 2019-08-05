#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array a)
{
    printf("\nElements are..\n");
    for (int i = 0; i < a.length; i++)
        printf("%d ", a.A[i]);
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void Reverse1(struct Array *a)
{
    int *b = (int *)malloc(a->length * sizeof(int));

    for (int j = 0, i = a->length - 1; i >= 0; i--, j++)
        b[j] = a->A[i];

    for (int i = 0; i < a->length; i++)
        a->A[i] = b[i];
}

void Reverse2(struct Array *a)
{
    for (int i = a->length - 1, j = 0; i > j; i--, j++)
        swap(&a->A[i], &a->A[j]);
}

int main()
{
    struct Array arr1 = {
        {2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};
    Reverse2(&arr1);
    Display(arr1);
    return 0;
}