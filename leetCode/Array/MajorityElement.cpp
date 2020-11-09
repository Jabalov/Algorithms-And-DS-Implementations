#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int element = nums[0];
        int counter = 1;
        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            if (element == nums[i])
                counter++;
            else
            {
                counter--;
                if (counter == 0)
                    element = nums[i], counter = 1;
            }
        }
        return element;
    }
};

int main()
{
    auto sol = Solution();
    vector<int> v{2, 2, 1, 1, 1, 2, 2};
    cout << sol.majorityElement(v);
}