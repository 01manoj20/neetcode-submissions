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
    int kthSmallest(TreeNode* root, int k) {

        // if(sizeTree(root) == 1){
        //     cout<<sizeTree(root)<<endl;
        //     cout<<"condition 1 \n";
        //     return root->val;
        // }

        int left_size(0),right_size(0);
        if(root->left!=nullptr)
            left_size = sizeTree(root->left);
        if(root->right!=nullptr)
            right_size = sizeTree(root->right);

        cout<<root->val<<" "<<left_size<<" "<<right_size<<endl;

        if(k<=left_size){
            cout<<"condition 2 \n";
            return kthSmallest(root->left,k);
        }
        else if(k == left_size+1){
            cout<<"condition 3 \n";
            return root->val;
        }
        else{ 
            cout<<"condition 4 \n";
            return kthSmallest(root->right,k-left_size-1);
        }

            
        
        
    }

    int sizeTree(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        int left_size(0),right_size(0);
        if(root->left!=nullptr)
            left_size = sizeTree(root->left);
        if(root->right!=nullptr)
            right_size = sizeTree(root->right);

        return left_size+right_size+1;
    }
};
