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
    void f(TreeNode* root,vector<vector<int>>& ans){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> res;          
            int n = q.size();           
            for(int i=0;i<n;++i){
                auto it = q.front();
                q.pop();
                res.push_back(it->val);
                if(it->left != NULL) q.push(it->left);
                if(it->right != NULL) q.push(it->right);
            }
            ans.push_back(res);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        f(root,ans);
        return ans;
    }
};
