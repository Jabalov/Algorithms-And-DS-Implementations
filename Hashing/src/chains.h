#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void sorted_insert(Node **p, int x)
{
    Node *tmp;
    Node *q = NULL;
    Node *it = *p;

    tmp = (Node *)malloc(sizeof(Node *));
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

Node *search(Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return p;

        p = p->next;
    }
    return NULL;
}
