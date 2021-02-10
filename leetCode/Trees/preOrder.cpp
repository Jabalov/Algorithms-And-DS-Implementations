#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void preorder(TreeNode *root,vector<int> &ans){
        if(root==NULL) return;
        
        ans.push_back(root->val);
        preorder(root->left,ans); 
        preorder(root->right,ans);  
    } 
        
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        
        return ans;
    }
};