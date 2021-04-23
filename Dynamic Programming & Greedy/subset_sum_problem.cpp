#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

bool isSubsetSum(int a[], int n, int sum)
{
    if (sum == 0)
        return true;
    
    if(n == 0 && sum != 0)
        return false;

    return isSubsetSum(a, n - 1, sum) || isSubsetSum(a, n - 1, sum - a[n - 1]);
}

bool isSubsetSum_dp(int a[], int n, int sum)
{
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (int i = 1; i <= n; i++)
        for (int s = 1; s <= sum; s++)
        {
            if (s < a[i - 1])
                subset[i][s] = subset[i - 1][s];
            
            if (s >= a[i - 1])
                subset[i][s] = subset[i - 1][s] || subset[i - 1][s - a[i - 1]];
        }

    return subset[n][sum];

}

int main() 
{ 
    int set[] = {3, 34, 4, 12, 5, 2}; 
    int sum = 9; 
    int n = sizeof(set)/sizeof(set[0]);

    if (isSubsetSum_dp(set, n, sum) == true) 
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
} 