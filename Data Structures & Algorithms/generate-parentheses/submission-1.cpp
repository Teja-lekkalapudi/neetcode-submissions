class Solution {
public:
    void f(int open,int close,string& temp,vector<string>& res,int n){
        if(temp.size() == 2*n){
            res.push_back(temp);
            return ;
        }
        if(open < n){
            temp.push_back('(');
            f(open+1,close,temp,res,n);
            temp.pop_back();
        }
        if(close < open){
            temp.push_back(')');
            f(open,close+1,temp,res,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp="";
        f(0,0,temp,res,n);
        return res;
    }
};
