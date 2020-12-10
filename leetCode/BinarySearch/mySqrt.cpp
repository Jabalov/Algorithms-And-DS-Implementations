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
    int mySqrt(int x) 
    {
        int start = 1, end = x;
        int ans;
        if (x == 0)
          return 0;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(mid == x / mid)
                return mid;
          
            else if(mid < x / mid)
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};

int main()
{
    auto sol = Solution();
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    int s = sol.mySqrt(10);
    cout << s << " ";
}