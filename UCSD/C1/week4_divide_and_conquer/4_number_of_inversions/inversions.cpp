#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>

#define vi vector<int>
#define ll long long
using namespace std;

ll merge(vi &a, vi &b, int left, int mid, int right)
{
  int i, j, k;
  int cnt = 0;

  i = left;
  j = mid;
  k = left;

  while ((i <= mid - 1) && (j <= right))
  {
    if (a[i] <= a[j])
      b[k++] = a[i++];

    else
      b[k++] = a[j++], cnt += (mid - i);
  }

  while (i <= mid - 1)
    b[k++] = a[i++];

  while (j <= right)
    b[k++] = a[j++];

  for (i = left; i <= right; i++)
    a[i] = b[i];

  return cnt;
}

ll get_number_of_inversions(vi &a, vi &b, size_t left, size_t right)
{
  ll num = 0;
  if (right <= left + 1)
    return num;

  size_t ave = left + (right - left) / 2;
  num += get_number_of_inversions(a, b, left, ave);
  num += get_number_of_inversions(a, b, ave + 1, right);
  num += merge(a, b, left, ave + 1, right);

  return num;
}

int main()
{
  int n;
  cin >> n;
  vi a(n);
  for (size_t i = 0; i < a.size(); i++)
    cin >> a[i];

  vi b(a.size());
  cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
