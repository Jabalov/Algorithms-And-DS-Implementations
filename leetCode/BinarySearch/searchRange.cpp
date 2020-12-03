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
    int getIndex(vector<int> &nums, int target, bool getFirst)
    {
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                if (getFirst)
                    e = mid - 1;

                else
                    s = mid + 1;
            }
            else if (nums[mid] < target)
                s = mid + 1;

            else
                e = mid - 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> sol(2, -1);
        int first = getIndex(nums, target, true);

        if (first == -1)
            return sol;

        int last = getIndex(nums, target, false);

        sol[0] = first, sol[1] = last;
        return sol;
    }
};

int main()
{
    auto sol = Solution();
    vector<int> v = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> s = sol.searchRange(v, target);
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
}