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

int optimal_weight(int W, const vi &w)
{
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i)
  {
    if (current_weight + w[i] <= W)
    {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int main()
{
  int n, W;
  cin >> W >> n;
  vi w(n);
  for (int i = 0; i < n; i++)
    cin >> w[i];

  cout << optimal_weight(W, w) << '\n';
}
