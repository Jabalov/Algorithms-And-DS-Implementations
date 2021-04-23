#include <iostream>
using namespace std;

int main()
{
    int A[11] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 19, 21};
    int n = sizeof(A) / sizeof(A[0]), lo = A[0], dif = lo - 0;

    /* int x = 0;
    for (int i = 0; i < n; i++)
        while (dif < A[i] - i)
        {
            cout << " " << dif + i;
            dif++;
        }
    */
    int H[50] = {0};
    for (int i = 0; i < n; i++)
        H[A[i]]++;

    for (int i = A[0]; i <= A[n - 1]; i++)
        if (H[i] == 0)
            cout << i << " ";
}