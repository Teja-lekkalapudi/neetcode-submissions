class Solution {
public:
    int f(int ind,int buy,int n,vector<int>& prices,vector<vector<int>>& dp){
        if(ind >= n){
            return 0;
        }
        if(dp[ind][buy] != -1) return dp[ind][buy];
        //Buy
        int profit = 0;
        if(buy){
            profit = max(-prices[ind]+f(ind+1,0,n,prices,dp),f(ind+1,1,n,prices,dp));
        }
        //sell
        else{
            profit = max(prices[ind] + f(ind+2,1,n,prices,dp),f(ind+1,0,n,prices,dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,n,prices,dp);
    }
};
