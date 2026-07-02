class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int longest = 0;
        for(int it=0;it<nums.size();++it){
            if(st.find(nums[it]-1) == st.end()){
                int length = 1;
                while(st.find(nums[it]+length) != st.end()){
                    length++;
                }
                longest=max(length,longest);
            }
        }
        return longest;
    }
};
