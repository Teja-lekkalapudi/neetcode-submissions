class Solution {
public:
    string longestPalindrome(string s) {
        int sInd = -1;
        int maxLen = 0;
        int n = s.size();
        for(int i=0;i<n;++i){
            //odd
            int l = i;
            int r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(maxLen < r-l+1){
                    maxLen = r-l+1;
                    sInd = l;
                }
                l--;r++;
            }
            //even 
            l=i;
            r=i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(maxLen < r-l+1){
                    maxLen = r-l+1;
                    sInd = l;
                }
                l--;r++;
            }
        }
        string str = s.substr(sInd,maxLen);
        return str;
    }
};
