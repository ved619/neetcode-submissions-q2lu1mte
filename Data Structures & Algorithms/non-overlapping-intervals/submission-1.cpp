class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int count = 0;
    int previousEnd = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      // no overlap
      if (intervals[i][0] >= previousEnd) {
        previousEnd = intervals[i][1];
      } else {
        ++count;
        previousEnd = min(previousEnd, intervals[i][1]);
      }
    }
    return count;
  }
};
