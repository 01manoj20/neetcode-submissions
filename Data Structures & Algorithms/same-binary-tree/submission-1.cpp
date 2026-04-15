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
    vector<int> pstruct;
    vector<int> qstruct;
public:
    vector<int> getstruct(TreeNode* root)
    {
        vector<int> ans;

        if(root == nullptr)
            return {0};
        else
        {
            ans.push_back(root->val);
            vector<int> lans = getstruct(root->left);
            vector<int> rans = getstruct(root->right);
            ans.insert(ans.end(),lans.begin(),lans.end());
            ans.insert(ans.end(),rans.begin(),rans.end());

            return ans;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        pstruct = getstruct(p);
        qstruct = getstruct(q);

        if(pstruct.size() == qstruct.size())
        {
            for(int i=0;i<pstruct.size();i++)
            {   
                cout<<i<<" "<<pstruct[i]<<" "<<qstruct[i]<<endl;
                if(pstruct[i]!=qstruct[i])
                    return false;
            }

            return true;
        }
        else
            return false;
    }
};
