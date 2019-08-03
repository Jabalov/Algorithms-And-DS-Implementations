#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct Node *root = NULL;

void treeCreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("Enter The root value:\n");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);

        printf("enter the left child of: %d\n ", p->data);
        scanf("%d", &x);

        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("enter the right child of: %d\n ", p->data);
        scanf("%d", &x);

        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preO(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preO(p->lchild);
        preO(p->rchild);
    }
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

void postO(struct Node *p)
{
    if (p)
    {
        postO(p->lchild);
        postO(p->rchild);
        printf("%d ", p->data);
    }
}

void IpreO(struct Node *p)
{
    struct Stack stk;
    stackCreate(&stk, 100);

    while (p || !isEmptyStack(stk))
        if (p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
}

void IinO(struct Node *p)
{
    struct Stack stk;
    stackCreate(&stk, 100);

    while (p || !isEmptyStack(stk))
        if (p)
            push(&stk, p), p = p->lchild;

        else
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
}

void levelOrder(struct Node *p)
{
    struct Queue q;
    create(&q, 100);

    printf("%d \n", root->data);
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);

        if (p->lchild)
            printf("%d ", p->lchild->data), enqueue(&q, p->lchild);

        if (p->rchild)
            printf("%d ", p->rchild->data), enqueue(&q, p->rchild);
    }
}

int count(struct Node *root)
{
    if (root)
        return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}

int height(struct Node *p)
{
    int x, y;
    x = y = 0;

    if (p == NULL)
        return 0;

    x = height(p->lchild);
    y = height(p->rchild);

    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int main()
{
    treeCreate();
    levelOrder(root);
}