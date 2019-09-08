#include <stdio.h>
#include <stdlib.h>
using namespace std;

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
