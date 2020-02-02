#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll get_fibonacci_last_digit_fast(ll n)
{
    if (n <= 1)
        return n;

    vector<int> list(n + 1);
    list[0] = 0, list[1] = 1;

    for (ll i = 2; i <= n; i++)
        list[i] = (list[i - 1] + list[i - 2]) % 10;

    return list[n] % 10;
}

ll get_pisano_period(ll m)
{
    ll a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++)
    {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1)
            return i + 1;
    }
}

ll solve1(ll n)
{
    ll period = get_pisano_period(10);
    ll sum = get_fibonacci_last_digit_fast((n + 2) % period); // sum = fib(n+2) - 1
    sum = (sum != 0) ? sum - 1 : 9;
    return sum;
}

ll solve(ll from, ll to)
{
    ll sum_before_from = solve1(from - 1);
    ll sum_to = solve1(to);

    ll sum = (sum_to >= sum_before_from) ? sum_to - sum_before_from : 10 - (sum_before_from - sum_to);
    return sum;
}

int main()
{
    ll from, to;
    cin >> from >> to;
    cout << solve(from, to) << '\n';
}
