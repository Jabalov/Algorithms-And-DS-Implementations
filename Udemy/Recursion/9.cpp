#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int nCr(int n, int r)
{

    int num = fact(n);
    int den = fact(r) * fact(n - r);

    return num / den;
}

int pascal(int n, int r)
{
    if (r == n || r == 0)
        return 1;

    return pascal(n - 1, r - 1) + pascal(n - 1, r);
}

int main()
{
    cout << pascal(4, 2);
}