#include <iostream>
using namespace std;

int main()
{
    int A[] = {1, 2, 2, 2, 3, 5, 6, 6, 7, 8, 8, 8, 9, 10};
    int dup = 0;

    /*for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
        if (A[i] == A[i + 1])
        {
            int j = i + 1;
            while (A[j] == A[i])
                j++;
            printf("%d is found %d times \n", A[i], j - i);
            i = j - 1;
        } 
        */
    int H[50] = {0};
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
        H[A[i]]++;

    for (int i = A[0]; i <= A[sizeof(A) / sizeof(A[0]) - 1]; i++)
        if (H[i] > 1)
            cout << i << " is found " << H[i] << " times \n";
}
