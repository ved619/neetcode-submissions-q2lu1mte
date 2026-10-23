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
    vector<vector<int>> meetings;
    for (auto interval : intervals) {
      meetings.push_back({interval.start, interval.end});
    }
    sort(meetings.begin(), meetings.end());
    int prev_start = meetings[0][0];
    int prev_end = meetings[0][1];
    for (int i = 1; i < meetings.size(); ++i) {
      int curr_start = meetings[i][0];
      int curr_end = meetings[i][1];
      if (curr_start < prev_end) {
        return false;
      }
      prev_start = curr_start;
      prev_end = curr_end;
    }
    return true;
  }
};
