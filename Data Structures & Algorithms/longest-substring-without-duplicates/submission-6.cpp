class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mpp;
        int max_len = 0;
        int l=0;
        int r=0;
        while(r < n){
            if(mpp.count(s[r])){
                if(l <= mpp[s[r]]){
                    l = 1 + mpp[s[r]];
                }
            }
            mpp[s[r]] = r;
            max_len = max(max_len,r-l+1);
            r++;
        }
        return max_len;
    }
};
