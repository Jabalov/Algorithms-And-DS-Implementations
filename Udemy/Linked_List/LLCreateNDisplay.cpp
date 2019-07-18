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

int main()
{
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    Create(A, 8);

    Display(first);

    return 0;
}