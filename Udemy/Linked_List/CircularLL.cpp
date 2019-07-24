#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * Head;

void create(int A[], int n)
{
    int i;
    struct Node *tmp, *last;

    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++)
    {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->data = A[i];
        tmp->next = last->next;

        last->next = tmp;
        last = tmp;
    }
}

void Display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != Head);
    printf("\n");
}

void RDisplay(struct Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
}

int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;

    } while (p != Head);
    return len;
}

void Insert(struct Node *p, int idx, int x)
{
    struct Node *t;

    int i = 0;

    if (idx < 0 || idx > Length(p))
        return;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (idx == 0)
    {
        if (Head == NULL)
            Head = t,
            Head->next = Head;

        else
        {
            while (p->next != Head)
                p = p->next;

            p->next = t;
            t->next = Head;
            Head = t;
        }
    }

    else
    {
        for (; i < idx - 1; i++)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int i, x;

    if (index < 0 || index > Length(Head))
        return -1;

    if (index == 1)
    {
        while (p->next != Head)
            p = p->next;
        x = Head->data;
        if (Head == p)
        {
            free(Head);
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    Delete(Head, 1);

    RDisplay(Head);
    return 0;
}