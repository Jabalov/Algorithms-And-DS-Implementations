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
#define ll long long
using namespace std;

int lcs2(vi &a, vi &b)
{
  int m = a.size(), n = b.size();
  vii A(m + 1, vi(n + 1));

  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
        A[i][j] = 0;

      else if (a[i - 1] == b[j - 1])
        A[i][j] = A[i - 1][j - 1] + 1;

      else
        A[i][j] = max(A[i - 1][j], A[i][j - 1]);
    }

  return A[m][n];
}

int main()
{
  size_t n;
  cin >> n;
  vi a(n);
  for (size_t i = 0; i < n; i++)
    cin >> a[i];

  size_t m;
  cin >> m;
  vi b(m);
  for (size_t i = 0; i < m; i++)
    cin >> b[i];

  cout << lcs2(a, b) << endl;
}
