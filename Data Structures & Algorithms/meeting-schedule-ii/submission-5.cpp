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
    static bool compare(Interval a, Interval b){
      return a.start<b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(), compare);
        priority_queue<int, vector<int>, greater<int>> endTimes;

        for(auto interval: intervals){
          if(!endTimes.empty() and endTimes.top()<=interval.start){
            endTimes.pop();
          }
          endTimes.push(interval.end);
        }
        return endTimes.size();
    }
};
