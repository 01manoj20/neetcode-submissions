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

    int ans = 0;

    int goodNodes(TreeNode* root) {
        dfs(root,-1e9);
        return ans;
    }

    void dfs(TreeNode* root, int maxt)
    {
        if(root == nullptr)
            return;
        
        if(root->val >= maxt)
            ans++;

        dfs(root->left,max(maxt,root->val));
        dfs(root->right,max(maxt,root->val));
    }
};
