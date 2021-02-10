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
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int colnum = matrix[0].size();

        if(row == 0)
            return;

        if(colnum == 0)
            return;

        bool hasZeroFirstRow = false;
        bool hasZeroFirstCol = false;
        
        for (int j = 0; j < colnum; j++)
            if(matrix[0][j] == 0)
            {
                hasZeroFirstRow = true;
                break;
            }
        
        for (int j = 0; j < row; j++)
            if(matrix[j][0] == 0)
            {
                hasZeroFirstCol = true;
                break;
            }

        for (int i = 1; i < row; i++)
            for (int j = 1; j < colnum; j++)
                if(matrix[i][j] == 0)
                    matrix[i][0] = 0,
                    matrix[0][j] = 0;
        
        for (int i = 1; i < row; i++)
            for (int j = 1; j < colnum; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        
        if(hasZeroFirstRow)
            for (int i = 0; i < colnum; i++)
                matrix[0][i] = 0;

        if(hasZeroFirstCol)
            for (int i = 0; i < row; i++)
                matrix[i][0] = 0;
    }
};

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    auto sol = Solution();
    sol.setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}
