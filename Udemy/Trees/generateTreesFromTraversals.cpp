#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *lchild, *rchild;
};

int search(char arr[], int start, int end, char value)
{
    int i;
    for (i = start; i <= end; i++)
        if (arr[i] == value)
            return i;
}

Node *createNode(char data)
{
    Node *node = new Node();
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;

    return node;
}

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

void inO(Node *node)
{
    if (node == NULL)
        return;

    inO(node->lchild);
    cout << node->data << " ";
    inO(node->rchild);
}

int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);
    Node *root = build(in, pre, 0, len - 1);

    cout << "Inorder traversal of the tree:\n";
    inO(root);
}