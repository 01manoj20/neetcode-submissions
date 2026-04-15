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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == nullptr)
            return nullptr;

        

        

        // if(!leftlca && !rightlca)
        //     cout<<root->val<<" "<<leftlca->val<<" "<<rightlca->val<<endl;

        if((root->val == p->val) || (root->val == q->val)){
            cout<<"1 "<<root->val<<" "<<root->val<<endl;
            return root;
        }

        TreeNode* leftlca = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightlca = lowestCommonAncestor(root->right,p,q);


        if((leftlca != nullptr) && (rightlca != nullptr)){
            
            return root;
        }

        if(leftlca != nullptr){
            cout<<"2 "<<root->val<<" "<<leftlca->val<<endl;
            return leftlca;
        }
        else if(rightlca != nullptr){
            cout<<"3 "<<root->val<<" "<<rightlca->val<<endl;
            return rightlca;
        }
        else
        {
            cout<<"4 "<<root->val<<endl;
            return nullptr;
        }
    }
};
