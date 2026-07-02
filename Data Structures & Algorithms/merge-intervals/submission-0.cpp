class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int i=0;
        while(i < n){
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j=i+1;
            while(j<n && intervals[j][0] <= end){
                end = max(end,intervals[j][1]);
                j++;
            }
            res.push_back({start,end});
            i=j;
        }
        return res;
    }
};
