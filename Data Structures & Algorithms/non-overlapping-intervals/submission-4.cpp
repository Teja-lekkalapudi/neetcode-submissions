class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int i = 1;
        sort(intervals.begin(),intervals.end());
        int pEnd = intervals[0][1];
        int res= 0;
        
        while(i < n){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(pEnd <= start){
                //Non-Overlapping 
                pEnd = end;
            }
            else{
                res++;
                pEnd = min(pEnd,end);
            }
            i++;
        }
        return res;
    }
};
