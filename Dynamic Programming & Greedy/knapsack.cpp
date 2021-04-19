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
            result = kp_recursion(wt, profit, w, n-1);
        else
            result = max(kp_recursion(wt, profit, w-wt[n], n-1) + profit[n], kp_recursion(wt, profit, w, n-1));

        memo[w][n] = result;
    }
    return memo[w][n];
}

int main()
{
    int wt[3] = {3, 2, 4};
    int profit[3] = {6, 8, 7};
    cout << kp_memo(wt, profit, 8, 3);
}