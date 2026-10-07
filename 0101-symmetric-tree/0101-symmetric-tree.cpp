/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return func(root->left,root->right);
        


        
    }
    bool func(TreeNode*lefttree,TreeNode*righttree)
    {
        if(lefttree==NULL||righttree==NULL)
           return lefttree==righttree;
        return func(lefttree->left,righttree->right)&&func(lefttree->right,righttree->left)&&lefttree->val==righttree->val;
    }
};