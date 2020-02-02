#include <iostream>
#include <vector>
#define ll long long
using namespace std;

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

ll solve(ll n)
{
    ll period = get_pisano_period(10);
    ll ans = get_fibonacci_last_digit_fast((n + 2) % period);
    ans = (ans != 0) ? ans - 1 : 9;
    return ans;
}

int main()
{
    ll n = 0;
    cin >> n;
    cout << solve(n);
}
