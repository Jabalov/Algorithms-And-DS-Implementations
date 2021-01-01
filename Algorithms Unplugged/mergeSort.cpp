#include <iostream>
using namespace std;

void merge(int A[], int lo, int mid, int hi)
{
    int i = lo, j = mid + 1, k = lo;
    int B[100];

    while (i <= mid && j <= hi)
        B[k++] = A[i] < A[j] ? A[i++] : A[j++];

    for (; i <= mid; i++)
        B[k++] = A[i];

    for (; j <= hi; j++)
        B[k++] = A[j];

    for (i = lo; i <= hi; i++)
        A[i] = B[i];
}


void merge_sort(int A[], int al, int ar)
{
    int mid;
    if (al < ar)
    {
        mid = (al + ar) >> 1;
        merge_sort(A, al, mid);
        merge_sort(A, mid + 1, ar);
        merge(A, al, mid, ar);
    }

}

int main()
{
    int a[] = {1, 6, 7, 8, 11, 3, 8, 15, 10, 16, 13, 8};
    int n = 12;
    merge_sort(a, 0, n);

    for (auto &element : a)
        cout << element << " ";
}