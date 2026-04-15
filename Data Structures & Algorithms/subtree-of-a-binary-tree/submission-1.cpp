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
    vector<TreeNode*> find_ptrs;
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }
    void find(TreeNode* root,int value)
    {
        if(root != nullptr)
        {
            if(root->val == value)
                find_ptrs.push_back(root);
            find(root->left,value);
            find(root->right,value);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr)
            return true;
        else
        {
            find(root,subRoot->val);
            if(find_ptrs.size() == 0)
                return false; 
            
            for(auto find_ptr:find_ptrs)
                if(isSameTree(find_ptr,subRoot))
                    return true;

            return false;
        }
        
    }
};
