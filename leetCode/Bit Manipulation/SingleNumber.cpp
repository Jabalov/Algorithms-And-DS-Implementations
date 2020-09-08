#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        return accumulate(nums.cbegin(), nums.cend(), 0, bit_xor<int>());
    }
};

int main()
{

    Solution s;
    vector<int> inp = {2, 1, 2};

    int x = s.singleNumber(inp);
    cout << x;
}