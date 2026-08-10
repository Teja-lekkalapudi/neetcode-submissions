class Solution {
public:
    int f(vector<int>& nums,int start,int end,vector<int>& dp){
        if(start > end) return 0;
        if(dp[start] != -1) return dp[start];
        //rob 
        int rob = nums[start] + f(nums,start+2,end,dp);
        //no-rob
        int no_rob = f(nums,start+1,end,dp);
        return dp[start] = max(rob,no_rob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        //when only one house is there to rob
        if(n == 1) return nums[0];
        vector<int> dp(n,-1);
        int s1 = f(nums,0,n-2,dp);
        for(int i=0;i<n;++i) dp[i] = -1;
        int s2 = f(nums,1,n-1,dp);
        return max(s1,s2);
    }
};
