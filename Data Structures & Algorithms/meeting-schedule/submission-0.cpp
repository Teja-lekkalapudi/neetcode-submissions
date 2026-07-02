/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) {
            return x.start < y.start;
        });
        int i = 1;
        int n = intervals.size();
        int pEnd = intervals[0].end;
        while(i < n){
            int start = intervals[i].start;
            int end = intervals[i].end;
            if(pEnd > start) return false;
            else{
                pEnd = end;
            }
            i++;
        }
        return true;
    }
};
