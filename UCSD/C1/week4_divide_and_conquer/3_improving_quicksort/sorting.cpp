#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>
#define vi vector<int>
using namespace std;

int partition2(vi &a, int l, int r)
{
  int pivot = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++)
    if (a[i] <= pivot)
      j++, swap(a[i], a[j]);

  swap(a[l], a[j]);

  return j;
}

int partitioning(vi &A, int lo, int hi)
{
  int pivot = A[lo];
  int i = lo, j = hi;
  do
  {
    do
    {
      i++;
    } while (pivot >= A[i]);

    do
    {
      j--;
    } while (pivot < A[j]);

    if (j > i)
      swap(A[i], A[j]);
  } while (j > i);

  swap(A[lo], A[j]);
  return j;
}

vi partition3(vi &a, int l, int r)
{
  int pivot = a[l];
  int j = l, k = r;

  for (int i = l + 1; i <= k; i++)
  {
    if (a[i] < pivot)
      swap(a[i], a[j]), j++;

    else if (a[i] > pivot)
      swap(a[i], a[k]), k--, i--;
  }

  return vi{j, k};
}

void randomized_quick_sort(vi &a, int l, int r)
{
  if (l >= r)
    return;

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vi m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main()
{
  int n;
  cin >> n;
  vi a(n);
  for (size_t i = 0; i < a.size(); ++i)
    cin >> a[i];

  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
    cout << a[i] << ' ';
}
