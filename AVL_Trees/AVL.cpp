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
