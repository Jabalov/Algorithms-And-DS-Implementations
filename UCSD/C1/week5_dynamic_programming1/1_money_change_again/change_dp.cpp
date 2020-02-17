#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>

#define vi vector<int>
#define ll long long
using namespace std;

ll get_change(ll money)
{
  ll den[] = {1, 3, 4};
  vi min_number(money + 1, 10e3);
  min_number[0] = {0};

  for (ll i = 1; i <= money; i++)
    for (ll j = 0; j < 3; j++)
      if (i >= den[j])
      {
        ll is_min = min_number[i - den[j]] + 1;
        if (is_min < min_number[i])
          min_number[i] = is_min;
      }

  return min_number[money];
}

int main()
{
  ll m;
  cin >> m;
  cout << get_change(m) << '\n';
}
