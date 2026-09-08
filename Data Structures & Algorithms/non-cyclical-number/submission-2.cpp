class Solution {
 public:
  int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
      int digit = num % 10;
      sum = sum + (digit * digit);
      num = num / 10;
    }
    return sum;
  }
  bool isHappy(int n) {
    set<int> s;
    while (true) {
      n = sumOfDigits(n);
      if (n == 1) {
        return true;
      }
      if (s.count(n)) {
        return false;
      }
       s.insert(n);
    }
  }
};
