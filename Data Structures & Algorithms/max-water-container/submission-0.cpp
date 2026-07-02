class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int breadth = j-i;
                int height = min(heights[i],heights[j]);
                int area = breadth*height;
                maxArea = max(area,maxArea);
            }
        }
        return maxArea;
    }
};
