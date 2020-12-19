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
    string convert(string s, int numRows) {
        
        if(numRows <= 1)
            return s;

        string *ans = new string[numRows];
        int row = 0, step = 1;

        for (int i = 0; i < s.size(); i++)
        {
            ans[row].push_back(s[i]);

            if(row == 0)
                step = 1;
            else if(row == numRows - 1)
                step = -1;

            row += step;
        }

        string Ans = "";
        for (int i = 0; i < numRows; i++)
            Ans += ans[i];

        return Ans;
    }
};

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;

    auto sol = Solution();
    cout << sol.convert(s, 3);
}