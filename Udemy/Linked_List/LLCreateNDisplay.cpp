#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void Create(int A[], int n)
{
    struct Node *LL, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
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

void RDisplay(struct Node *p)
{
    if (p != NULL)
        RDisplay(p->next), printf("%d ", p->data);
}

int count(struct Node *p)
{
    int l = 0;
    while (p)
        l++, p = p->next;
    return l;
}

int Rcount(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return Rcount(p->next) + 1;
}

int sum(struct Node *p)
{
    int s = 0;
    while (p != NULL)
        s += p->data, p = p->next;
    return s;
}

int Rsum(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return Rsum(p->next) + p->data;
}

int Max(struct Node *p)
{
    int max = INT32_MIN;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int RMax(struct Node *p)
{
    int x = 0;

    if (p == 0)
        return INT32_MIN;
    x = RMax(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

struct Node *LS(struct Node *p, int x)
{
    struct Node *q;

    while (p->next != NULL)
    {
        if (p->data == x)
        {
            q->next = p->next;
            p->next = first->next;
            first = p;
            return p;
        }

        q = p;
        p = p->next;
    }
}

struct Node *RLS(struct Node *p, int x)
{
    if (p == NULL)
        return NULL;
    if (p->data == x)
        return p;
    return RLS(p->next, x);
}

int main()
{
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    Create(A, 8);

    Display(first);

    return 0;
}