class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int totalSum = 0;
    int currMax = 0;
    int maxSum = nums[0];

    int currMin = 0;
    int minSum = nums[0];

    for (int num : nums) {
      totalSum += num;

      // kadanes algo
      currMax = max(num, currMax + num);
      maxSum = max(maxSum, currMax);

      // kadanes for minimum subarray
      currMin = min(num, currMin + num);
      minSum = min(minSum, currMin);
    }
    if (maxSum < 0) {
      return maxSum;
    }
    return max(maxSum, totalSum - minSum);
  }
};