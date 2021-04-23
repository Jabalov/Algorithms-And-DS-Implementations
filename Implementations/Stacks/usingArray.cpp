#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size, top, *s;
};

void create(struct Stack *s)
{
    printf("Enter Size of The Stack:\n");
    scanf("%d", &s->size);

    s->top = -1;
    s->s = (int *)malloc(s->size * sizeof(int));
}

void display(struct Stack s)
{
    int i = s.top;
    for (; i >= 0; i--)
        printf("%d ", s.s[i]);
    printf("\n");
}

void push(struct Stack *s, int x)
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

int main()
{
    struct Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    printf("%d \n", peek(st, 2));

    display(st);
    return 0;
}