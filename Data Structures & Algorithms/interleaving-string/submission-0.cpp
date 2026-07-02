class Solution {
public:
    int f(int ind1,int ind2,int ind3,string s1,string s2,string s3,vector<vector<int>>& dp){
        if(ind3 == 0){
            return (ind1 == 0) && (ind2 == 0);
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        bool take1 = false, take2 = false;

        if (ind1 > 0 && s1[ind1 - 1] == s3[ind3 - 1])
            take1 = f(ind1 - 1, ind2, ind3-1,s1, s2, s3,dp);

        if (ind2 > 0 && s2[ind2 - 1] == s3[ind3 - 1])
            take2 = f(ind1, ind2 - 1, ind3-1,s1, s2, s3,dp);

        return dp[ind1][ind2] = (take1 || take2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        int p = s1.size();
        int q = s2.size();
        int r = s3.size();
        if(p+q != r) return false;
        vector<vector<int>> dp(p+1,vector<int>(q+1,-1));
        return f(p,q,r,s1,s2,s3,dp);
    }
};
