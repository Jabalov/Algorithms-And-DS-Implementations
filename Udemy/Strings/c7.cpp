#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex>

using namespace std;

#include <stdio.h>

int main()
{
    char *s1 = "medical", *s2 = "decimal";
    int H[26] = {0};

    for (int i = 0; s1[i] != '\0'; i++)
        H[s1[i] - 'a']++;

    for (int i = 0; s2[i] != '\0'; i++)
        H[s2[i] - 'a']--;

    for (int i = 0; i < 26; i++)
        if (H[i] < 0)
            return printf("NOT angrams"), 0;

    printf("Angrams!");
}