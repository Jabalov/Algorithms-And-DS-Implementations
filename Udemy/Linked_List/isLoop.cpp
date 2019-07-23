#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void create(int A[], int n)
{
    int i;
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

int isLoop(struct Node *LL)
{
    struct Node *p, *q;
    p = q = LL;
    do
    {
        p = p->next;
        q = q->next;
        q = (q != NULL) ? q->next : q;

    } while (p && q && p != q);

    return p == q;
}

int main()
{
    struct Node *t1, *t2;

    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;

    printf("%d\n", isLoop(first));

    return 0;
}