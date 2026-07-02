class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int right = nums.size()-1;
        while(low <= right){
            int mid = (low+right)>>1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid-1;
            else low = mid+1;
            
        }
        return -1;
    }
};
