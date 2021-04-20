#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;


int kp_recursion(int wt[], int profit[], int w, int n)
{
    if(n == 0 || w == 0)
        return 0;

    int result;
    if(wt[n] > w)
        return kp_recursion(wt, profit, w, n-1);
    else
        return max(kp_recursion(wt, profit, w-wt[n], n-1) + profit[n], kp_recursion(wt, profit, w, n-1));
}

int memo[100][100];
void set()
{
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            memo[i][j] = -1;
}

int kp_memo(int wt[], int profit[], int w, int n)
{
    if(n == 0 || w == 0)
        return 0;

    if(memo[w][n] != -1)
    {
        int result;
        if(wt[n] > w)
            result = kp_memo(wt, profit, w, n-1);
        else
            result = max(kp_memo(wt, profit, w-wt[n], n-1) + profit[n], kp_memo(wt, profit, w, n-1));

        memo[w][n] = result;
    }
    return memo[w][n];
}

int knapsack(int W, int wt[], int profit[], int n)
{
    int i, w;
    int dp[n + 1][W + 1];
 
    for(i = 0; i <= n; i++)
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (wt[i - 1] <= w)
                dp[i][w] = max(profit[i - 1] + dp[i - 1][w - wt[i - 1]],
                                dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    
    return dp[n][W];
}

int main()
{
    int wt[3] = {3, 2, 4};
    int profit[3] = {6, 8, 7};
    cout << knapsack(8, wt, profit, 3);
}