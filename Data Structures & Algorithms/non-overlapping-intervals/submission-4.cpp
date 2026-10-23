class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int prev_start = intervals[0][0];
    int prev_end = intervals[0][1];
    int ans = 0;
    for (int i = 1; i < intervals.size(); ++i) {
      int curr_start = intervals[i][0];
      int curr_end = intervals[i][1];
      if (curr_start < prev_end) {
        prev_end = min(prev_end, curr_end);
        ++ans;
      } else {
        prev_start = curr_start;
        prev_end = curr_end;
      }
    }
    return ans;
  }
};
