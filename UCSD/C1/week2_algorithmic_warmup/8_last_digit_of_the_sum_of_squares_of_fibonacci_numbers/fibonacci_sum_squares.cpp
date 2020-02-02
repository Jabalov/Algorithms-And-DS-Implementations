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

ll fibonacci_sum_squares(ll n)
{
    ll period = get_pisano_period(10);
    ll Fn = get_fibonacci_last_digit_fast(n % period);
    ll Fn_1 = get_fibonacci_last_digit_fast((n + 1) % period);

    return (Fn * Fn_1) % 10;
}

int main()
{
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_squares(n);
}
