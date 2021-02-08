#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;


int fib_recursive_dp(int n, int *arr)
{
    if(n == 0 || n == 1)
        return 1;

    if(arr[n] != 0)
        return arr[n];

    int answer = fib_recursive_dp(n - 1, arr) + fib_recursive_dp(n - 2, arr);
    arr[n] = answer;
    return answer;
}

int fib_iterative_dp(int n)
{
    int *arr = new int(n + 1);
    arr[0] = arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    int answer = arr[n];
    delete[] arr;
    return answer;
}