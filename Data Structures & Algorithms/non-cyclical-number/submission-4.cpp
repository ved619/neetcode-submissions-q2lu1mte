class Solution {
 public:
  int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
      int lastDigit = num % 10;
      sum += lastDigit * lastDigit;
      num /= 10;
    }
    return sum;
  }
  bool isHappy(int n) {
    set<int> st;
    while (true) {
      if (n == 1) {
        return true;
      }

      n = sumOfDigits(n);
      if (st.count(n)) {
        return false;
      }
      st.insert(n);
    }
    return false;
  }
};
