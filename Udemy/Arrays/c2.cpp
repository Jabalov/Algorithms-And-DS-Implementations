#include <iostream>
using namespace std;

int main()
{
    int A[] = {1, 2, 2, 2, 3, 5, 6, 6, 7, 8, 8, 8, 9, 10};
    int dup = 0;

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
        if (A[i] == A[i + 1] && A[i] != dup)
            cout << A[i] << " ",
                dup = A[i];
}
