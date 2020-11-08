#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void reverse(string &s, int begin, int end)
    {
        while (begin <= end)
            swap(s[begin], s[end]), begin++, end--;
    }

    string reverseWords(string s)
    {
        int start = 0, i = 0;

        while (i < s.size())
        {
            if (s[i] == ' ')
            {
                reverse(s, start, i - 1);
                i++, start = i;
            }
            else
                i++;
        }

        reverse(s, start, i - 1);
        reverse(s, 0, s.size() - 1);

        string no_spaces;
        int j = 0;
        while (s[j] == ' ')
            j++;
        while (j < s.size())
        {
            if (s[j] == ' ')
            {
                no_spaces.push_back(' ');
                j++;
                while (s[j] == ' ')
                    j++;
            }
            else
                no_spaces.push_back(s[j++]);
        }

        if (no_spaces.back() == ' ')
            no_spaces.pop_back();

        return no_spaces;
    }
};

int main()
{
    string s = "  hello world  ";

    auto solution = Solution();
    cout << solution.reverseWords(s);
    return 0;
}