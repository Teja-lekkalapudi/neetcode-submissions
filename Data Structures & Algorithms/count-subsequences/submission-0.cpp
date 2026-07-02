class Solution {
public:
    int f(int ind1,int ind2,string s,string t,vector<vector<int>>& dp){
        if(ind2 == 0) return 1;
        if(ind1 == 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int take = 0;
        if(s[ind1-1] == t[ind2-1]){
           return  dp[ind1][ind2] = f(ind1-1,ind2-1,s,t,dp) + f(ind1-1,ind2,s,t,dp);
        }
        return dp[ind1][ind2] = f(ind1-1,ind2,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(m,n,s,t,dp);
    }
};
