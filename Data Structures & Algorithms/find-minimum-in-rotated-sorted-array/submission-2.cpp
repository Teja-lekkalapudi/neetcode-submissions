class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int res = nums[0];
        while(low <= high){
            if(nums[low] <= nums[high]) return min(res,nums[low]);
            int mid = (low + high) >> 1;
            res = min(res,nums[mid]);
            // We are in left sorted portion
            // Search right portion for minimum value
            if(nums[mid] >= nums[low]){
                low = mid+1;
            }
            else high = mid-1;
        }
        return res;
    }
};
