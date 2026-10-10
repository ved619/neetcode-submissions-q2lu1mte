class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    int start = intervals[0][0];
    int end = intervals[0][1];
    vector<vector<int>> res;
    for (int i = 1; i < intervals.size(); ++i) {
      int curr_start = intervals[i][0];
      int curr_end = intervals[i][1];
      if (curr_start <= end) {
        end = max(end, curr_end);
      } else {
        res.push_back({start, end});
        start = curr_start;
        end = curr_end;
      }
    }
    res.push_back({start, end});
    return res;
  }
};
