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
    bool f(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL) return true;
        else if(p == NULL || q == NULL) return false;
        else if(p -> val != q->val ) return false;
        return f(p->left,q->left) && f(p->right,q->right);
    }
    void inorder(TreeNode* root, TreeNode* subRoot,bool& ans){
        if(root == NULL) return;
        if(root->val == subRoot->val){
            ans = ans || f(root,subRoot);
        }
        inorder(root->left,subRoot,ans);
        inorder(root->right,subRoot,ans);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        inorder(root,subRoot,ans);
        return ans;
    }
};
