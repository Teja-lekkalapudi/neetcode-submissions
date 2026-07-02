class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(auto it : strs){
            string str = it;
            sort(it.begin(),it.end());
            mpp[it].push_back(str);
        }
        vector<vector<string>> res;
        for(auto it : mpp){
            res.push_back(it.second);
        }   
        return res;
    }
};
