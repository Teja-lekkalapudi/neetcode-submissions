class Solution {
public:
    bool f(int ind1,int ind2,string& s,string& p){
        if(ind2 == p.size()) return (ind1 == s.size());
        
        if(ind2 + 1 < p.size() && p[ind2+1] == '*'){
            //zero || one or more times matching for p[ind2]
            bool zero = f(ind1,ind2+2,s,p);
            bool one_or_more = false;
            if(ind1 < s.size() && (s[ind1] == p[ind2] || p[ind2] == '.')){
                one_or_more = f(ind1+1,ind2,s,p);
            }
            return zero || one_or_more;
        }
        if(ind1 < s.size() && (s[ind1] == p[ind2] || p[ind2] == '.')){
            return f(ind1+1,ind2+1,s,p);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return f(0,0,s,p);
    }
};
