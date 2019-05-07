#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaxPairwiseProduct(const vector<int> &numbers)
{
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first)
        for (int second = first + 1; second < n; ++second)
            max_product = max(max_product, numbers[first] * numbers[second]);

    return max_product;
}

long long n;
int main()
{
    cin >> n;
    long long A[n];

    for (int i = 0; i < n; ++i)
        cin >> A[i];
    sort(A, A + n);

    long long s = A[n - 1] * A[n - 2] > A[0] * A[1] ? A[n - 1] * A[n - 2] : A[0] * A[1];
    cout << s;

    return 0;
}
