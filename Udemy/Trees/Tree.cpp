#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
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

int main()
{
    treeCreate();
    preO(root);
    printf("\nPost Order ");
    postO(root);

    return 0;
}