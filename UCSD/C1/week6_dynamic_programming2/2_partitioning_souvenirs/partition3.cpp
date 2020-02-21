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

int partition3(vi &A)
{
  int s = 0;

  int n = A.size();

  for (int i = 0; i < n; i++)
    s += A[i];

  if (s == 0 || s % 3 != 0)
    return 0;

  vii partition(s / 3 + 1, vi(n + 1));

  for (int i = 1; i <= s / 3; i++)
    for (int j = 1; j <= n; j++)
    {
      int diff = i - A[j - 1];

      if ((A[j - 1] == i) || (diff > 0 && partition[diff][j - 1] > 0))
        partition[i][j] = (partition[i][j - 1] == 0) ? 1 : 2;

      else
        partition[i][j] = partition[i][j - 1];
    }

  if (partition[s / 3][n] == 2)
    return 1;
  else
    return 0;
}

int main()
{
  int n;
  cin >> n;
  vi A(n);
  for (size_t i = 0; i < A.size(); ++i)
    cin >> A[i];

  cout << partition3(A) << '\n';
}
