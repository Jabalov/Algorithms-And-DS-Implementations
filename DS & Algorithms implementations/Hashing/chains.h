#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void sorted_insert(struct Node **p, int x)
{
    struct Node *tmp, *q = NULL, *it = *p;

    tmp = (struct Node *)malloc(sizeof(struct Node *));
    tmp->data = x;
    tmp->next = NULL;

    if (*p == NULL)
        *p = tmp;

    else
    {
        while (it && it->data < x)
            q = it, it = it->next;

        if (it == *p)
            tmp->next = *p, *p = tmp;

        else
            tmp->next = q->next, q->next = tmp;
    }
}

struct Node *search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return p;

        p = p->next;
    }
    return NULL;
}
