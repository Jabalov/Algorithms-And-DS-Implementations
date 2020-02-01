#include <iostream>
#include <vector>

using namespace std;

long long get_fibonacci_last_digit_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

long long get_fibonacci_last_digit_fast(long long n)
{
    if (n <= 1)
        return n;
    vector<int> list(n + 1);
    list[0] = 0, list[1] = 1;

    for (long long i = 2; i <= n; i++)
        list[i] = (list[i - 1] + list[i - 2]) % 10;

    return list[n] % 10;
}

int main()
{
    long long n;
    cin >> n;
    long long c = get_fibonacci_last_digit_fast(n);
    cout << c << '\n';
}
