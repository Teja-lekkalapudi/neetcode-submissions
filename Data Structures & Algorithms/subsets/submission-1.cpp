class Solution {
public:
    void f(int ind,vector<int>& nums,vector<int>& temp,vector<vector<int>>& res){
       if(ind == nums.size()){
            res.push_back(temp);
            return ;
       }
        //Not_pick 
        f(ind+1,nums,temp,res);
        //Pick
        temp.push_back(nums[ind]);
        f(ind+1,nums,temp,res);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        // vector<int> temp; created to use for recursion.
        vector<vector<int>> res;
        // f(0,nums,temp,res);
        // return res;
        int total = (1 << n);
        for(int mask = 0;mask<total;++mask){
            vector<int> temp;
            for(int i=0;i<n;++i){
                if(mask & (1 << i)){
                    temp.push_back(nums[i]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
