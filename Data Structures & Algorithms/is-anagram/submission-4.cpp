class Solution {
public:
    bool isAnagram(string s, string t) {
        int xorr = 0;
        int xorr2 = 0;
        for(int i=0;i<s.size();++i){
            xorr ^= s[i]-'a';
        }
        for(int j=0;j<t.size();++j) xorr2 ^= t[j]-'a'; 
        if(xorr == 0 && xorr2 == 0){
            for(int j=0;j<t.size();++j){
                if(s[0] == t[j]) return true;
            }
            return false;
        }
        return (xorr == xorr2);
    }
    
};
