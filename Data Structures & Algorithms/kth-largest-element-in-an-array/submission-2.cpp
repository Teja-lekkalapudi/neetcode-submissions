class Solution {
public:
    int quickSelect(vector<int>& nums,int l,int r,int k){
        int pivot = nums[r];
        int p = l;
        for(int i=l;i<r;++i){
            if(nums[i] <= pivot){
                swap(nums[i],nums[p]);
                p++;
            }
        }
        swap(nums[r],nums[p]);
        if(p == k) return nums[p];
        else if(p < k) return quickSelect(nums,p+1,r,k);
        else return quickSelect(nums,l,p-1,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int K = n-k;
        return quickSelect(nums,0,n-1,K);
    }
};
