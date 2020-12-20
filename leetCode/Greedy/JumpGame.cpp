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
    bool canJump(vector<int>& nums) {
        int good_position = nums.size() - 1;

        for(int i = nums.size() - 2; i >= 0; i--)
            if(nums[i] + i >= good_position)
                good_position = i;

        return good_position == 0;
    }
};


int main()
{
    vector<int> s = {3,2,1,0,4};
    int numRows = 3;

    auto sol = Solution();
    cout << sol.canJump(s);
}