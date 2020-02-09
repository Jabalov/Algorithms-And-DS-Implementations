#include <iostream>
#include <cassert>
#include <vector>

#define vi vector<int>
using namespace std;

int binary_search(const vi &a, int x)
{
  int left = 0, right = (int)a.size() - 1, mid;
  while (left < right)
  {
    mid = (left + right) >> 1;

    if (a[mid] == x)
      return mid;

    else if (x < a[mid])
      right = mid - 1;

    else
      left = mid + 1;
  }

  return -1;
}

int linear_search(const vi &a, int x)
{
  for (size_t i = 0; i < a.size(); ++i)
    if (a[i] == x)
      return i;

  return -1;
}

int main()
{
  int n;
  cin >> n;
  vi a(n);
  for (size_t i = 0; i < a.size(); i++)
    cin >> a[i];

  int m;
  cin >> m;
  vi b(m);
  for (int i = 0; i < m; ++i)
    cin >> b[i];

  for (int i = 0; i < m; ++i)
    cout << binary_search(a, b[i]) << ' ';
}
