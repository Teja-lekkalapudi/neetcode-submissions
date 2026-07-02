class Solution {
public:
    int f(int n,vector<int>& dp){
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        int step1 = f(n-1,dp);
        int step2=0;
        if(n-2 >= 0) step2 = f(n-2,dp);
        return dp[n] = step1+step2;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};
