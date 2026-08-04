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

class Codec {
public:

    void dfs_serialize(TreeNode* root , string& res) {
        if(!root){
            res += "N,";
            return ;
        }
        res += to_string(root->val) + ",";
        dfs_serialize(root->left,res);
        dfs_serialize(root->right,res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        dfs_serialize(root,res);
        return res;
    }
    TreeNode* dfs_deserialize(vector<string>& arr , int& ind){
        if(arr[ind] == "N"){
            ind++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(arr[ind]));
        ind++;
        node->left = dfs_deserialize(arr,ind);
        node->right = dfs_deserialize(arr,ind);
        return node;
    }
    vector<string> split(string& data ,char delim){
        vector<string> res;
        stringstream ss(data);
        string item;
        while(getline(ss,item,delim)){
            res.push_back(item);
        }
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> arr = split(data,',');
        int ind = 0;
        return dfs_deserialize(arr,ind);
    }
};
