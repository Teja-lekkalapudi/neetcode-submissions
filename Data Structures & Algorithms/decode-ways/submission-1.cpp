class Solution {
public:
    int f(int ind,string s,int n){
        if(ind == n) return 1;
        if(s[ind] == '0') return 0;
        int take = f(ind+1,s,n);
        int nottake = 0;
        if(ind + 1 < n){
            int num = (s[ind]-'0')*10 + s[ind+1]-'0';
            if(num >= 10 && num <= 26){
                nottake = f(ind+2,s,n);
            }
        }
        return take + nottake;
    }
    int numDecodings(string s) {
        return f(0,s,s.size());
    }
};
