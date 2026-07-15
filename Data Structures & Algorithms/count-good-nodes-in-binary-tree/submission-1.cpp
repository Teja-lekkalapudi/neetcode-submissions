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
    int f(TreeNode* root , int num){
        int count = 0;
        if(root -> val >= num ){
            count += 1;
        }

        
        if(root -> left ){
            count += f(root->left,max(root->val,num));
        }
        if(root->right){
            count += f(root->right,max(root->val,num));
        }
        return count;
    }
    int goodNodes(TreeNode* root) {
        return f(root,INT_MIN);
    }
};
