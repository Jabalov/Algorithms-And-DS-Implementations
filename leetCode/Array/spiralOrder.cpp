#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool check_equality(int a, int b) { return a == b; }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int m = matrix.size();
        if(m == 0)
            return answer;

        int n = matrix[0].size();
        if(n == 0)
            return answer;

        int start_row = 0, end_row = m - 1;
        int start_col = 0, end_col = n - 1;
        int cnt = 0;
        
        while (start_row <= end_row && start_col <= end_col)
        {
            for (int i = start_col; i <= end_col; i++)
                answer.push_back(matrix[start_row][i]), cnt++;

            start_row++;
            if(cnt == n * m)
                return answer;

            for (int i = start_row; i <= end_row; i++)
                answer.push_back(matrix[i][end_col]), cnt++;

            end_col--;
            if(cnt == n * m)
                return answer;

            for (int i = end_col; i >= start_col; i--)
                answer.push_back(matrix[end_row][i]), cnt++;

            end_row--;
            if(cnt == n * m)
                return answer;

            for (int i = end_row; i >= start_row; i--)
                answer.push_back(matrix[i][start_col]), cnt++;

            start_col++;
            if(cnt == n * m)
                return answer;
        }

        return answer;
    }
};