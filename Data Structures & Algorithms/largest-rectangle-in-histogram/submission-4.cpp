class Solution {
public:
    void prevSmaller(vector<int>& heights,vector<int>& pse,stack<int>& st){
        int n = heights.size();
        for(int i=0;i<n;++i){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
    }
    void nextSmaller(vector<int>& heights,vector<int>& nse,stack<int>& st){
        int n = heights.size();
        for(int i=n-1;i>=0;--i){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        stack<int> st;
        // prevSmaller(heights,pse,st);
        // while(!st.empty()) st.pop();
        // nextSmaller(heights,nse,st);
        int maxArea = 0;
        // for(int i=0;i<n;++i){
        //     int width = nse[i]-pse[i]-1;
        //     int area = width * heights[i];
        //     maxArea = max(maxArea,area);
        // }

        // With out using nse and pse 
        for(int i=0;i<=n;++i){
            int curht = (i == n) ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] > curht){
                // If the current element is less than h[st.top()] then remove the stack top element and calculate area for it .
                // The right is the nse for it i.e, i and left is st.top() , if st.top() is empty then it is -1
                int ht = heights[st.top()];
                st.pop();
                int left = (st.empty()) ? -1 : st.top();
                int right = i;
                int width = (right - left -1);
                int area = (width * ht);
                maxArea = max(maxArea,area);
            }
            st.push(i);
        }
        return maxArea;
    }
};
