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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()){
            TreeNode* rightNode = nullptr;
            int qLen = q.size();
            for(int i=0;i<qLen;++i){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    rightNode = node;
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
            if(rightNode) res.push_back(rightNode->val);
        }
        return res;
    }
};
