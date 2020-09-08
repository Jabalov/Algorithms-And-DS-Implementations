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
        int first = 0, second = 0;

        for (int &num : nums)
        {
            int first_ = (~num & first) | (num & ~first & ~second);
            int second_ = (~num & second) | (num & first);

            first = first_, second = second_;
        }

        return first;
    }
};

int main(int argc, const char **argv)
{

    return 0;
}