class Solution {
public:
    void f(int ind,vector<int>& nums,vector<int>& temp,vector<vector<int>>& res){
       if(ind == nums.size()){
            res.push_back(temp);
            return ;
       }
        //Not_pick 
        int next = ind+1;
        while(next < nums.size() && nums[next] == nums[ind]) next++;
        f(next,nums,temp,res);
        //Pick
        temp.push_back(nums[ind]);
        f(ind+1,nums,temp,res);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        //sort the array to skip the duplicates later
        sort(nums.begin(),nums.end());
        vector<int> temp; 
        vector<vector<int>> res;
        f(0,nums,temp,res);
        return res;
    }
};
