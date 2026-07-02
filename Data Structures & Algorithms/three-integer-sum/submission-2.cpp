class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        vector<vector<int>> res;
        for(int i=0;i<n;++i){
            if(a[i] > 0) break;
            if(i>0 && a[i] == a[i-1]) continue;
            int l = i+1;
            int r = n-1;
            while(l < r){
                int sum = a[i] + a[l] + a[r];
                if(sum > 0) r--;
                else if(sum < 0) l++;
                else{
                    res.push_back({a[i],a[l],a[r]});
                    l++;r--;
                    while(l < r && a[l] == a[l-1]) l++;
                }
            }
        }
        return res;
    }
};
