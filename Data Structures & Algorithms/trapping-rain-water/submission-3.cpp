class Solution {
public:
    // not pge and important to rememeber is , it is prefix max 
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
    // It is suffix max not nge . (careful).
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
        // vector<int> next(n,n);
        // vector<int> prev(n,-1);
        // prevGreater(height,prev);
        // nextGreater(height,next);
        // int trap = 0;
        // for(int i=0;i<n;++i){
        //     int drops = min(height[prev[i]],height[next[i]]);
        //     // we found the minimum height of prev and next , 
        //     // now this much water drops can be stored but we have to substract the height of the pillar 
        //     // and this approach is mainly calculating the water droplets on each piller.
        //     trap += drops-height[i];
        // }
        // return trap;


        // Using the two pointer approach (Optimal)

        int left = 0;
        int right = n-1;
        int drops = 0;
        int leftMax = 0,rightMax=0;
        while(left < right){
            // Always move a pointer towards higher height.
            if(height[left] <= height[right]){
                // While moving a pointer towards higher height keep track of leftMax for max height until reached.
                //If we have a pillar less than leftMax then that is between leftMax and height[right]
                //because now we are moving left++ as height[right] is greater.
                //But when height[left] is greater than leftMax then we cannot calculate water drops on the pillar as we dont have left boundary to store.
                if(height[left] > leftMax) leftMax = height[left];
                else drops += leftMax - height[left];
                left++;
            }
            else{
                if(height[right] > rightMax) rightMax = height[right];
                else   drops += rightMax - height[right];
                right--;
            }
            
        }
        return drops;
    }
};
