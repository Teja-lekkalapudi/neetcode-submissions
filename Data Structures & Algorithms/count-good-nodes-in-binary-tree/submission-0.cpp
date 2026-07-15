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
    void f(TreeNode* root , int num , int& count){
        if(root -> val >= num ){
            count++;
        }
        if(root -> left ){
            f(root->left,max(root->val,num),count);
        }
        if(root->right){
            f(root->right,max(root->val,num),count);
        }
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        f(root,INT_MIN,count);
        return count;
    }
};
