class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mpp;
        int l = 0;
        int r = 0;
        int maxi;
        maxi = (n == 0) ? 0 : 1;
        while(r < n){
            if(mpp.count(s[r]) != 0){
                if(mpp[s[r]] >= l){
                    l = 1 + mpp[s[r]];
                }
            }
            maxi = max(maxi,r-l+1);
            mpp[s[r]] = r;
            r++;
        }
        return maxi;
    }
};
