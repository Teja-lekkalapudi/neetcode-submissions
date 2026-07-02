class Solution {
public:
    bool f(int ind1,int ind2,string& s,string& p,vector<vector<int>>& dp){
        if(ind2 == p.size()) return (ind1 == s.size());
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(ind2 + 1 < p.size() && p[ind2+1] == '*'){
            //zero || one or more times matching for p[ind2]
            bool zero = f(ind1,ind2+2,s,p,dp);
            bool one_or_more = false;
            if(ind1 < s.size() && (s[ind1] == p[ind2] || p[ind2] == '.')){
                one_or_more = f(ind1+1,ind2,s,p,dp);
            }
            return dp[ind1][ind2] = zero || one_or_more;
        }
        if(ind1 < s.size() && (s[ind1] == p[ind2] || p[ind2] == '.')){
            return dp[ind1][ind2]=f(ind1+1,ind2+1,s,p,dp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(0,0,s,p,dp);
    }
};
