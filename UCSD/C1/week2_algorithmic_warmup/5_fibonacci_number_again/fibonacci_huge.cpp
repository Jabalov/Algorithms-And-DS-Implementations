#include <iostream>
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

ll get_fibonacci_huge(ll n, ll m)
{
    ll remainder = n % get_pisano_period(m);

    ll first = 0;
    ll second = 1;

    ll res = remainder;

    for (int i = 1; i < remainder; i++)
    {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge(n, m) << '\n';
}
