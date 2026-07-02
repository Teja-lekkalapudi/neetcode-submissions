class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();++i){
            mpp[nums[i]]++;
        }
        vector<pair<int,int>> vec;
        for(auto it : mpp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end(),[](auto a,auto b){
            return a > b;
        });
        vector<int> res;
        for(int i=0;i<k;++i){
            res.push_back(vec[i].second);
        }
        return res;
    }
};
