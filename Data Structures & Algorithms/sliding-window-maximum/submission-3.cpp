class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int maxi = INT_MIN;
        vector<int> res;
        while(r < n){
            if(r-l+1 > k){
                l++;
            }
            if(r-l+1 == k){
                maxi = INT_MIN;
                for(int i=l;i<=r;++i){
                    maxi = max(maxi,nums[i]);
                }
                res.push_back(maxi);
            }
            r++;
        }
        return res;
    }
};
