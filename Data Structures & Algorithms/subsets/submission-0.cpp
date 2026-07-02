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
        vector<int> temp;
        vector<vector<int>> res;
        f(0,nums,temp,res);
        return res;
    }
};
