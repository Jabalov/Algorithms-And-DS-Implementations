#include <iostream>
using namespace std;

#define ll long long

ll get_change(ll m)
{
  ll change[] = {10, 5, 1};
  ll cnt = 0, idx = 0;

  while (m != 0)
    if ((ll)m / change[idx])
      m -= change[idx], cnt++;
    else
      (idx++) % 3;

  return cnt;
}

int main()
{
  ll m;
  cin >> m;
  cout << get_change(m) << '\n';
}
