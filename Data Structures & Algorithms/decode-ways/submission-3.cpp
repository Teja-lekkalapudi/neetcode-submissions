class Solution {
   public:
    int f(int ind, string s, int n, vector<int>& dp) {
        if (ind == n) return 1;
        if(ind > n) return 0;
        if (s[ind] == '0') return 0;
        if (dp[ind] != -1) return dp[ind];
        int take_one_digit = f(ind + 1, s, n, dp);
        int take_two_digits = 0;
        if (ind + 1 < n) {
            int num = (s[ind] - '0') * 10 + s[ind + 1] - '0';
            if (num >= 10 && num <= 26) {
                take_two_digits = f(ind + 2, s, n, dp);
            }
        }
        return dp[ind] = take_one_digit + take_two_digits;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return f(0,s,n,dp);
    }
};
