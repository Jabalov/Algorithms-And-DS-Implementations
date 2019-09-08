#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int find_max(int A[], int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}

int no_of_digit(int n)
{
    int count = 0;
    while (n)
    {
        n /= 10;
        count++;
    }
    return count;
}
void insert(struct Node **p, int x, int j)
{
    int pos = (x / j) % 10;
    if (p[pos] == NULL)
    {
        p[pos] = new Node;
        p[pos]->data = x;
        p[pos]->next = NULL;
    }
    else
    {
        struct Node *temp, *q;
        q = p[pos];
        while (q->next)
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
    x = temp->data;
    p[i] = p[i]->next;
    delete temp;
    return x;
}

void set_it_null(struct Node **p)
{
    for (int i = 0; i < 10; i++)
        p[i] = NULL;
}

void radix_sort(int A[], int n)
{
    int i, pass, k, j = 1, m = 0;
    pass = no_of_digit(find_max(A, n));

    struct Node **radix;
    radix = new Node *[10];
    set_it_null(radix);
    for (i = 0; i < pass; i++)
    {
        for (k = 0; k < n; k++)
            insert(radix, A[k], j);

        k = 0, m = 0;
        while (m < n)
        {
            while (radix[m])
                A[k++] = del(radix, m);
            ++m;
        }
        j *= 10;
        set_it_null(radix);
    }
}

int main()
{
    int A[] = {238, 149, 36, 49, 312, 412, 510, 159, 187};
    int n = 9;
    radix_sort(A, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}