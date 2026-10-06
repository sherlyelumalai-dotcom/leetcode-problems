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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>coordinates;
        dfs(root,0,0,coordinates);
        vector<vector<int>>ans;
        for(auto p:coordinates)
        {
            vector<int>col;
            for(auto q:p.second)
            {
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;

    

        
    }
    void dfs(TreeNode*root,int col, int row,map<int,map<int,multiset<int>>>&coordinates)
    {
        if(root==NULL)
        {
            return;
        }
        coordinates[col][row].insert(root->val);
        dfs(root->left,col-1,row+1,coordinates);
        dfs(root->right,col+1,row+1,coordinates);


    }
};