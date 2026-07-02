class Solution {
public:
    int f(int ind,vector<int>& nums,vector<int>& dp){
        if(ind == nums.size()-1) return 0;
        if(nums[ind] == 0) return INT_MAX;
        if(dp[ind] != -1) return dp[ind];
        int end = min(ind + nums[ind] , (int)nums.size()-1);
        int res = INT_MAX;
        for(int j=ind+1;j<=end;++j){
             int next = f(j, nums, dp);

            if (next != INT_MAX) {           // only if reachable
                res = min(res, 1 + next);
            }
        }
        return dp[ind] = res;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp);
    }
};
