class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> hash(26,0);
        int l = 0;
        int r = 0;
        int maxFreq = 1;
        int max_len = 0;
        while(r < n){
            hash[s[r]-'A']++;
            maxFreq = max(maxFreq,hash[s[r]-'A']);
            if((r-l+1)-maxFreq <= k){
                max_len = max(max_len , r-l+1);
            }
            else{
                while((r-l+1)-maxFreq > k){
                    hash[s[l]-'A']--;
                    l++;
                }
            }
            r++;
        }
        return max_len;
    }
};
