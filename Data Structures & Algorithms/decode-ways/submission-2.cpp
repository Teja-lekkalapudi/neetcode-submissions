class Solution {
public:
    int f(int ind,string s,int n,vector<int>& dp){
        if(ind == n) return 1;
        if(s[ind] == '0') return 0;
        if(dp[ind] != -1) return dp[ind];
        int take = f(ind+1,s,n,dp);
        int nottake = 0;
        if(ind + 1 < n){
            int num = (s[ind]-'0')*10 + s[ind+1]-'0';
            if(num >= 10 && num <= 26){
                nottake = f(ind+2,s,n,dp);
            }
        }
        return dp[ind]=take + nottake;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return f(0,s,s.size(),dp);
    }
};
