class Solution {
public:
    int f(int ind,int n,vector<int>& cost,vector<int>& dp){
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int step1=cost[ind]+f(ind+1,n,cost,dp);
        int step2=cost[ind]+f(ind+2,n,cost,dp);
        return dp[ind]=min(step1,step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(f(0,n,cost,dp),f(1,n,cost,dp));
    }
};
