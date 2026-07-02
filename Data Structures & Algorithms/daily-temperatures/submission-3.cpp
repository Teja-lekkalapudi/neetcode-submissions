class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        // Next Greater Element , Monotonic Stack.
        stack<int> st;
        int n = nums.size();
        vector<int> res(n,0);
        for(int i=n-1;i>=0;--i){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            res[i] = (!st.empty()) ? st.top() - i : 0;
            st.push(i); 
        }
        return res;
    }
};
