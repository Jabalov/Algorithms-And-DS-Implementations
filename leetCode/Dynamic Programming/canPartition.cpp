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
    vector<vector<int>> memo;
    bool isSubsetSum(vector<int>& nums, int n, int pos, int sum)
    {
        if(sum == 0)
            return true;
        else if(pos >= n || sum < 0)
            return false;
        
        if(memo[pos][sum] != -1)
            return memo[pos][sum];

        return memo[pos][sum] = isSubsetSum(nums, n, pos + 1, sum - nums[pos]) || isSubsetSum(nums, n, pos + 1, sum);
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        
        if(sum & 1)
            return false;

        memo.clear();
        memo.resize(n + 1, vector<int>(sum / 2 + 1, -1));
        return isSubsetSum(nums, n, 0, sum/2);
    }
};