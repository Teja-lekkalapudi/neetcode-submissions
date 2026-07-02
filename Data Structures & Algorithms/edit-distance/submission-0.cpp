class Solution {
public:
    int f(int ind1,int ind2,string word1,string word2,vector<vector<int>>& dp){
        if(ind1 == word1.size()){
            return word2.size()-ind2; // insert remaining
        }
        if(ind2 == word2.size()){
            return word1.size()-ind1; // delete remaining
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        //Matches
        if(word1[ind1] == word2[ind2]){
            return dp[ind1][ind2] = f(ind1+1,ind2+1,word1,word2,dp);
        }
        //No-match
        int insert_op = 1+f(ind1,ind2+1,word1,word2,dp);
        int delete_op = 1+f(ind1+1,ind2,word1,word2,dp);
        int replace_op = 1+f(ind1+1,ind2+1,word1,word2,dp);
        return dp[ind1][ind2] = min({insert_op,delete_op,replace_op});
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return f(0,0,word1,word2,dp);
    }
};
