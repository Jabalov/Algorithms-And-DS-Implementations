#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <climits>
#include <cstring>

#define vi vector<int>
#define vii vector<vector<int>>
#define viii vector<vector<vector<int>>>
#define ll long long
using namespace std;

ll eval(ll a, ll b, char op)
{
  if (op == '*')
  {
    return a * b;
  }
  else if (op == '+')
  {
    return a + b;
  }
  else if (op == '-')
  {
    return a - b;
  }
  else
  {
    assert(0);
  }
}

ll get_maximum_value(const string &exp)
{
  int len = exp.size();
  int num = (len + 1) / 2;

  long long mini[num][num];
  long long maxi[num][num];

  memset(mini, 0, sizeof(mini));
  memset(maxi, 0, sizeof(maxi));
  for (int i = 0; i < num; i++)
  {

    mini[i][i] = stoll(exp.substr(2 * i, 1));
    maxi[i][i] = stoll(exp.substr(2 * i, 1));
  }

  for (int s = 0; s < num - 1; s++)
    for (int i = 0; i < num - s - 1; i++)
    {
      int j = i + s + 1;
      long long miniValue = LLONG_MAX;
      long long maxiValue = LLONG_MIN;

      for (int k = i; k < j; k++)
      {
        long long a = eval(mini[i][k], mini[k + 1][j], exp[2 * k + 1]);
        long long b = eval(mini[i][k], maxi[k + 1][j], exp[2 * k + 1]);
        long long c = eval(maxi[i][k], mini[k + 1][j], exp[2 * k + 1]);
        long long d = eval(maxi[i][k], maxi[k + 1][j], exp[2 * k + 1]);

        miniValue = min(miniValue, min(a, min(b, min(c, d))));
        maxiValue = max(maxiValue, max(a, max(b, max(c, d))));
      }
      mini[i][j] = miniValue;
      maxi[i][j] = maxiValue;
    }

  return maxi[0][num - 1];
  return 0;
}

int main()
{
  string s;
  cin >> s;
  cout << get_maximum_value(s) << '\n';
}
