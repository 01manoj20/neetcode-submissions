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

    int sum_dist(TreeNode* node)
    {
        if(node == nullptr)
            return 0;

        int l_ans = sum_dist(node->left);
        int r_ans = sum_dist(node->right);

        if(ans<l_ans+r_ans)
            ans=l_ans+r_ans;

        return 1+max(l_ans,r_ans)   ;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int temp = sum_dist(root);
        return ans;
    }
};
