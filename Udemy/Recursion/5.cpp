#include <iostream>
using namespace std;

int pow(int m, int n)
{
    if (n == 0)
        return 1;
    else
        return pow(m, n - 1) * m;
}

int fastPow(int m, int n)
{
    if (n == 0)
        return n;
    if (!n % 2)
        return pow(m * m, n / 2);
    else
        return m * pow(m * m, (n - 1) / 2);
}

int main()
{
    cout << fastPow(2, 5);
}