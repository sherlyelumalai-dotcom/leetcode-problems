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
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
          return 0;
        int maxsum=root->val;
        findmaxsum(root,maxsum);
        return maxsum;
    
        
    }
    int findmaxsum(TreeNode*root,int&maxsum)
    {
        if(root==NULL)
          return 0;
        int leftsum=max(0,findmaxsum(root->left,maxsum));
        int rightsum=max(0,findmaxsum(root->right,maxsum));
        maxsum=max(maxsum,root->val+leftsum+rightsum);
        return root->val+max(leftsum,rightsum);  
    }
};