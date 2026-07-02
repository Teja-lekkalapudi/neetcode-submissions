class Solution {
public:
    int f(int ind , vector<int>& nums,vector<int>& dp){
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int no_rob = f(ind-1,nums,dp);
        int rob = nums[ind] + f(ind-2,nums,dp);
        return dp[ind] = max(rob,no_rob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n,-1);
        // return f(n-1,nums,dp);
        
        //Tabulation
        vector<int> dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;++i){
            int rob = nums[i] + dp[i-2] ;
            int no_rob = dp[i-1];
            dp[i] = max(rob,no_rob);
        }
        return dp[n-1];
    }
};
