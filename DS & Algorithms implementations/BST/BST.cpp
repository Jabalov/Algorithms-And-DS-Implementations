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

int Height(struct Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;

    x = Height(p->lchild);
    y = Height(p->rchild);

    return x > y ? x + 1 : y + 1;
}

void inO(struct Node *p)
{
    if (p)
    {
        inO(p->lchild);
        printf("%d ", p->data);
        inO(p->rchild);
    }
}

struct Node *search(int x)
{
    struct Node *tmp = root;

    while (tmp != NULL)
    {
        if (x == tmp->data)
            return tmp;

        else if (x > tmp->data)
            tmp = tmp->rchild;

        else
            tmp = tmp->lchild;
    }
    return NULL;
}

struct Node *inPredecessor(struct Node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;

    return p;
}

struct Node *inSuccessor(struct Node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;

    return p;
}

struct Node *del(struct Node *p, int x)
{
    if (p == NULL)
        return NULL;

    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (x < p->data)
        p->lchild = del(p->lchild, x);
    else if (x > p->data)
        p->rchild = del(p->rchild, x);
    else
    {
        struct Node *q;
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = inPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = del(p->lchild, q->data);
        }

        else
        {
            q = inSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = del(p->rchild, q->data);
        }
    }
    return p;
}
