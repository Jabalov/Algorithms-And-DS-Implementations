#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int return_maxIndex(int A[][MAX], int rows, int mid, int &maxi)
{
    int idx = 0;
    for (int i = 0; i < rows; i++)
        if (maxi < A[i][mid])
        {
            maxi = A[i][mid];
            idx = i;
        }
    return idx;
}

int recursion_peakFind(int A[][MAX], int rows, int columns, int mid)
{
    int max = 0;
    int maxIndex = return_maxIndex(A, rows, mid, max);

    //Base Cases
    if (mid == 0 || mid == columns - 1)
        return max;
    if (max >= A[maxIndex][mid - 1] && max >= A[maxIndex][mid + 1])
        return max;

    //dividing the task
    if (max < A[maxIndex][mid - 1])
        return recursion_peakFind(A, rows, columns, mid - mid / 2);

    else
        return recursion_peakFind(A, rows, columns, mid + mid / 2);
}

int solve_peakFind2D(int A[][MAX], int rows, int columns)
{
    return recursion_peakFind(A, rows, columns, columns / 2);
}

int main()
{
    int A[][MAX] = {{10, 8, 10, 10},
                    {14, 13, 12, 11},
                    {15, 9, 11, 21},
                    {16, 17, 19, 20}};

    cout << solve_peakFind2D(A, 4, 4);
}
