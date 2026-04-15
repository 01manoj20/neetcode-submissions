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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans(1001);

        if(root == nullptr)
            return {};

        queue<pair<TreeNode*,int>> q;

        q.push({root,0});
        int max_dep = 0;

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();

            auto cur_nod = cur.first;
            auto cur_dep = cur.second;
            
            if(cur_nod->left!=nullptr)
                q.push({cur_nod->left,cur_dep+1});
            if(cur_nod->right!=nullptr)
                q.push({cur_nod->right,cur_dep+1});

            ans[cur_dep].push_back(cur_nod->val);
            max_dep = cur_dep;
        }
        
        ans.erase(ans.begin()+max_dep+1,ans.end());

        return ans;
    }
};
