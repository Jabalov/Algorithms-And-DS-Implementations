#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>

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
  return 0;
}

int main()
{
  string s;
  cin >> s;
  cout << get_maximum_value(s) << '\n';
}
