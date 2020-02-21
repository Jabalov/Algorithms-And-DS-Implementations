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

int optimal_weight_dp(int W, const vi &w)
{
  int n = w.size();
  vii knapsack(n + 1, vi(W + 1));

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= W; j++)
    {
      if (i == 0 || j == 0)
        knapsack[i][j] = 0;

      else if (w[i - 1] <= j)
        knapsack[i][j] = max(knapsack[i - 1][j - w[i - 1]] + w[i - 1], knapsack[i - 1][j]);

      else
        knapsack[i][j] = knapsack[i - 1][j];
    }

  return knapsack[n][W];
}

int main()
{
  int n, W;
  cin >> W >> n;
  vi w(n);
  for (int i = 0; i < n; i++)
    cin >> w[i];

  cout << optimal_weight_dp(W, w) << '\n';
}
