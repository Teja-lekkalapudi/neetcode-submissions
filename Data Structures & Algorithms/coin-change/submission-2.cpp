class Solution {
public:
    int f(int ind,vector<int>& coins,int amount,vector<vector<int>>& dp){
        if(ind == 0){
            if(amount%coins[ind] == 0) return amount/coins[ind];
            return INT_MAX;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        //Not Pick
        int not_pick = f(ind-1,coins,amount,dp);
        //Pick
        int pick = INT_MAX;
        if(amount >= coins[ind]){
            int sub = f(ind,coins,amount-coins[ind],dp);
            if(sub != INT_MAX) pick = 1 + sub;
        }
        return dp[ind][amount] = min(not_pick,pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int temp = f(coins.size()-1,coins,amount,dp);
        return (temp != INT_MAX) ? temp : -1;
    }
};
