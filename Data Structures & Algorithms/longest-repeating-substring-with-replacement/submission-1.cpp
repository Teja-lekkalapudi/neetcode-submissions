class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0,maxFreq=0;
        vector<int> hash(26,0);
        int l=0;
        int r=0;
        while(r < n){
            hash[s[r]-'A']++;
            maxFreq = max(maxFreq,hash[s[r]-'A']);
            int changes = (r-l+1)-maxFreq;
            if(changes <= k){
                maxLen = max(maxLen,r-l+1);
            }
            else{
                while(changes > k){
                    hash[s[l]-'A']--;
                    l++;
                    maxFreq = *max_element(hash.begin(),hash.end());
                    changes = (r-l+1) - maxFreq;
                }
            }
            r++;
        }
        return maxLen;
    }
};
