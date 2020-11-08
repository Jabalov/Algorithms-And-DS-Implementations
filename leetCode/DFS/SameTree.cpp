#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <assert.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if ((p == nullptr && q != nullptr) || (p != NULL && q == NULL))
            return false;

        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

int main()
{
    struct TreeNode n1 = TreeNode(1);
    n1.left = new TreeNode(2);
    n1.right = new TreeNode(3);

    struct TreeNode n2 = TreeNode(1);
    n2.left = new TreeNode(2);
    n2.right = new TreeNode(3);

    auto solution = Solution();

    bool f = solution.isSameTree(&n1, &n2);

    assert(f == true);
    return 0;
}