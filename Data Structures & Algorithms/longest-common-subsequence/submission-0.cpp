class Solution {
public:
    int f(int ind1,int ind2,string text1,string text2,vector<vector<int>>& dp){
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        //Take
        int take = 0;
        if(text1[ind1] == text2[ind2]){
            take = 1 + f(ind1-1,ind2-1,text1,text2,dp);
        }
        int not_take = max(f(ind1-1,ind2,text1,text2,dp),f(ind1,ind2-1,text1,text2,dp));
        return dp[ind1][ind2]=max(take,not_take);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,text1,text2,dp);
    }
};
