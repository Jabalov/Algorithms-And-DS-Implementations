#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define ll long long

void heapify_down(vector<pair<int, ll>> &w_, int i)
{

  int idx = i;
  int l = 2 * i + 1, r = 2 * i + 2;

  if (l < w_.size() && w_[l].second < w_[idx].second)
    idx = l;

  if (r < w_.size() && w_[r].second < w_[idx].second)
    idx = r;

  if (l < w_.size() && w_[l].second == w_[idx].second)
    if (w_[l].first < w_[idx].first)
      idx = l;

  if (r < w_.size() && w_[r].second == w_[idx].second)
    if (w_[r].first < w_[idx].first)
      idx = r;

  if (i != idx)
  {
    swap(w_[i], w_[idx]);
    heapify_down(w_, idx);
  }
}

int main()
{

  int n, m;
  cin >> n >> m;
  vector<pair<int, long long>> w_(n);

  for (int i = 0; i < n; i++)
    w_[i].first = i, w_[i].second = 0;

  vector<int> t_(m);
  for (int i = 0; i < m; i++)
    cin >> t_[i];

  for (int i = 0; i < m; i++)
  {
    cout << w_[0].first << " " << w_[0].second << endl;

    w_[0].second += (long long)t_[i];
    heapify_down(w_, 0);
  }

  return 0;
}