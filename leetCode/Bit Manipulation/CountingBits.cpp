#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>

using namespace std;

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> cnt_;
        for (int i = 0; i <= num; i++)
        {
            int cnt = 0;
            int n = i;

            while (n)
            {
                cnt++;
                n &= (n - 1);
            }
            cnt_.push_back(cnt);
        }
        return cnt_;
    }
};

int main(int argc, const char **argv)
{

    return 0;
}
