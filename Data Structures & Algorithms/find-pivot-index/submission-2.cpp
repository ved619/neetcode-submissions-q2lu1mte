class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int sumTotal = 0;
    int sumLeft = 0;
    // total sum
    for (int num : nums) {
      sumTotal += num;
    }
    for (int i = 0; i < nums.size(); ++i) {
      int sumRight = sumTotal - nums[i] - sumLeft;

      if (sumLeft == sumRight) {
        return i;
      }
      sumLeft += nums[i];
    }
    return -1;
  }
};