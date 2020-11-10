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
    int wordCount(string s)
    {
        int count = 0;

        for (int i = 0; i < s.size(); i++)
            count++;

        return count;
    }

    int lengthOfLastWord2(string s)
    {
        reverse(s.begin(), s.end());
        string Ans;

        int i = 0;
        for (; i < s.size();)
            if (s[i] == ' ')
                i++;
            else
                break;

        for (; i < s.size();)
            if (s[i] != ' ')
                Ans.push_back(s[i++]);
            else
                break;

        return wordCount(Ans);
    }

    int lengthOfLastWord(string s)
    {

        int n = s.size();
        int i = 0, cnt = 0;

        while (i < n)
        {
            if (s[i] != ' ') //Charcters
                cnt++, i++;

            else //Spaces
            {
                while (s[i] == ' ' && i < n)
                    i++;

                if (i == n)
                    return cnt;
                else
                    cnt = 0;
            }
        }
        return cnt;
    }
};

int main()
{
    auto solution = Solution();
    string s = "Hello World         ";
    cout << solution.lengthOfLastWord2(s);
}