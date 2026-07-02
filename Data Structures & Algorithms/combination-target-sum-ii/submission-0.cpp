class Solution {
public:
    void f(int ind,vector<int>& nums,vector<int>& temp,vector<vector<int>>& res,int target){
        
            if(target == 0){
                res.push_back(temp);
                return ;
            }
            
        
        if(ind == nums.size()) return ;
        //Not_take
        int next = ind + 1;
        while (next < nums.size() && nums[next] == nums[ind]) next++;
        f(next,nums,temp,res,target);
        //take
        if(nums[ind] <= target){
            temp.push_back(nums[ind]);
            f(ind+1,nums,temp,res,target-nums[ind]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        //As the input is not distinct integers , sort the nums
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> res;
        f(0,nums,temp,res,target);
        return res;
    }
};
