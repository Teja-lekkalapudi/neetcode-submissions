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
        for(int i=0;i<n;++i){
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k-1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
