#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> _stack;

        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int x1 = _stack.top();
                _stack.pop();

                int x2 = _stack.top();
                _stack.pop();

                if (tokens[i] == "+")
                    _stack.push(x2 + x1);

                else if (tokens[i] == "-")
                    _stack.push(x2 - x1);

                else if (tokens[i] == "*")
                    _stack.push(x2 * x1);

                else if (tokens[i] == "/")
                    _stack.push(x2 / x1);
            }

            else
            {
                _stack.push(atoi(tokens[i].c_str()));
            }
        }

        return _stack.top();
    }
};

int main()
{
    vector<string> postfix = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    auto sol = Solution();
    cout << sol.evalRPN(postfix);
}