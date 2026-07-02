class Solution {
public:
    bool valid(string s){
        int open = 0;
        for(char ch : s){
            open += (ch == '(') ? 1 : -1;
            if(open < 0) return false;
        }
        return open == 0;
    }
    void dfs(string s,vector<string>& res,int n){
        if(s.size() == 2*n){
            if(valid(s)){
                res.push_back(s);
            }
            return ;
        }
        dfs(s + '(',res, n);
        dfs(s + ')',res,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("",res,n);
        return res;
    }
};
