#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lchild, *rchild;
};

struct Stack
{
    int size, top;
    struct Node **s;
};

void create(struct Stack *s, int x)
{
    s->size = x;

    s->top = -1;
    s->s = (struct Node **)malloc(s->size * sizeof(struct Node *));
}

void display(struct Stack s)
{
    int i = s.top;
    for (; i >= 0; i--)
        printf("%d ", s.s[i]);
    printf("\n");
}

void push(struct Stack *s, struct Node *x)
{
    if (s->top == s->size - 1)
        printf("Stack overflow\n");
    else
        s->top++, s->s[s->top] = x;
}

int pop(struct Stack *s)
{
    int x = -1;
    if (s->top == -1)
        printf("Stack Underflow\n");
    else
        x = s->s[s->top--];

    return x;
}

int peek(struct Stack s, int index)
{
    int x = -1;
    if (s.top - index + 1 < 0)
        printf("Invalid Index \n");
    x = s.s[s.top - index + 1];
    return x;
}

int isEmpty(struct Stack s)
{
    return (s.top == -1);
}

int isFull(struct Stack s)
{
    return s.top == s.size - 1;
}

int stackTop(struct Stack s)
{
    if (!isEmpty(s))
        return s.s[s.top];
    return -1;
}