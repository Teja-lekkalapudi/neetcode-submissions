class Solution {
public:
    int f(int ind,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(ind == 0){
            return (amount%coins[ind] == 0);
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        //Not Take
        int not_take = f(ind-1,amount,coins,dp);
        //Take
        int take = 0;
        if(coins[ind] <= amount){
            take = f(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // return f(n-1,amount,coins,dp);
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        for(int i=0;i<=amount;++i){
            dp[0][i] = (i%coins[0] == 0);
        }
        for(int ind=1;ind<n;++ind){
            for(int j=0;j<=amount;++j){
                int not_take = dp[ind-1][j];
                int take = 0;
                if(coins[ind] <= j){
                    take = dp[ind][j-coins[ind]];
                }
                dp[ind][j] = take + not_take;
            }
        }
        return dp[n-1][amount];
    }
};
