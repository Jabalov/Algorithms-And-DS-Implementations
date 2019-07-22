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

void Insert(struct Node *p, int idx, int x)
{
    if (idx < 0 || idx > count(p))
        return;

    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->data = x;
    int i;

    if (idx == 0)
        tmp->next = first, first = tmp;

    else
    {
        for (i = 0; i < idx - 1; i++)
            p = p->next;

        tmp->next = p->next;
        p->next = tmp;
    }
}

void InsertBack(int x)
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node)), *last;
    tmp->data = x;
    tmp->next = NULL;

    if (first == NULL)
        first = last = tmp;
    else
        last->next = tmp, last = tmp;
}

void InsertSorted(struct Node *p, int x)
{
    struct Node *tmp = (struct Node *)malloc((sizeof(struct Node))), *q = NULL;
    tmp->data = x;
    tmp->next = NULL;

    if (first == NULL)
        first = tmp;

    else
    {
        while (p && p->data < x)
            q = p,
            p = p->next;

        if (p == first)
            tmp->next = first,
            first = tmp;

        else
            tmp->next = q->next,
            q->next = tmp;
    }
}

int Delete(struct Node *p, int idx)
{
    struct Node *q = NULL;
    int x = -1, i = 0;

    if (idx < 1 || idx > count(p))
        return -1;

    if (idx == 1)
    {
        p = first;
        x = first->data;
        first = first->next;
        free(p);
        return x;
    }
    else
    {
        for (i; i < idx - 1 && p; i++)
            q = p,
            p = p->next;

        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int isSorted(struct Node *p)
{
    int x = -60000;

    while (p != NULL)
    {
        if (p->data < x)
            return 0;

        x = p->data;
        p = p->next;
    }
    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
            p = q,
            q = q->next;

        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}
int main()
{

    int A[] = {10, 20, 20, 40, 50, 50, 50, 60};
    Create(A, 8);

    RemoveDuplicate(first);
    Display(first);

    return 0;
}