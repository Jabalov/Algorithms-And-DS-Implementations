#include <bits/stdc++.h>
using namespace std;

#define ll long long

void selection_sort(ll A[])
{
    ll pos = 0, min = 0;
    ll n = 10;

    for (int i = 0; i < n - 1; i++)
    {
        pos = i, min = A[i];
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[pos])
                min = A[j], pos = j;
        }
        swap(A[i], A[pos]);
    }
}

int main()
{
    const int n = 10;
    ll A[n];

    for (int i = 0; i < 10; i++)
        cin >> A[i];

    selection_sort(A);

    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
}