class Solution {
public:
    void nextPermutation(vector<int>& nums){
        int n = nums.size();
        int ind = -1;
        for(int i=n-1;i>=1;--i){
            if(nums[i] > nums[i-1]){
                ind = i-1;
                break;
            }
        }
        if(ind == -1){
            //if we dont find the ind , then it is the last permutation , reverse it to get next permutation. i.e, first permutation 
            reverse(nums.begin(),nums.end());
            return ;
        }     
        else{
            for(int i=n-1;i>ind;--i){
                if(nums[ind] < nums[i]){
                    swap(nums[ind],nums[i]);
                    break;
                }
            }
            reverse(nums.begin() + ind + 1, nums.end());
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> first = nums;

        do{
            res.push_back(nums);
            nextPermutation(nums);
        }while(nums != first);
        
        return res;
    }
};
