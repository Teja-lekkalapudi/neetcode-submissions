class Solution {
public:
    bool isValid(vector<int>& hs,vector<int>& ht){
        for(int i=0;i<256;++i){
            if(hs[i] < ht[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m < n ) return "";
        vector<int> hashT(256,0);
        for(int i=0;i<n;++i) hashT[t[i]]++;
        
        //For every substring
        int minLen = INT_MAX;
        int sIdx = -1;
        for(int i=0;i<m;++i){
            vector<int> hashS(256,0);
            for(int j=i;j<m;++j){
                hashS[s[j]]++;
                if(isValid(hashS,hashT)){
                    if(minLen > j-i+1){
                        minLen = j-i+1;
                        sIdx = i;
                    }
                    break;
                }
            }
        }
         if(sIdx == -1) return "";
        return s.substr(sIdx, minLen);
    }
};
