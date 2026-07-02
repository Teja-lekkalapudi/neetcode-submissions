class Solution {
public:
    int f(int ind,vector<int>& nums,int target,vector<vector<int>>& dp){
        if(ind == 0){
            if(target == 0 && nums[0] == 0) return 2;  // +0 or -0
            if(target == 0 || nums[0] == target) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        //Not Take
        int not_take = f(ind-1,nums,target,dp);
        //Take 
        int take = 0;
        if(nums[ind] <= target){
            take = f(ind-1,nums,target-nums[ind],dp);
        }
        return dp[ind][target] = take + not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        if(total_sum < abs(target)|| (total_sum + target) % 2 != 0) return 0;
        int tar = (total_sum + target)/2;
        // vector<vector<int>> dp(n+1,vector<int>(tar+1,-1));
        // return f(n-1,nums,tar,dp);
        vector<vector<int>> dp(n+1,vector<int> (tar+1,0));
        //Base cases
        if(nums[0] == 0){
            dp[0][0] = 2;
        }
        else{
            dp[0][0] = 1;
            if(nums[0] <= tar)
                dp[0][nums[0]] = 1;
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= tar; j++){
                int not_take = dp[i-1][j];
                int take = 0;
                if(nums[i] <= j)
                    take = dp[i-1][j - nums[i]];
                dp[i][j] = take + not_take;
            }
        }

        return dp[n-1][tar];
    }
};
