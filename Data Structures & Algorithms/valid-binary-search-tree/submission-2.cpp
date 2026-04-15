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
    bool final_ans = true;

    bool isValidBST(TreeNode* root) {
        dfs(root);
        return final_ans;
    }

    pair<int,int> dfs(TreeNode* root)
    {
        
        if((!root->left) && (!root->right))
            return {root->val,root->val};

        pair<int,int> ans = {root->val,root->val};

        if(root->left!=nullptr){
            auto temp1 = dfs(root->left);

            if(temp1.second>=root->val)
                final_ans = false;

            cout<<root->val<<" 1 "<<temp1.first<<" "<<temp1.second<<endl;

            ans.first = min(ans.first,temp1.first);
            ans.second = max(ans.second,temp1.second);

        }

        if(root->right != nullptr){
            auto temp2 = dfs(root->right);

            if(temp2.first<=root->val)
                final_ans = false;

            cout<<root->val<<" 2 "<<temp2.first<<" "<<temp2.second<<endl;

            ans.first = min(ans.first,temp2.first);
            ans.second = max(ans.second,temp2.second);
        }

        cout<<root->val<<" "<<ans.first<<" "<<ans.second<<endl;

   

        return ans;
    }
};
