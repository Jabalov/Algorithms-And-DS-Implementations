#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <queue>
#define pow2(n) (1 << (n))
using namespace std;

enum col
{
    red,
    black
};

class Node
{
public:
    int val;
    col col;
    Node *left, *right, *parent;

    Node(int val)
    {
        this->val = val;
        parent = left = right = NULL;
        col = red;
    }

    Node *uncle()
    {
        if (parent == NULL || parent->parent == NULL)
            return NULL;

        if (parent->inLeft())
            return parent->parent->right;
        else
            return parent->parent->left;
    }

    bool inLeft()
    {
        return this == parent->left;
    }

    Node *sibling()
    {
        if (parent == NULL)
            return NULL;
        if (inLeft())
            return parent->right;

        return parent->left;
    }

    void moveDown(Node *nParent)
    {
        if (parent != NULL)
        {
            if (inLeft())
                parent->left = nParent;
            else
                parent->right = nParent;
        }
        nParent->parent = parent;
        parent = nParent;
    }

    bool hasredChild()
    {
        return (left != NULL && left->col == red) || (right != NULL && right->col == red);
    }
};

class RBTree
{
    Node *root;
    void leftRotate(Node *x)
    {
        Node *nParent = x->right;

        if (x == root)
            root = nParent;

        x->moveDown(nParent);

        x->right = nParent->left;
        if (nParent->left != NULL)
            nParent->left->parent = x;

        nParent->left = x;
    }

    void rightRotate(Node *x)
    {
        Node *nParent = x->left;

        if (x == root)
            root = nParent;

        x->moveDown(nParent);

        x->left = nParent->right;

        if (nParent->right != NULL)
            nParent->right->parent = x;

        nParent->right = x;
    }

    void swapcols(Node *x1, Node *x2)
    {
        col temp;
        temp = x1->col;
        x1->col = x2->col;
        x2->col = temp;
    }

    void swapValues(Node *u, Node *v)
    {
        int temp;
        temp = u->val;
        u->val = v->val;
        v->val = temp;
    }

    void fixredred(Node *x)
    {
        if (x == root)
        {
            x->col = black;
            return;
        }

        Node *parent = x->parent, *grandparent = parent->parent,
             *uncle = x->uncle();

        if (parent->col != black)
        {
            if (uncle != NULL && uncle->col == red)
            {
                parent->col = black;
                uncle->col = black;
                grandparent->col = red;
                fixredred(grandparent);
            }
            else
            {
                if (parent->inLeft())
                {
                    if (x->inLeft())
                    {
                        swapcols(parent, grandparent);
                    }
                    else
                    {
                        leftRotate(parent);
                        swapcols(x, grandparent);
                    }
                    rightRotate(grandparent);
                }
                else
                {
                    if (x->inLeft())
                    {
                        rightRotate(parent);
                        swapcols(x, grandparent);
                    }
                    else
                    {
                        swapcols(parent, grandparent);
                    }

                    leftRotate(grandparent);
                }
            }
        }
    }

    Node *successor(Node *x)
    {
        Node *temp = x;

        while (temp->left != NULL)
            temp = temp->left;

        return temp;
    }

    Node *BSTreplace(Node *x)
    {
        if (x->left != NULL && x->right != NULL)
            return successor(x->right);

        if (x->left == NULL && x->right == NULL)
            return NULL;

        if (x->left != NULL)
            return x->left;
        else
            return x->right;
    }

    void deleteNode(Node *v)
    {
        Node *u = BSTreplace(v);

        bool uvblack = ((u == NULL || u->col == black) && (v->col == black));
        Node *parent = v->parent;

        if (u == NULL)
        {
            if (v == root)
            {
                root = NULL;
            }
            else
            {
                if (uvblack)
                {

                    fixDoubleblack(v);
                }
                else
                {
                    if (v->sibling() != NULL)
                        v->sibling()->col = red;
                }

                if (v->inLeft())
                {
                    parent->left = NULL;
                }
                else
                {
                    parent->right = NULL;
                }
            }
            delete v;
            return;
        }

        if (v->left == NULL || v->right == NULL)
        {
            if (v == root)
            {
                v->val = u->val;
                v->left = v->right = NULL;
                delete u;
            }
            else
            {
                if (v->inLeft())
                {
                    parent->left = u;
                }
                else
                {
                    parent->right = u;
                }
                delete v;
                u->parent = parent;
                if (uvblack)
                {
                    fixDoubleblack(u);
                }
                else
                {
                    u->col = black;
                }
            }
            return;
        }

        swapValues(u, v);
        deleteNode(u);
    }

    void fixDoubleblack(Node *x)
    {
        if (x == root)
            return;

        Node *sibling = x->sibling(), *parent = x->parent;
        if (sibling == NULL)
        {
            fixDoubleblack(parent);
        }
        else
        {
            if (sibling->col == red)
            {
                parent->col = red;
                sibling->col = black;
                if (sibling->inLeft())
                {
                    rightRotate(parent);
                }
                else
                {
                    leftRotate(parent);
                }
                fixDoubleblack(x);
            }
            else
            {
                if (sibling->hasredChild())
                {
                    if (sibling->left != NULL && sibling->left->col == red)
                    {
                        if (sibling->inLeft())
                        {
                            sibling->left->col = sibling->col;
                            sibling->col = parent->col;
                            rightRotate(parent);
                        }
                        else
                        {
                            sibling->left->col = parent->col;
                            rightRotate(sibling);
                            leftRotate(parent);
                        }
                    }
                    else
                    {
                        if (sibling->inLeft())
                        {
                            sibling->right->col = parent->col;
                            leftRotate(sibling);
                            rightRotate(parent);
                        }
                        else
                        {
                            sibling->right->col = sibling->col;
                            sibling->col = parent->col;
                            leftRotate(parent);
                        }
                    }
                    parent->col = black;
                }
                else
                {
                    sibling->col = red;
                    if (parent->col == black)
                        fixDoubleblack(parent);
                    else
                        parent->col = black;
                }
            }
        }
    }

    void levelOrder(Node *x)
    {
        if (x == NULL)
            return;

        queue<Node *> q;
        Node *curr;

        q.push(x);

        while (!q.empty())
        {
            curr = q.front();
            q.pop();

            cout << curr->val << " ";

            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }

    void inorder(Node *x)
    {
        if (x == NULL)
            return;
        inorder(x->left);
        cout << x->val << " ";
        inorder(x->right);
    }

public:
    RBTree() { root = NULL; }

    Node *getRoot() { return root; }

    Node *search(int n)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (n < temp->val)
            {
                if (temp->left == NULL)
                    break;
                else
                    temp = temp->left;
            }
            else if (n == temp->val)
            {
                break;
            }
            else
            {
                if (temp->right == NULL)
                    break;
                else
                    temp = temp->right;
            }
        }

        return temp;
    }

    void insert(int n)
    {
        Node *newNode = new Node(n);
        if (root == NULL)
        {
            newNode->col = black;
            root = newNode;
        }
        else
        {
            Node *temp = search(n);

            if (temp->val == n)
            {
                return;
            }

            newNode->parent = temp;

            if (n < temp->val)
                temp->left = newNode;
            else
                temp->right = newNode;

            fixredred(newNode);
        }
    }

    void deleteByVal(int n)
    {
        if (root == NULL)
            return;

        Node *v = search(n), *u;

        if (v->val != n)
        {
            cout << "No node found to delete with value:" << n << endl;
            return;
        }

        deleteNode(v);
    }

    void printInOrder()
    {
        cout << "Inorder: " << endl;
        if (root == NULL)
            cout << "Tree is empty" << endl;
        else
            inorder(root);
        cout << endl;
    }

    void printLevelOrder()
    {
        cout << "Level order: " << endl;
        if (root == NULL)
            cout << "Tree is empty" << endl;
        else
            levelOrder(root);
        cout << endl;
    }
};

int main()
{
    RBTree tree;

    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    tree.insert(2);
    tree.insert(6);
    tree.insert(13);

    tree.printInOrder();
    tree.printLevelOrder();

    cout << endl
         << "Deleting 18, 11, 3, 10, 22" << endl;

    tree.deleteByVal(18);
    tree.deleteByVal(11);
    tree.deleteByVal(3);
    tree.deleteByVal(10);
    tree.deleteByVal(22);

    tree.printInOrder();
    tree.printLevelOrder();
    return 0;
}
