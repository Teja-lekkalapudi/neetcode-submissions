class Solution {
public:
    bool isPalindrome(vector<int>& vec,string str){
        int n = str.size();
        vector<int> vec1(26,0);
        for(int i=0;i<n;++i){
            vec1[str[i]-'a']++;
        }
        for(int i=0;i<26;++i){
            if(vec[i] != vec1[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        vector<int> vec(26,0);
        for(int i=0;i<n;++i){
            vec[s1[i]-'a']++;
        }
        int l = 0;
        int r = n-1;
        while(r < m){
            string str = s2.substr(l,r-l+1);
            if(isPalindrome(vec,str)) return true;
            l++;
            r++;
        }
        return false;
    }
};
