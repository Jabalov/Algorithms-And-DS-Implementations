#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int countSubset(int a[], int n, int sum)
{
    if (sum == 0)
        return 1;
    
    if(n == 0 && sum != 0)
        return 0;

    return countSubset(a, n - 1, sum) + countSubset(a, n - 1, sum - a[n - 1]);
}

int countSubset_dp(int a[], int n, int sum)
{
    int subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = 1;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = 0;

    for (int i = 1; i <= n; i++)
        for (int s = 1; s <= sum; s++)
        {
            if (s < a[i - 1])
                subset[i][s] = subset[i - 1][s];
            
            if (s >= a[i - 1])
                subset[i][s] = subset[i - 1][s] + subset[i - 1][s - a[i - 1]];
        }

    return subset[n][sum];

}

int main() 
{ 
    int set[] = {3, 1, 2, 3}; 
    int sum = 6; 
    int n = sizeof(set)/sizeof(set[0]);

    cout <<  (countSubset_dp(set, n, sum));
} 