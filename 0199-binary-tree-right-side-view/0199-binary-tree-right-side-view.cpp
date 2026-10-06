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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>coordinates;
        vector<int>ans;
        dfs(root,0,coordinates);
        for(auto p:coordinates)
        {
            ans.push_back(p.second);
        }
        return ans;
        
    }
     void dfs(TreeNode*root,int level,map<int,int>&coordinates)
    {
        if(root==NULL)
        {
            return;
        }
        if(coordinates.find(level)==coordinates.end())
        {
           coordinates[level]=root->val;
        }
        dfs(root->right,level+1,coordinates);
        dfs(root->left,level+1,coordinates);
    }
};