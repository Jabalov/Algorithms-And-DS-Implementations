#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex>

using namespace std;

#include <stdio.h>

void getDup(char *str)
{
    int h = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        int x = 1;
        x = x << (str[i] - 'a');

        if (x & h)
            printf("character %c is duplicated\n", str[i]);
        else
            h = x | h;
    }
}

int main()
{
    char str[100];
    fgets(str, sizeof(str), stdin);
    getDup(str);

    return 0;
}