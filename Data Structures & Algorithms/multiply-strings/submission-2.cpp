class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" or num2 == "0") {
      return "0";
    }
    int m = num1.size();
    int n = num2.size();
    vector<int> result(m + n, 0);

    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        int a = num1[i] - '0';
        int b = num2[j] - '0';
        result[i + j + 1] += a * b;
      }
    }
    for (int i = m + n - 1; i > 0; i--) {
      result[i - 1] += result[i] / 10;
      result[i] %= 10;
    }
    string ans;

    int i = 0;

    while (i < result.size() && result[i] == 0) i++;

    while (i < result.size()) {
      ans += char(result[i] + '0');
      i++;
    }
    return ans;
  }
};
