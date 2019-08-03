#include <stdio.h>
#include <stdlib.h>

class Node
{
private:
    int data;
    struct Node *lchild, *rchild;
};

class Queue
{
private:
    int size, front, rear;
    struct Node **Q;

public:
    Queue(int size);
    void enqueue(Node *x);
    Node *dequeue();
    bool isEmpty();
};

Queue::Queue(int size)
{
    this->size = size;
    this->front = this->rear = 0;
    this->Q = (struct Node **)malloc(this->size * sizeof(struct Node *));
}

void Queue::enqueue(Node *x)
{
    if ((rear + 1) % size == front)
        printf("Queue is Full");
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    struct Node *x = NULL;

    if (front == rear)
        printf("Queue is Empty\n");
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

bool Queue::isEmpty()
{
    return front == rear;
}