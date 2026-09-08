class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> result;
    int i = digits.size() - 1;
    int carry = 1;
    while (i >= 0 or carry) {
      int sum = carry;
      if (i >= 0) {
        sum += digits[i];
      }
      carry = sum / 10;
      sum = sum % 10;
      result.push_back(sum);
      --i;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
