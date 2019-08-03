#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Stack
{
    int size, top;
    struct Node **s;
};

void stackCreate(struct Stack *s, int x)
{
    s->size = x;
    s->top = -1;
    s->s = (struct Node **)malloc(s->size * sizeof(struct Node *));
}

void push(struct Stack *s, struct Node *x)
{
    if (s->top == s->size - 1)
        printf("Stack overflow\n");
    else
        s->top++, s->s[s->top] = x;
}

struct Node *pop(struct Stack *s)
{
    struct Node *x = NULL;
    if (s->top == -1)
        printf("Stack Underflow\n");
    else
        x = s->s[s->top--];

    return x;
}

int isEmptyStack(struct Stack s)
{
    return (s.top == -1);
}

int isFullStack(struct Stack s)
{
    return s.top == s.size - 1;
}
