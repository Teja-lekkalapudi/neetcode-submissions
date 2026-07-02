class Solution {
public:
    void f(int ind,string& s,vector<string>& part,vector<vector<string>>& res){
        if(ind >= s.size()){
            res.push_back(part);
            return ;
        }
        for(int i=ind;i<s.size();++i){
            if(isPali(s,ind,i)){
                part.push_back(s.substr(ind,i-ind+1));
                f(i+1,s,part,res);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        f(0,s,part,res);
        return res;
    }
    bool isPali(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
