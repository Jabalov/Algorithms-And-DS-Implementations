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

int BS(struct Array arr, int x)
{
    int lo = 0, hi = arr.length - 1, mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (arr.A[mid] == x)
            return mid;
        else if (arr.A[mid] > x)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}

int main()
{
    struct Array arr1 = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};
    printf("%d", BS(arr1, 16));
}