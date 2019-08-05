#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *lchild, *rchild;
};

int search(char *arr, int strt, int end, char value);
Node *createNode(char data);

Node *build(char *in, char *pre, int in_start, int in_end)
{
    static int pre_index = 0;

    if (in_start > in_end)
        return NULL;

    Node *tmp = createNode(pre[pre_index++]);

    if (in_start == in_end)
        return tmp;

    int in_index = search(in, in_start, in_end, tmp->data);

    tmp->lchild = build(in, pre, in_start, in_index - 1);
    tmp->rchild = build(in, pre, in_index + 1, in_end);

    return tmp;
}
