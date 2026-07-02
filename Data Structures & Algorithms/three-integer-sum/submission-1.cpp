class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        unordered_map<int,int> mpp;
        for(int it : a){
            mpp[it]++;
        }
        vector<vector<int>> res;
        for(int i=0;i<n;++i){
            mpp[a[i]]--;
            if(i>0 && a[i] == a[i-1]) continue;
            for(int j=i+1;j<n;++j){
                mpp[a[j]]--;
                if(j > i+1 && a[j] == a[j-1]) continue;
                int target = -(a[i] + a[j]);
                if(mpp[target]> 0){
                    vector<int> temp={a[i],a[j],target};
                    res.push_back(temp);
                }
            }
            for(int j=i+1;j<n;++j) mpp[a[j]]++;
        }
        return res;
    }
};
