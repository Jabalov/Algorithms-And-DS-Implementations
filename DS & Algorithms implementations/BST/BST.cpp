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