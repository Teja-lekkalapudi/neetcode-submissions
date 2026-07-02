class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m < n ) return "";
        vector<int> hashT(256,0);
        for(int i=0;i<n;++i) hashT[t[i]]++;
        
        //For every substring
        int minLen = INT_MAX;
        int sIdx = -1;
        int l = 0;
        int r = 0;
        int count = 0;
        while(r < m){
            if(hashT[s[r]] > 0){
                count++;
            }
            hashT[s[r]]--;
            while(count == n){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIdx = l;
                }
                hashT[s[l]]++;
                if(hashT[s[l]] > 0) count--;
                l++;
            }
            r++;
        }
        if(sIdx == -1) return "";
        return s.substr(sIdx, minLen);
    }
};
