#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void insert(struct Node **p, int x)
{
    if (!p[x])
    {
        p[x] = new Node;
        p[x]->data = x;
        p[x]->next = NULL;
    }
    else
    {
        struct Node *q, *temp;
        q = p[x];

        while (q->next != NULL)
            q = q->next;

        temp = new Node;
        temp->data = x;
        temp->next = NULL;

        q->next = temp;
    }
}

int del(struct Node **p, int i)
{
    int x;
    struct Node *temp;

    temp = p[i];
    x = p[i]->data;
    p[i] = p[i]->next;
    delete temp;

    return x;
}

int find_max(int A[], int n)
{
    int m;
    m = A[0];
    for (int i = 1; i < n; i++)
        if (m < A[i])
            m = A[i];

    return m;
}

void bin_sort(int A[], int n)
{
    struct Node **bins;
    int i, j = 0, x;
    x = find_max(A, n) + 1;

    bins = new Node *[x];

    for (i = 0; i < x; i++)
        bins[i] = NULL;

    for (i = 0; i < n; i++)
        insert(bins, A[i]);

    for (i = 0; i < x; i++)
        while (bins[i] != NULL)
        {
            A[j] = del(bins, i);
            ++j;
        }
}

int main()

{

    int A[] = {6, 8, 3, 10, 15, 6, 9, 12, 6, 3}, n = 10;

    bin_sort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}