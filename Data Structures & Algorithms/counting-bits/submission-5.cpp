class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> result;
    for (int i = 0; i <= n; ++i) {
      int num = i;
      int oneCount = 0;
      while (num) {
        int lastDigit = num & 1;
        if (lastDigit == 1) {
          ++oneCount;
        }
        num = num >> 1;
      }
      result.push_back(oneCount);
    }
    return result;
  }
};
