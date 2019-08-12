#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root = NULL;
