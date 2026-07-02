class Solution {
public:
    int f(int ind1,int ind2,string text1,string text2,vector<vector<int>>& dp){
        if(ind1 == 0 || ind2 == 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        //Take
        int take = 0;
        if(text1[ind1-1] == text2[ind2-1]){
            take = 1 + f(ind1-1,ind2-1,text1,text2,dp);
        }
        int not_take = max(f(ind1-1,ind2,text1,text2,dp),f(ind1,ind2-1,text1,text2,dp));
        return dp[ind1][ind2]=max(take,not_take);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        //Tabulation

        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                int take = 0;
                if(text1[i-1] == text2[j-1]){
                    take = 1 + dp[i-1][j-1];
                }
                int not_take = max(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = max(take , not_take);
            }
        }
        return dp[m][n];
    }
};
