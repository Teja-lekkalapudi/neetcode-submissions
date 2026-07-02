class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        set<vector<int>> st;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                for(int k=j+1;k<n;++k){
                    if(a[i] + a[j] + a[k] == 0){
                        vector<int> temp = {a[i],a[j],a[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(auto it : st)   res.push_back(it);
        return res;
    }
};
