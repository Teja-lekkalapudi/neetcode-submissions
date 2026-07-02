class Solution {
public:
    bool f(string s,vector<string>& wordDict,int ind,vector<int>& dp){
        if(ind == s.size()) return true;
        if(dp[ind] != -1) return dp[ind];
        for(string word : wordDict){
            if(ind + word.size() <= s.size()){
                if(s.substr(ind,word.size()) == word){
                    if(f(s,wordDict,ind+word.size(),dp))
                        return dp[ind] = 1;
                }
            }
        }
        return dp[ind]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        //Try each word in string s ,
        //if matches move index by the length of the word
        vector<int> dp(s.size(),-1);
        return f(s,wordDict,0,dp);
    }
};
