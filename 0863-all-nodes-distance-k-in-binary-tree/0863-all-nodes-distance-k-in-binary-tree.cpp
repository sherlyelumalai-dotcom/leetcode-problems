/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left!=NULL)
                {
                  parent[temp->left]=temp;
                  q.push(temp->left);
                }
                if(temp->right!=NULL) 
                {
                   parent[temp->right]=temp;
                   q.push(temp->right);
                }
                
                
            }
        }
        q.push(target);
        map<TreeNode*,bool>visited;
        visited[target]=true;
        
        int count=1;
        while(!q.empty())
        {
            int n=q.size();
            
            if(count>k)
            {
                break;
            }
            for(int i=0;i<n;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                if(parent[temp]&&!visited[parent[temp]])
                {
                  visited[parent[temp]]=true;
                  q.push(parent[temp]);
                }
                if(temp->left!=NULL&&!visited[temp->left])
                {
                  visited[temp->left]=true;
                  q.push(temp->left);
                }
                if(temp->right!=NULL&&!visited[temp->right])
                {
                  visited[temp->right]=true;
                  q.push(temp->right);
                }
            }
            count++;
        }
        vector<int>ans;
        while(!q.empty())
        {

            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

        
    }
   
};