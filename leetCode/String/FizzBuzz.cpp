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
    vector<string> fizzBuzz(int n)
    {

        vector<string> Ans;

        for (int i = 1; i <= n; i++)
        {
            if ((i % 5 == 0) && (i % 3 == 0))
                Ans.push_back("FizzBuzz");

            else if (i % 3 == 0)
                Ans.push_back("Fizz");

            else if (i % 5 == 0)
                Ans.push_back("Buzz");

            else
                Ans.push_back(to_string(i));
        }

        return Ans;
    }
};

int main()
{
    auto sol = Solution();
    vector<string> s = sol.fizzBuzz(15);

    for (auto str : s)
        cout << str << " ";
    return 0;
}