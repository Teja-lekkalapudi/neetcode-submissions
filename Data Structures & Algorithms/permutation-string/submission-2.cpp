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
        // For first window 
        vector<int> vec1(26,0);
        for(int i=0;i<n;++i){
            vec1[s2[i]-'a']++;
        }
        if(vec == vec1) return true;
        int l = 0;
        int r = n-1;
        while(r < m-1){
            // Check continuosly for each window 
            //Dont use substring and passing to isPermutation function as substring in loop is costly
            //and for each we have to check whether it is true or false
            vec1[s2[l]-'a']--;
            l++;
            ++r;
            //check r<m as if r == m-1 and ++r does that r == m then it cause ouof bounds error
            vec1[s2[r]-'a']++;
            if(vec == vec1) return true;
        }
        return false;
    }
};
