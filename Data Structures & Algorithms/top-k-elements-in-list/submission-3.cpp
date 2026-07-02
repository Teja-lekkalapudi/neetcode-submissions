class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;++i){
            mpp[nums[i]]++;
        }
        // we splitted the numbers into frequency of buckets , means the same frequency of numbers will be in same bucket
        vector<vector<int>> buckets(n+1);
        for(auto it : mpp){
            buckets[it.second].push_back(it.first);
        }
        vector<int> res;
        int count = 0;
        for(int i=n;i>=1;--i){
            int m = buckets[i].size();
            if(count < k && m > 0){
               for(auto it : buckets[i]){
                res.push_back(it);
               }
                count += m;
            }
        }
        return res;
    }
};
