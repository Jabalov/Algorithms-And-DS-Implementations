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
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix[0].size(), m = matrix.size();

        for (int row = 0; row < m; row++)
            for (int col = row; col < n; col++)
                swap(matrix[row][col], matrix[col][row]);

        for (int row = 0; row < m; row++)
        {
            int start = 0, end = n - 1;
            
            while(start <= end)
                swap(matrix[row][start++], matrix[row][end--]);
            
        }
    }
};

int main()
{

}