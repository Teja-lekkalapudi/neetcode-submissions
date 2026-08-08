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
        int v1 = 1;
        int v2 = 1;
        for(int i=2;i<=n;++i){
            int step1 = v1;
            int step2 = v2;
            int v3 = step1 + step2;
            v1 = v2;
            v2 = v3;
        }
        return v2;
    }
};
