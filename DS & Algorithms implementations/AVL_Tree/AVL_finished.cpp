#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <math.h>
#define pow2(n) (1 << (n))
using namespace std;

struct Node
{
    int data, bf;
    struct Node *left, *right;
} *root = NULL;

int height(struct Node *p)
{
    int l, r;
    l = r = 0;
    if (!p)
        return 0;
    l = height(p->left);
    r = height(p->right);

    return l > r ? l + 1 : r + 1;
}

void insert(int x)
{
    struct Node *t = root, *r = NULL, *p;

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(Node));
        p->data = x;
        p->bf = 0;
        p->left = p->right = NULL;
        root = p;
    }

    while (t != NULL)
    {
        r = t;
        if (t->data > x)
            t = t->left;
        else if (t->data < x)
            t = t->right;
        else
            return;
    }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;
    p->left = p->right = NULL;
    if (x < r->data)
        r->left = p;
    else
        r->right = p;
}

struct Node *LL(struct Node *p)
{
    int l, r;
    struct Node *pl = p->left;
    pl->bf = 0;

    p->left = pl->right;
    pl->right = p;

    l = height(p->left) + 1;
    r = height(p->right) + 1;

    p->bf = l - r;
    if (p == root)
        root = pl;
    return pl;
}

struct Node *RR(struct Node *p)
{
    int l, r;
    struct Node *pr = p->right;
    pr->bf = 0;

    p->right = pr->left;
    pr->left = p;

    l = height(p->left) + 1;
    r = height(p->right) + 1;
    p->bf = l - r;
    if (p == root)
        root = pr;
    return pr;
}

struct Node *LR(struct Node *p)
{
    int l, r;
    struct Node *pl = p->left;
    struct Node *plr = pl->right;
    plr->bf = 0;

    p->left = plr->right;
    pl->right = plr->left;
    plr->left = pl;
    plr->right = p;

    l = height(p->left) + 1;
    r = height(p->right) + 1;
    p->bf = l - r;

    l = height(pl->left) + 1;
    r = height(pl->right) + 1;
    pl->bf = l - r;

    if (p == root)
        root = plr;
    return plr;
}

struct Node *RL(struct Node *p)
{
    int l, r;
    struct Node *pr = p->right;
    struct Node *prl = pr->left;
    prl->bf = 0;

    p->right = prl->left;
    pr->left = prl->right;
    prl->right = pr;
    prl->left = p;

    l = height(p->left) + 1;
    r = height(p->right) + 1;
    p->bf = l - r;

    l = height(pr->left) + 1;
    r = height(pr->right) + 1;
    pr->bf = l - r;

    if (p == root)
        root = prl;
    return prl;
}

struct Node *recursive_insert(struct Node *p, int x)
{
    struct Node *t;
    int l, r;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->bf = 0;
        t->left = t->right = NULL;
        return t;
    }

    if (x < p->data)
        p->left = recursive_insert(p->left, x);
    else if (x > p->data)
        p->right = recursive_insert(p->right, x);

    l = height(p->left) + 1;
    r = height(p->right) + 1;
    p->bf = l - r;

    if (p->bf == 2 && p->left->bf == 1)
        return LL(p);
    if (p->bf == 2 && p->left->bf == -1)
        return LR(p);
    if (p->bf == -2 && p->right->bf == -1)
        return RR(p);
    if (p->bf == -2 && p->right->bf == 1)
        return RL(p);
    return p;
}

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

int main()
{
    struct Node *temp;
    insert(30);
    recursive_insert(root, 50);
    recursive_insert(root, 40);
    recursive_insert(root, 20);
    recursive_insert(root, 10);
    recursive_insert(root, 42);
    recursive_insert(root, 46);

    inorder(root);
    printf("\n");
}