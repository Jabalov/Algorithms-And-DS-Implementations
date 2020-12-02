#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int memo[100];
int fib_dp(int x) //bottom-up approach
{
    memo[0] = 0, memo[1] = 1;

    for (int i = 2; i <= x; i++)
        memo[i] = memo[i - 1] + memo[i - 2];

    return memo[x];
}

int fib_recursive(int x) // Heavy On Memory Space. Causes overlaping sub-problems. O(2^n)
{
    static int count = 0;
    count++;
    if (x < 0)
        return -1;
    if (x <= 1)
        return x;

    int num = fib_recursive(x - 1) + fib_recursive(x - 2);
    return count; // return num;
}

int main()
{
    cout << fib_dp(10);
}