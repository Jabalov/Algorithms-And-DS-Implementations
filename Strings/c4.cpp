#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex>

using namespace std;

int main()
{
    int i = 0;
    char A[] = "python";

    for (; A[i] != '\0'; i++)
        ;

    char B[6 + 1];
    i--;
    //reverse
    for (int j = 0; i >= 0; j++, i--)
        B[j] = A[i];

    B[6] = '\0';
    printf("%s", B);
}