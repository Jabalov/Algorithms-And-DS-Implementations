#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *Top = NULL;

void Push(int x)
{
    struct Node *tmp;
    tmp = (struct Node *)malloc(sizeof(struct Node));

    if (tmp == NULL)
        printf("Stack is full\n");
    else
        tmp->data = x,
        tmp->next = Top,
        Top = tmp;
}

int Pop()
{
    struct Node *tmp;
    int x = -1;

    if (Top == NULL)
        printf("Stack is EMPTY\n");
    else
        tmp = Top,
        Top = Top->next,
        x = tmp->data,
        free(tmp);

    return x;
}

void Display()
{
    struct Node *p;
    p = Top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Push(10);
    Push(20);
    Push(30);

    Display();

    printf("%d ", Pop());

    return 0;
}