#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int *A[3];
    A[0] = new int[4];
    A[1] = new int[4];
    A[2] = new int[4];

    int **B;
    B = new int *[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
}