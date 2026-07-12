class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int sumLeft = 0;
    int sum = 0;
    for (int num : nums) {
      sum += num;
    }
    for (int i = 0; i < nums.size(); ++i) {
      int sumRight = sum - nums[i] - sumLeft;
      if (sumLeft == sumRight) {
        return i;
      }
      sumLeft += nums[i];
    }
    return -1;
  }
};