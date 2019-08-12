#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    struct Node *lchild, *rchild;
    int data, bf;
} *root = NULL;

int height(struct Node *p)
{
    int x = 0, y = 0;
    if (!p)
        return 0;

    x = height(p->lchild);
    y = height(p->rchild);

    return x > y ? x + 1 : y + 1;
}

void Insert(int key)
{
    struct Node *t = root;
    struct Node *r = NULL, *p;

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->bf = 0;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}