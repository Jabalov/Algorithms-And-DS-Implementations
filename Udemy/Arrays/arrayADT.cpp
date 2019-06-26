#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Array
{
    int *A;
    int size;
    int len;
};

void display(struct Array a)
{
    printf("\n Elements are: \n");
    for (int i = 0; i < a.len; i++)
        printf("%d ", a.A[i]);
}

int main()
{
    int n;
    struct Array arr;
    printf("Enter size of an array \n");
    scanf("%d", &arr.size);

    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.len = 0;

    printf("Enter how many numbers \n");
    scanf("%d", n);

    printf("Enter all elements \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr.A[i]);
    arr.len = n;

    display(arr);
}