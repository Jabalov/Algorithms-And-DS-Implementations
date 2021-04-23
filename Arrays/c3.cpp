#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int A[10] = {1, 4, 7, 9, 6, 3, 8, 2, 9, 11};

    int H[50] = {0};
    for (int i = 1; i <= 11; i++)
    {
        if (H[abs(k - A[i])])
            printf("%d + %d = %d \n", A[i], k - A[i], k);

        H[A[i]]++;
    }
}