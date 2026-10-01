class Solution {
 public:
  int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
      int x = n % 10;
      sum += x * x;
      n /= 10;
    }
    return sum;
  }
  bool isHappy(int n) {
    unordered_set<int> uset;
    while (true) {
      int num = sumOfDigits(n);
      if (num == 1) {
        return true;
      }
      if (uset.count(num) > 0) {
        return false;
      }
      uset.insert(num);
      n = num;
    }
    return false;
  }
};
