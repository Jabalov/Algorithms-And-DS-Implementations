#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex>

using namespace std;

int main()
{
    char *c = "finding";
    int H[26] = {0};

    for (int i = 0; c[i] != '\0'; i++)
        H[c[i] - 97]++;

    for (int i = 0; i < 26; i++)
        if (H[i] > 1)
            printf("%c ", i + 97),
                printf("%d times \n", H[i]);
}