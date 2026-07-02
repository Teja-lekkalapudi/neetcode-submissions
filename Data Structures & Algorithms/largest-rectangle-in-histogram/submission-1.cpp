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
        prevSmaller(heights,pse,st);
        while(!st.empty()) st.pop();
        nextSmaller(heights,nse,st);
        int maxArea = INT_MIN;
        for(int i=0;i<n;++i){
            int width = nse[i]-pse[i]-1;
            int area = width * heights[i];
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};
