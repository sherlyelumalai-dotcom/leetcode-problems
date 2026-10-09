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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        int n = inorder.size();

        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return build(inorder, 0, n-1, postorder, 0, n-1, mp);
    }

    TreeNode* build(vector<int>& inorder, int instart, int inend,
                    vector<int>& postorder, int poststart, int postend,
                    map<int,int>& mp) {

        if(poststart > postend || instart > inend) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postend]);

        int inroot = mp[root->val];
        int numleft = inroot - instart;

        root->left = build(inorder, instart, inroot-1,
                           postorder, poststart,
                           poststart+numleft-1, mp);

        root->right = build(inorder, inroot+1, inend,
                            postorder, poststart+numleft,
                            postend-1, mp);

        return root;
    }
};