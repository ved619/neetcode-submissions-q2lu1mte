class Solution {
 public:
  int sumOfSquareOfDigits(int n) {
    int res = 0;
    while (n != 0) {
      int lastDigit = n % 10;
      res += lastDigit * lastDigit;
      n = n / 10;
    }
    return res;
  }
  bool isHappy(int n) {
    set<int> seen;
    int val = n;
    while (val != 1) {
      if (seen.count(val) > 0) {
        return false;
      }
      seen.insert(val);
      val = sumOfSquareOfDigits(val);
    }
    return true;
  }
};
