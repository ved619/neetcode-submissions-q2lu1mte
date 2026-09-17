class Solution {
 public:
  int sumOfDigits(int n) {
    int sum = 0;
    while (n != 0) {
      int dig = n % 10;
      sum += dig * dig;
      n /= 10;
    }
    return sum;
  }
  bool isHappy(int n) {
    set<int> st;
    while (true) {
      int num = sumOfDigits(n);
      if (st.count(num) > 0) {
        return false;
      } else if (num == 1) {
        return true;
      }
      st.insert(num);
      n = num;
    }
    return false;
  }
};
