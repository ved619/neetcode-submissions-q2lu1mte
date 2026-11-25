class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    int prevStart = intervals[0][0];
    int prevEnd = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      int currStart = intervals[i][0];
      int currEnd = intervals[i][1];
      if (currStart <= prevEnd) {
        prevEnd = max(prevEnd, currEnd);
      } else {
        res.push_back({prevStart, prevEnd});
        prevStart = currStart;
        prevEnd = currEnd;
      }
    }
    res.push_back({prevStart, prevEnd});
    return res;
  }
};
