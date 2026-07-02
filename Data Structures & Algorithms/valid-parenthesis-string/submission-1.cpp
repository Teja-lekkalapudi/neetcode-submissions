class Solution {
public:
    bool f(int ind,int open,string s,vector<vector<int>>& dp){
        if(open < 0) return false;
        if(ind == s.size()){
            return (open == 0);
        }
        if(dp[ind][open] != -1) return dp[ind][open];
        bool result;
        if(s[ind] == '('){
            result = f(ind+1,open+1,s,dp);
        }
        else if(s[ind] == ')'){
            result = f(ind+1,open-1,s,dp);
        }
        else{
           result = (f(ind+1,open+1,s,dp) || f(ind+1,open,s,dp) || f(ind+1,open-1,s,dp));
        }
        return dp[ind][open] = result ? 1 : 0;
    }
    bool checkValidString(string s) {
        int n = s.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return f(0,0,s,dp);

        //******
        // minOpen = minimum possible open brackets
        // maxOpen = maximum possible open brackets
        //******

        int min=0;
        int max=0;
        for(char ch : s){
            if(ch == '('){
                min++;
                max++;
            }
            else if(ch == ')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(max < 0) return false;
            if(min < 0) min =0;
        }
        return min == 0;
    }
};
