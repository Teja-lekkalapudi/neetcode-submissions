class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int i=1;
        int start = intervals[0][0];
        int end = intervals[0][1];
        while(i < n){
            if(intervals[i][0] <= end){
                end = max(end,intervals[i][1]);
            }
            else{
                res.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            i++;
        }
        res.push_back({start,end});
        return res;
    }
};
