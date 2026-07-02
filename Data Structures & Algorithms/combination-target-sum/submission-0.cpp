class Solution {
public:
    void f(int ind,vector<int>& nums,vector<int>& temp,vector<vector<int>>& res,int target){
        if(ind == nums.size()){
            if(target == 0){
                res.push_back(temp);
            }
            return ;
        }
        //Not_take
        f(ind+1,nums,temp,res,target);
        //take
        if(nums[ind] <= target){
            temp.push_back(nums[ind]);
            f(ind,nums,temp,res,target-nums[ind]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> res;
        f(0,nums,temp,res,target);
        return res;
    }
};
