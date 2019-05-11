#include <iostream>
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

int main()
{
    long long n;
    cin >> n;
    long long c = get_fibonacci_last_digit_naive(n);
    cout << c << '\n';
}
