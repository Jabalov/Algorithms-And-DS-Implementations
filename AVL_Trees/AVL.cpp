#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    struct Node *lchild, *rchild;
    int data, bf;
} *root = NULL;
