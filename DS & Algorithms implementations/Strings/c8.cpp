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

void perm1(char *s, int lo, int hi)
{
    if (lo == hi)
        printf("%s\n", s);

    else
        for (int i = lo; i <= hi; i++)
        {
            swap(s[lo], s[i]);
            perm1(s, lo + 1, hi);
            swap(s[lo], s[i]);
        }
}

int main()
{
    char s[] = "ABCD";
    perm1(s, 0, 3);
}