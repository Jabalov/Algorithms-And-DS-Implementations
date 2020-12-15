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
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1;

        while(start <= end)
        {
            int mid = (start + end) >> 1, 
            next = (mid + 1) % n, 
            prev = (mid - 1 + n) % n;

            if(nums[mid] <= nums[next] && nums[mid] <= nums[prev])
                return nums[mid];

            else if(nums[mid] <= nums[end])
                end = mid - 1;

            else if(nums[mid] >= nums[start])
                start = mid + 1;
        }

        return -1;
    }
};

int main()
{
    auto sol = Solution();
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    int s = sol.findMin(v);
    cout << s << " ";
}