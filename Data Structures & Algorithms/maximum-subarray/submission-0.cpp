class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int max_sum = INT_MIN;
        int sum = 0;
        while(r < n){
            sum += nums[r];
            max_sum = max(max_sum,sum);
            while(sum < 0){
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return max_sum;
    }
};
