class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int sum = 0;
    for (int n : nums) {
      sum += n;
    }
    int sumLeft = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int sumRight = sum - sumLeft - nums[i];
      if (sumLeft == sumRight) {
        return i;
      }
      sumLeft += nums[i];
    }
    return -1;
  }
};