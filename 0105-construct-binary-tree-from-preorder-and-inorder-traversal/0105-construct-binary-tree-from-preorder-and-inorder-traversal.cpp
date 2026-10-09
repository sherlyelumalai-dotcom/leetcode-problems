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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int>mp;
        long long n=inorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode* root=build(preorder,inorder,0,0,n-1,n-1,mp);
        return root;
        
    }
    TreeNode*build(vector<int>&preorder,vector<int>&inorder,int prestart,int instart,int preend,int inend,map<int,int>&mp)
    {
        if(prestart>preend||instart>inend)
        {
           return NULL;
        }
         long long inroot=mp[preorder[prestart]];
        long long numleft=inroot-instart;
        TreeNode*root=new TreeNode(preorder[prestart]);
        root->left=build(preorder,inorder,prestart+1,instart,prestart+numleft,inroot-1,mp);
        root->right=build(preorder,inorder,prestart+numleft+1,inroot+1,preend,inend,mp);
        return root;

    }
};