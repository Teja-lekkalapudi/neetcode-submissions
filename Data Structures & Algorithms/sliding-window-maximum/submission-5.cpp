class Solution {
public:
// Brute force is the sliding window + finding maximum for each window and TC -> O(n*k)
//n-k+1 -- windows in total 
// while writing the brute force check for test case [1,-1] for k = 1;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //This the optimal solution using deque. TC->O(N), space ->O(k)
        //The intuition is if the window crosses the size k , then pop from front .
        //Check the new element in the array is greater than element in deque from if yes then pop from back.
        int n = nums.size();
        vector<int> res;
        deque<int> dq;
        int l = 0;
        int r = 0;
        while(r < n){
            while(!dq.empty() && nums[dq.back()] <= nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);
            if(l > dq.front()){
                dq.pop_front();
            }
            if(r-l+1 == k){
                res.push_back(nums[dq.front()]);
                l++;
            } 
            r++;
        }
        return res;
    }
};
