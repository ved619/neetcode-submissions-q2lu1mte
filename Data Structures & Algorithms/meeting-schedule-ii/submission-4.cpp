class Solution {
 public:
  int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const Interval& a, const Interval& b) { return a.start < b.start; });

    priority_queue<int, vector<int>, greater<int>> endTimes;

    for (const auto& m : intervals) {
      if (!endTimes.empty() && endTimes.top() <= m.start) {
        endTimes.pop();
      }
      endTimes.push(m.end);
    }
    return endTimes.size();
  }
};