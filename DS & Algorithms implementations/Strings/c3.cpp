#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex>

using namespace std;

int main()
{
    string a = "GeeksForGeeks";
    regex b("[a-zA-Z/0-9]*");

    if (regex_match(a, b))
        cout << "String 'a' matches regular expression 'b' \n";

    return 0;
}