class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int right = nums.size()-1;
        while(low <= right){
            int mid = (low+right)>>1;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) right = mid-1;
            else low = mid+1;
            
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()-1;
        int m = matrix[0].size();
        while(low <= high){
            int mid = (low+high)>>1;
            if(matrix[mid][0] > target){
               high = mid-1;
            }
            else if(matrix[mid][m-1] < target){
                low = mid+1;
            }
            else{
                return search(matrix[mid],target);
            }
        }
        return false;
    }
};
