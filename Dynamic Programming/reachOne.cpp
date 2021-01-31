#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
int helper(int target, int *answer){
    if(target <= 1)
        return 0;
    
    if(answer[target] != -1)
        return answer[target];

    int x = helper(target - 1, answer);
    int y, z;
    y = z = INT_MAX;

    if(target % 2 == 0)
        y = helper(target / 2, answer);

    if(target % 3 == 0)
        z = helper(target / 3, answer);

    int output = min(x, min(y, z)) + 1;
    answer[target] = output;

    return output;
}
    int reachNumber(int target) {
        int *answer = new int[target + 1];
        for (int i = 0; i <= target; i++)
            answer[i] = -1;

        return helper(target, answer);
    }

    int reachNumber2(int target)
    {
        int *dp = new int[target + 1];
        dp[0] = dp[1] = 0;

        for (int i = 2; i <= target; i++)
        {
            dp[i] = dp[i - 1] + 1;

            if(i % 2 == 0)
                dp[i] = min(dp[i], dp[i / 2] + 1);
            
            if(i % 3 == 0)
                dp[i] = min(dp[i], dp[i / 3] + 1);
        }

        int ans = dp[target];
        delete []dp;
        return ans;
    }
};

int main(){
    int n;
    auto sol = Solution();
    cin >> n;
    cout << sol.reachNumber2(n) << endl;
    return 0;
}