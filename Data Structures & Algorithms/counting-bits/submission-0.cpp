class Solution {
public:
    int f(int n) {
        int count=0;
        while(n > 0){
            n = n&n-1;
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;++i){
            int cnt = f(i);
            res.push_back(cnt);
        }
        return res;
    }
};
