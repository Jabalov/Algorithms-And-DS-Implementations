#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <string.h>
#include <assert.h>

using namespace std;

class Solution
{ 
    
public:
    int search(vector<int> &nums, int target)
    {
        int s = 0, e = nums.size() - 1;

        while (s <= e)
        {
            int mid = (s + e) >> 1;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] <= nums[e])
            {
                if (target >= nums[mid] && target <= nums[e])
                    s = mid + 1;
                else
                    e = mid - 1;
            }

            else if (nums[mid] >= nums[s])
            {
                if (target <= nums[mid] && target >= nums[s])
                    e = mid - 1;
                else
                    s = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    auto sol = Solution();
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int s = sol.search(v, target);
    cout << s << " ";
}