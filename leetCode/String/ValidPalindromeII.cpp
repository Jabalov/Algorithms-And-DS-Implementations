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
    bool IsPalindrome(string s, int st, int en)
    {
        while (st <= en)
        {
            if (s[st] != s[en])
                return false;

            st++, en--;
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int st = 0;
        int en = s.size() - 1;

        while (st <= en)
        {
            if (s[st] != s[en])
            {
                if (IsPalindrome(s, st + 1, en) || IsPalindrome(s, st, en - 1))
                    return true;
                else
                    return false;
            }
            st++, en--;
        }

        return true;
    }
};

int main()
{
    auto s = Solution();
    string ss = "abcca";

    string sol = s.validPalindrome(ss) ? "True" : "False";
    cout << sol;
}
