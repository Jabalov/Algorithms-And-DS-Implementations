#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));

    if (tmp == NULL)
        printf("Queue is Full");

    else
    {
        tmp->data = x;
        tmp->next = NULL;

        if (front == NULL)
            front = rear = tmp;

        else
            rear->next = tmp, rear = tmp;
    }
}

void Display()
{
    struct Node *p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int dequeue()
{
    int x = -1;
    struct Node *tmp;

    if (front == NULL)
        printf("Queue is Empty\n");

    else
    {
        x = front->data;
        tmp = front;
        front = front->next;
        free(tmp);
    }
    return x;
}