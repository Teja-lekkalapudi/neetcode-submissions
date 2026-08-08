class Solution {
public:
    int f(int n,vector<int>& dp){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int step1 = f(n-1,dp);
        int step2 = f(n-2,dp);
        return dp[n] = step1+step2;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;++i){
            int step1 = dp[i-1];
            int step2 = dp[i-2];
            dp[i] = step1 + step2;
        }
        return dp[n];
    }
};
