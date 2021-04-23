#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <string.h>
#include <assert.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n + 1][amount + 1];

        for (int i = 0; i <= n;++i)
        {
            for (int a = 0; a <= amount; ++a)
            {
                if(a == 0)
                    dp[i][a] = 0;
                else if(i == 0)
                    dp[i][a] = 1e5;

                else if(coins[i - 1] > a)
                    dp[i][a] = dp[i - 1][a];
                else
                    dp[i][a] = min(1 + dp[i][a - coins[i - 1]], dp[i - 1][a]);
            }
        }
        return dp[n][amount] > 1e4 ? -1 : dp[n][amount];
    }
};