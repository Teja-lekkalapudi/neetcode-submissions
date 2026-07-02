class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res1(n,1),res2(n,1);
        for(int i=1;i<nums.size();++i){
            res1[i] = nums[i-1] * res1[i-1]; 
        }
        for(int i=n-2;i>=0;--i){
            res2[i] = nums[i+1]*res2[i+1];
        }
        for(int i=0;i<n;++i){
            res1[i] = res1[i] * res2[i];
        }
        return res1;
    }
};
