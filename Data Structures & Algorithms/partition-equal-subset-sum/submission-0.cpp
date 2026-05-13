class Solution {
 public:
  vector<vector<int>> memo;
  bool solve(int i, int target, vector<int>& nums) {
    if (target == 0) {
      return true;
    }
    if (i >= nums.size()) {
      return false;
    }
    if (memo[i][target] != -1) {
      return memo[i][target];
    }
    bool notTake = solve(i + 1, target, nums);
    bool take = false;

    if (nums[i] <= target) {
      take = solve(i + 1, target - nums[i], nums);
    }
    return memo[i][target] = take or notTake;
  }
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num : nums) {
      sum += num;
    }
    if (sum % 2 != 0) {
      return false;
    }
    int target = sum / 2;
    int n = nums.size();
    memo.resize(n, vector<int>(target + 1, -1));
    return solve(0, target, nums);
  }
};
