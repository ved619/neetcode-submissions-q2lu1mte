class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      int curr_start = intervals[i][0];
      int curr_end = intervals[i][1];
      if (curr_start <= end) {
        end = max(end, curr_end);
      } else {
        result.push_back({start, end});
        start = curr_start;
        end = curr_end;
      }
    }
    result.push_back({start, end});
    return result;
  }
};
