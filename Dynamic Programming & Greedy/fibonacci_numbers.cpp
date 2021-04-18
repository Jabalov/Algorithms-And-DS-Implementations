#include<iostream>
#include<vector>
using namespace std;

int recursive_fib(int x)
{
    if(x <= 1)
        return x;

    return recursive_fib(x - 1) + recursive_fib(x - 2);
}

long long dp_fib1(int x)
{
    vector<long long> fib(x);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= x; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[x];
}

long long dp_fib2(int x)
{
    vector<long long> fib;
    for(int i = 0; i <= x; i++)
        fib.push_back(-1);

    if(fib[x] == -1)
    {
        if(x <= 1)
            fib[x] = x;
        else
            fib[x] = dp_fib2(x - 1) + dp_fib2(x - 2);
    }
    return fib[x];
}

int main()
{
    cout << dp_fib2(50);
}