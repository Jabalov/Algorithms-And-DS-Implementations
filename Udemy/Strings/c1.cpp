#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    char name[] = "john";
    int i = 0, cnt = 0;

    while (name[i] != '\0')
        i++, cnt++;

    cout << cnt;
}