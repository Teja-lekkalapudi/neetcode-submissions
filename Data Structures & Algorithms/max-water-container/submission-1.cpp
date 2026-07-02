class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        int l = 0;
        int r = n-1;
        while(l < r){
            int height = min(heights[l],heights[r]);
            int area = (height*(r-l));
            maxArea = max(maxArea,area);
            if(heights[l] < heights[r]) l++;
            else if(heights[l] > heights[r]) r--;
            else{
                l++;r--;
            }
        }
        return maxArea;
    }
};
