#include <iostream>
#include <vector>
#include <algorithm>
#include <new>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of elements \n";
    cin >> n;

    int *p;
    p = new (nothrow) int[n];

    if (p == nullptr)
        cout << "Memory couldn't be Allocated \n";

    else
    {
        for (int i = 0; i < n; i++)
            cout << "enter a number \n", cin >> p[i];

        cout << "numbers you have entered: \n";
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";

        delete[] p;
    }
}
