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
        if(intervals.size()<=1){
            return true;
        }
        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });
        int prev_start,prev_end;
        prev_start=intervals[0].start;
        prev_end=intervals[0].end;
        for(int i=1;i<intervals.size();++i){
            int curr_start=intervals[i].start;
            int curr_end=intervals[i].end;
            if(curr_start<prev_end){
                return false;
            }
            prev_start=curr_start;
            prev_end=curr_end;
        }
        return true;
    }
};
