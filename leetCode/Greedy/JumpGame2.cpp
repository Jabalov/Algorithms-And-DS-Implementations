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
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) 
            return 0;

        if(nums[0] == 0) 
            return -1;

        int biggestLadder = nums[0];
        int current = nums[0];
        int jumps = 1;

        for (int i = 1; i < n; i++)
        {
            if(i == n - 1)
                return jumps;

            if(i + nums[i] > biggestLadder)
                biggestLadder = nums[i] + i;

            current--;

            if(current == 0)
            {
                jumps++;
                if(i >= biggestLadder)
                    return -1;

                current = biggestLadder - i;
            }
        }

        return -1;
    }
};


int main()
{
    vector<int> s = {2,3,1,1,4};
    int numRows = 3;

    auto sol = Solution();
    cout << sol.jump(s);
}