#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;
using std::vector;
#define vi vector<int>
#define ll long long

ll max_dot_product(vi a, vi b)
{
  // write your code here
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll result = 0;
  for (size_t i = 0; i < a.size(); i++)
    result += ((ll)a[i]) * (ll)b[i];

  return result;
}

int main()
{
  size_t n;
  cin >> n;
  vi a(n), b(n);
  for (size_t i = 0; i < n; i++)
    cin >> a[i];

  for (size_t i = 0; i < n; i++)
    cin >> b[i];

  cout << max_dot_product(a, b) << endl;
}
