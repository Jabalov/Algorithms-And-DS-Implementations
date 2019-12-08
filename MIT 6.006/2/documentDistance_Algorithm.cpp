#include <bits/stdc++.h>
#include <fstream>

#define pi 3.14159265358979323846264338327950288419716939937510
using namespace std;
typedef map<string, int> dict;

void count_words(istream &in, dict &words)
{
    string s;
    while (in >> s)
        words[s]++;
}

int return_mod(dict d)
{
    int mod = 0;
    for (auto p = d.begin(); p != d.end(); p++)
        mod += p->second * p->second;

    return mod;
}

int return_Angle(dict d1, dict d2)
{
    int prod = 0;

    for (auto p1 = d1.begin(); p1 != d1.end(); p1++)
        for (auto p2 = d2.begin(); p2 != d2.end(); p2++)
            if (p1->first == p2->first)
                prod += (p1->second * p2->second);

    return prod;
}

int main()
{

    ifstream f1, f2;
    int Angle;
    int mod1, mod2;
    double mod;
    float distance;

    f1.open("file1.txt", ios::in);
    f2.open("file2.txt", ios::in);

    if (!f1)
        cout << "file 1 error ";
    if (!f2)
        cout << "file 2 error";

    dict d1, d2;

    count_words(f1, d1);
    count_words(f2, d2);

    Angle = return_Angle(d1, d2);
    mod1 = return_mod(d1);
    mod2 = return_mod(d2);
    mod = sqrt(mod1 * mod2);

    distance = 180 * acos(Angle / mod) / pi;

    cout << "the distance between the docments is " << distance;

    getchar();
    return 0;
}