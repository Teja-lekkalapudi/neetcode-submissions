class Solution {
public:
    bool f(vector<int>& nums,int ind,vector<int>& dp){
        if(nums.size()-1 == ind) return true;
        if(dp[ind] != -1) return dp[ind];
        int end = min((int)nums.size()-1,ind + nums[ind]);
        for(int j=ind+1;j<=end;++j){
            if(f(nums,j,dp)){
                dp[ind]=1;
                return true;
            }
        }
        dp[ind]=0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        //vector<int> dp(nums.size(),-1);
        // return f(nums,0,dp);
        int n = nums.size();
        int max_ind_reach = 0;
        int cur_ind = 0;
        for(int i=0;i<n;++i){
            if(i > max_ind_reach) return false;
            cur_ind = i+nums[i];
            max_ind_reach = max(max_ind_reach,cur_ind);
        }
        if(max_ind_reach >= n-1) return true;
        return false;
    }
};
