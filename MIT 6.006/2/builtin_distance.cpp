#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    int num = distance(v.begin(), v.end());
    cout << num << "\n";
}