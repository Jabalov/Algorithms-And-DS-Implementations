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
    string longestCommonPrefix(vector<string> &strs)
    {
        string Ans = "";
        string current = *min_element(strs.begin(), strs.end());

        for (int i = 0; i < current.size(); i++)
        {
            for (int j = 0; j < strs.size(); j++)
                if (current[i] != strs[j][i])
                    return Ans;

            Ans.push_back(current[i]);
        }

        return Ans;
    }
};

int main()
{
    vector<string> v = {"flower", "flow", "flight"};
    auto sol = Solution();
    string s = sol.longestCommonPrefix(v);

    for (auto str : s)
        cout << str;

    // for (auto str : s)
    //     cout << str << " ";
    return 0;
}