class Solution {
public:

    int countSubstrings(string s) {
        int sInd = -1;
        int maxLen = 0;
        int n = s.size();
        int count = 0;
        for(int i=0;i<n;++i){
            //odd
            int l = i;
            int r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                count++;
                l--;r++;
            }
            //even 
            l=i;
            r=i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                count++;
                l--;r++;
            }
        }
        return count;
    }
};
