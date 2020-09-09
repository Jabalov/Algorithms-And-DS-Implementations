#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>

using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {

        vector<int> solution;
        int n = arr.size();
        int cumulative[n];

        cumulative[0] = arr[0];

        // Pre-Processing, in order to Answer each query in O(1).  cumulative Array is a prefix Array.
        for (int i = 1; i < n; i++)
            cumulative[i] = cumulative[i - 1] ^ arr[i];

        for (int i = 0; i < queries.size(); i++)
        {
            int start = queries[i][0], stop = queries[i][1];

            if (start == 0)
                solution.push_back(cumulative[stop]);
            else
                solution.push_back(cumulative[start - 1] ^ cumulative[stop]);
        }

        return solution;
    }
};