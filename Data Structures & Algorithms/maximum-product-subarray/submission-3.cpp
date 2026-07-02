class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int lprod = 1;
        int rprod = 1;
        int l = 0;
        int r = n-1;
        int maxProd = INT_MIN;
        for(int i=0;i<n;++i){
            lprod *= nums[l++];
            rprod *= nums[r--];
            maxProd = max(maxProd,max(lprod,rprod));
            if(rprod == 0) rprod = 1;
            if(lprod == 0) lprod = 1;
        }
        return maxProd;
    }
};
