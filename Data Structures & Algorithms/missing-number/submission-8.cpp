class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int result = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i <= nums.size(); ++i) {
      result = result ^ i;
    }
    for (int i = 0; i < nums.size(); ++i) {
      result = result ^ nums[i];
    }
    return result;
  }
};
