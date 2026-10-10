class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int i = digits.size() - 1;
    int carry = 1;
    while (i >= 0 and carry) {
      int sum = carry;
      sum += digits[i];
      digits[i] = sum % 10;
      carry = sum / 10;
      --i;
    }
    if (carry) {
      digits.insert(digits.begin(), carry);
    }
    return digits;
  }
};
