#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Create(int A[], int n)
{
    struct Node *LL, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i <= n; i++)
    {
        LL = (struct Node *)malloc(sizeof(struct Node));
        LL->data = A[i];
        LL->next = NULL;

        last->next = LL;
        last = LL;
    }
}

void Display(struct Node *p)
{
    while (p->next != NULL)
        printf("%d ", p->data), p = p->next;
}

int mid(struct Node *p)
{
    struct Node *q;
    q = p;

    while (q)
    {
        q = q->next;
        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }
    return p->data;
}


int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    Create(A, 5);
    cout << mid(first);
}