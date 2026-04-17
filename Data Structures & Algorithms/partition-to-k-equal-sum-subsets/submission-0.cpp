class Solution {
 public:
  bool solve(vector<int>& nums, int idx, vector<int>& bucket, int target) {
    if (idx == nums.size()) {
      return true;
    }
    int num = nums[idx];
    for (int i = 0; i < bucket.size(); ++i) {
      if (bucket[i] + num > target) {
        continue;
      }
      bucket[i] += num;
      if (solve(nums, idx + 1, bucket, target)) {
        return true;
      }
      bucket[i] -= num;
      if (bucket[i] == 0) {
        break;
      }
    }
    return false;
  }
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (int num : nums) {
      sum += num;
    }
    // step1: check divisibility
    if (sum % k != 0) {
      return false;
    }
    int target = sum / k;
    // sort reversed
    sort(nums.rbegin(), nums.rend());
    if (nums[0] > target) {
      return false;
    }
    vector<int> bucket(k, 0);
    return solve(nums, 0, bucket, target);
  }
};