#include <iostream>
using namespace std;

double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;

    if (n == 0)
        return 1;
    else
    {
        r = e(x, n - 1);
        p *= x;
        f *= n;
        return r + p / f;
    }
}

int main()
{
    printf("%lf", e(1, 10));
}