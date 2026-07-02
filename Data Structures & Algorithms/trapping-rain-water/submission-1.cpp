class Solution {
public:
    void prevGreater(vector<int>& heights, vector<int>& pge) {
        int n = heights.size();
        int max_ele = INT_MIN;
        int idx = 0;
        for(int i=0;i<n;++i){
            if(heights[i] > max_ele){
                idx = i;
                max_ele = heights[i];
            }
            pge[i] = idx;
        }
    }
    void nextGreater(vector<int>& heights, vector<int>& nge) {
        int n = heights.size();
        int idx = n-1;
        for(int i=n-1;i>=0;--i){   
            if(heights[i] > heights[idx]){
                idx = i;
            }
            nge[i] = idx;
        }
    }   

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> next(n,n);
        vector<int> prev(n,-1);
        prevGreater(height,prev);
        nextGreater(height,next);
        int trap = 0;
        for(int i=0;i<n;++i){
            int drops = min(height[prev[i]],height[next[i]]);
            trap += drops-height[i];
        }
        return trap;
    }
};
