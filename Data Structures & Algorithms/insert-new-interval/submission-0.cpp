class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];
        int i=0;
        int n = intervals.size();
        vector<vector<int>> res;
        while(i < n){
            //edge case
            if(intervals[i][0] > end){
                res.push_back(newInterval);
                for(int it = i;it<n;++it){
                    res.push_back(intervals[it]);
                }
                return res;
            }
            else if(intervals[i][1] < start){
                res.push_back(intervals[i]);
            }
            else{
                int mini = min(intervals[i][0],newInterval[0]);
                int maxi = max(intervals[i][1],newInterval[1]);
                newInterval[0] = mini;
                newInterval[1] = maxi;
            }
            i++;
        }
        res.push_back(newInterval);
        return res;
    }
};
