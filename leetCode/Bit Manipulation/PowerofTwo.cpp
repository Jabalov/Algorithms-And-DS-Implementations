#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;

        int cnt = 0;

        while (n)
            cnt++, n &= (n - 1);

        return cnt == 1;
    }
};

class Solution2
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;

        return (n & (n - 1)) == 0  ;
    }
};