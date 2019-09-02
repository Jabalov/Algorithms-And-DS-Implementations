#include <iostream>
using namespace std;


struct Node {
    int k1, k2;
    Node *left, *right, *mid;
    int n;
};

struct usefulData
{
    int midVal;             
    Node * child;

    usefulData()
    {
        child = NULL;
    }

    //Overloaded Constructor 1
    usefulData (Node* c)
    {
        child = c;
    }

    //Overloaded Constructor 2
    usefulData (Node* c, int m)
    {
        child    = c;
        midVal = m;
    }


    //Overloaded Assignment Operator
    usefulData operator = (usefulData & otherusefulData)
    {
        if (&otherusefulData != this)
        {
            child    = otherusefulData.child;
            midVal = otherusefulData.midVal;
        }

        return *this;
    }

    //Copy Constructor
    usefulData(usefulData & otherusefulData)
    {
        child = otherusefulData.child;
        midVal = otherusefulData.midVal;
    }
};

//----------------------------------------------------------------

class Tree 
{
private:
    Node *root;

public:
    Tree()
    {
        root = NULL;
    }

    ~Tree()
    {
        if(root != NULL) 
            destroy(root);
    }

    void destroy(Node *r)
    {
        if(r != NULL)
        {
            destroy (r->left);
            destroy (r->mid);
            destroy (r->right);
            delete r;
        }
    }


};