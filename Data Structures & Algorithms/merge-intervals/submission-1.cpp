class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int i = 0;
    int n = intervals.size();
    while (i < n) {
      int start = intervals[i][0];
      int end = intervals[i][1];
      while (i < n and intervals[i][0] <= end) {
        end = max(end, intervals[i][1]);
        ++i;
      }
      ans.push_back({start, end});
    }
    return ans;
  }
};
