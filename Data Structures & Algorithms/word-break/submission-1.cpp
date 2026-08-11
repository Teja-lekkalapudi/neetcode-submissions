class Solution {
public:
    int f(string s,vector<string>& wordDict,int ind,vector<int>& dp){
        if(ind == s.size()) return true;
        if(dp[ind] != -1) return dp[ind];
        int maxi = INT_MIN;
        for(string word : wordDict){
            if(ind + word.size() <= s.size()){
                if(s.substr(ind,word.size()) == word){
                    int sub = f(s,wordDict,ind+word.size(),dp);
                    if(sub != INT_MIN) {
                        maxi = max(maxi,1+sub);
                    }
                }
            }
        }
        return dp[ind] = maxi;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        //Try each word in string s ,
        //if matches move index by the length of the word
        vector<int> dp(s.size(),-1);
        int ans = f(s,wordDict,0,dp);
        return (ans != INT_MIN);
    }
};