#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lchild, *rchild;
} *root = NULL;

void insert(int val)
{
    struct Node *tmp = root, *r = NULL, *q;

    if (root == NULL)
    {
        q = (struct Node *)malloc(sizeof(struct Node));
        q->data = val;
        q->lchild = q->rchild = NULL;
        root = q;
        return;
    }

    while (tmp != NULL)
    {
        r = tmp;
        if (val < tmp->data)
            tmp = tmp->lchild;

        else if (val > tmp->data)
            tmp = tmp->rchild;

        else
            return;
    }

    q = (struct Node *)malloc(sizeof(struct Node));
    q->data = val;
    q->lchild = q->rchild = NULL;

    if (val < r->data)
        r->lchild = q;
    else
        r->rchild = q;
}

struct Node *recursiveInsert(struct Node *p, int x)
{
    struct Node *tmp = NULL;

    if (p == NULL)
    {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->data = x;
        tmp->lchild = tmp->rchild = NULL;

        return tmp;
    }

    if (x < p->data)
        p->lchild = recursiveInsert(p->lchild, x);

    else if (x > p->data)
        p->rchild = recursiveInsert(p->rchild, x);

    return p;
}