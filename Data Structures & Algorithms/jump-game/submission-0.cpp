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
        vector<int> dp(nums.size(),-1);
        return f(nums,0,dp);
    }
};
