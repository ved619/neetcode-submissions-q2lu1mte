class Solution {
 public:
  vector<int> dp;
  int solve(vector<int>& nums, int target) {
    int result = 0;
    if (target == 0) {
      return 1;
    }
    if (target < 0) {
      return 0;
    }
    if (dp[target] != -1) {
      return dp[target];
    }
    for (int i = 0; i < nums.size(); ++i) {
      result += solve(nums, target - nums[i]);
    }
    return dp[target] = result;
  }
  int combinationSum4(vector<int>& nums, int target) {
    dp.resize(target + 1, -1);
    return solve(nums, target);
  }
};