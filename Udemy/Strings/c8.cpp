#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex>

using namespace std;

#include <stdio.h>

void perm(char s[], int k)
{
    static int A[10] = {0};
    static char res[10];

    if (s[k] == '\0')
        res[k] = '\0', printf("%s\n", res);

    else
        for (int i = 0; s[i] != '\0'; i++)
            if (A[i] == 0)
            {
                res[k] = s[i];
                A[i] = 1;
                perm(s, k + 1);
                A[i] = 0;
            }
}

int main()
{
    char s[] = "ABC";
    perm(s, 0);
}