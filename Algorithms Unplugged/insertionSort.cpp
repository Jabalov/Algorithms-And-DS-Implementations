#include <iostream>
using namespace std;

void insertion_sort(int A[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int current = A[i];
        j = i - 1;

        while(j >= 0 && A[j] > current)
            A[j + 1] = A[j], j--;

        A[j + 1] = current;
    }
}

int main()
{
    int a[] = {1, 6, 7, 8, 11, 3, 8, 15, 10, 16, 13, 8};
    int n = 12;
    insertion_sort(a, n);

    for (auto &element : a)
        cout << element << " ";
}