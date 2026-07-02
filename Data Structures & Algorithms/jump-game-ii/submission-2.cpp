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
        // vector<int> dp(n,-1);
        // return f(0,nums,dp);
        int max_ind = 0;
        int curr_ind = 0;
        int count=0;
        for(int i=0;i<n-1;++i){
            max_ind = max(max_ind, i+nums[i]);
            if(curr_ind == i){
                count++;
                curr_ind = max_ind;
            }
            
        }
        return count;
    }
};
