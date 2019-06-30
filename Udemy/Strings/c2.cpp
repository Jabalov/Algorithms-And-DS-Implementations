#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    char A[] = "HeLLo";

    int i = 0;
    while (A[i] != '\0')
    {
        if (A[i] >= 'a' && A[i] <= 'z')
            A[i] += -32;
        else
            A[i] += 32;

        i++;
    }

    printf("%s", A);
}