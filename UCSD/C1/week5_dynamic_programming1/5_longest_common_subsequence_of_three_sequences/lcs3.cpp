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

int lcs3(vi &a, vi &b, vi &c)
{
  int m = a.size();
  int n = b.size();
  int z = c.size();

  viii A(m + 1, vii(n + 1, vi(z + 1)));

  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= z; k++)
        if (i == 0 || j == 0 || k == 0)
        {
          A[i][j][k] = 0;
          continue;
        }

        else if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
        {
          A[i][j][k] = A[i - 1][j - 1][k - 1] + 1;
          continue;
        }
        else
        {
          A[i][j][k] = max(max(A[i - 1][j][k], A[i][j - 1][k]), A[i][j][k - 1]);
        }

  return A[m][n][z];
}

int main()
{
  size_t an;
  cin >> an;
  vi a(an);
  for (size_t i = 0; i < an; i++)
    cin >> a[i];

  size_t bn;
  cin >> bn;
  vi b(bn);
  for (size_t i = 0; i < bn; i++)
    cin >> b[i];

  size_t cn;
  cin >> cn;
  vi c(cn);
  for (size_t i = 0; i < cn; i++)
    cin >> c[i];

  cout << lcs3(a, b, c) << endl;
}
