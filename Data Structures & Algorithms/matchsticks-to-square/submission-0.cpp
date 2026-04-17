class Solution {
 public:
  bool solve(vector<int>& matchsticks, int idx, vector<int>& bucket, int target) {
    if (idx == matchsticks.size()) {
      return true;
    }
    int num = matchsticks[idx];
    for (int i = 0; i < bucket.size(); ++i) {
      if (bucket[i] + num > target) {
        continue;
      }
      bucket[i] += num;
      if (solve(matchsticks, idx + 1, bucket, target)) {
        return true;
      }
      bucket[i] -= num;
      if (bucket[i] == 0) {
        break;
      }
    }
    return false;
  }
  bool makesquare(vector<int>& matchsticks) {
    vector<int> bucket(4, 0);
    int sum = 0;
    for (int matchstick : matchsticks) {
      sum += matchstick;
    }
    if (sum % 4 != 0) {
      return false;
    }
    int target = sum / 4;
    sort(matchsticks.rbegin(), matchsticks.rend());
    return solve(matchsticks,0,bucket,target);
  }
};