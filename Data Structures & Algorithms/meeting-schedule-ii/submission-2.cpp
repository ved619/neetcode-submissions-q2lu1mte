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
    //min-heap approach
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()){
            return 0;
        }   
        //sort by start-time
        sort(intervals.begin(), intervals.end(),
         [](const Interval& a, const Interval& b){
             return a.start < b.start;
         });

        //min-heap storing end-time of current meetings.
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(intervals[0].end);
        
        for(int i=1;i<intervals.size();++i){
            int start=intervals[i].start;
            int end=intervals[i].end;
            if(!pq.empty() and pq.top()<=start){
                pq.pop();
            }
            pq.push(end);
        }
        return pq.size();
    }
};
