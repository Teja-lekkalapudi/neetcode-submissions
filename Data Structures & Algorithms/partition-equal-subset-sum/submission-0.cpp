class Solution {
public:
//Look for a subset of sum = total_sum/2;
    bool f(int ind,int n,vector<int>& nums,int total_sum,vector<vector<int>>& dp){
        if(total_sum == 0) return true;
        if(ind == n){
            return false;
        }
        if(dp[ind][total_sum] != -1) return dp[ind][total_sum];
        bool nottake = f(ind+1,n,nums,total_sum,dp);
        bool take = false;
        if(total_sum >= nums[ind]){
           take =  f(ind+1,n,nums,total_sum-nums[ind],dp);
        }
        return dp[ind][total_sum]=take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        if(total_sum % 2 != 0) return false;
        total_sum = total_sum/2;
        vector<vector<int>> dp(n,vector<int>(total_sum+1,-1));
        return f(0,n,nums,total_sum,dp);
    }
};
