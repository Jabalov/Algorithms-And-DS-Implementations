#include <bits/stdc++.h>
using namespace std;

class Matrix
{
private:
    size_t rows, columns;
    vector<int> matrix;

public:
    Matrix(size_t numrows, size_t numcols) : rows(numrows), columns(numcols), matrix(rows * columns){};
    int &operator()(size_t row, size_t column)
    {
        return matrix[row * columns + column];
    }

    int operator()(size_t row, size_t column) const
    {
        return matrix[row * columns + column];
    }
};

int maxi(vector<int> col)
{
    int max = col[0];
    int idx = 0;
    for (int i = 0; i < col.size(); i++)
        if (max <= col[i])
        {
            max = col[i];
            idx = i;
        }

    return idx;
}

int find_a_peak(Matrix matrix, int n, int m)
{

    if (m <= 2)
        return matrix(0, 0);

    int mid = (m / 2);
    int start, end;
    vector<int> col(n);
    for (int i = 0; i < n; i++)
        col[i] = matrix(i, mid);

    int max = maxi(col);

    if (matrix(max, mid - 1) < matrix(max, mid) > matrix(max, mid + 1))
    {
        return matrix(max, mid);
    }

    if (matrix(max, mid - 1) >= matrix(max, mid))
    {
        start = 0;
        end = mid;
    }

    if (matrix(max, mid + 1) >= matrix(max, mid))
    {
        start = mid;
        end = m;
    }

    Matrix submatrix(3, mid);
    for (int i = 0; i < 3; i++)
    {
        for (int j = start; j < end; j++)
        {
            submatrix(i, j) = matrix(i, j);
        }
    }

    return find_a_peak(submatrix, n, mid);
}

int main()
{
    int n = 3, m = 9;
    int tmp[27] = {1, 2, 2, 4, 2, 6, 7, 8, 9,
                   1, 2, 3, 5, 3, 1, 7, 8, 9,
                   1, 2, 1, 4, 1, 6, 7, 8, 9};

    Matrix matrix(3, 9);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            matrix(i, j) = tmp[i * 9 + j];
        }
    }

    cout << find_a_peak(matrix, n, m) << "\n";
}