class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        vector<int> vec(26,0);
        for(int i=0;i<n;++i){
            vec[s1[i]-'a']++;
        }
        vector<int> vec1(26,0);
        for(int i=0;i<n;++i){
            vec1[s2[i]-'a']++;
        }
        if(vec == vec1) return true;
        int l = 0;
        int r = n-1;
        while(r < m){
            vec1[s2[l]-'a']--;
            l++;
            ++r;
            vec1[s2[r]-'a']++;
            if(vec == vec1) return true;
        }
        return false;
    }
};
