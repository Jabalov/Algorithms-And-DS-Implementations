#include <bits/stdc++.h>
using namespace std;

int peak_1D(vector<int> A)
{
    int l = A.size();
    int mid = l / 2;
    if (l == 0)
        throw logic_error("invalid input");
    if (l == 2)
        return A[1];

    if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
        return A[mid];

    else if (A[mid] <= A[mid - 1])
    {
        vector<int> slice(A.begin(), A.begin() + mid);
        return peak_1D(slice);
    }

    else if (A[mid] <= A[mid + 1])
    {
        vector<int> slice(A.begin() + mid, A.end());
        return peak_1D(slice);
    }
}

int main()
{
    vector<int> array = {1, 2, 3, 5, 4, 6, 7, 8, 9};
    cout << "the peak is " << peak_1D(array) << "\n";
}