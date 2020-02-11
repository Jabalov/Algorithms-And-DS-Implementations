#include <iostream>
#include <cassert>
#include <vector>
#include <map>

#define vi vector<int>
using namespace std;

int get_majority_element_rcs(vi &a, int left, int right)
{
  if (left == right)
    return -1;
  if (left + 1 == right)
    return a[left];

  int mid = (left + right) >> 1;
  int left_side = get_majority_element_rcs(a, 0, mid);
  int right_side = get_majority_element_rcs(a, mid + 1, right);

  int lcnt(0);
  for (int i = left; i < right; i++)
    if (a[i] == left_side)
      lcnt++;

  if (lcnt > (right - left) >> 1)
    return left_side;

  int rcnt(0);
  for (int i = left; i < right; i++)
    if (a[i] == right_side)
      rcnt++;

  if (rcnt > (right - left) >> 1)
    return right_side;

  return -1;
}

int get_majority_element_itr(vi &a, int left, int right)
{
  if (left == right)
    return -1;
  if (left + 1 == right)
    return a[left];

  map<int, int> cnt;

  for (int i = 0; i < a.size(); i++)
    cnt[a[i]]++;

  for (int i = 0; i < a.size(); i++)
    if (cnt[a[i]] > (a.size() >> 1))
      return 1;

  return -1;
}

int main()
{
  int n;
  cin >> n;
  vi a(n);

  for (size_t i = 0; i < a.size(); ++i)
    cin >> a[i];

  cout << (get_majority_element_rcs(a, 0, a.size()) != -1) << '\n';
}
