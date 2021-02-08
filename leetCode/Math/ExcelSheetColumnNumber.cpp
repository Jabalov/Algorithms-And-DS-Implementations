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
    long int titleToNumber(string s)
    {
        int n = s.size();
        long int Ans = 0, power = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            Ans += (s[i] - 64) * power;
            power *= 26;
        }
        return Ans;
    }
};

int main()
{
    auto sol = Solution();
    string v = "ABCD";
    cout << sol.titleToNumber(v);
}