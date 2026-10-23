class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" or num2 == "0") {
      return "0";
    }
    int n = num1.length();
    int m = num2.length();
    vector<int> result(m + n, 0);
    for (int i = n - 1; i >= 0; --i) {
      int carry = 0;
      for (int j = m - 1; j >= 0; --j) {
        int digit1 = num1[i] - '0';
        int digit2 = num2[j] - '0';
        int sum = digit1 * digit2 + result[i + j + 1] + carry;
        result[i + j + 1] = sum % 10;
        carry = sum / 10;
      }
      result[i] += carry;
    }
    string answer = "";
    for (int digit : result) {
      if (!(answer.empty() and digit == 0)) {
        answer += to_string(digit);
      }
    }
    return answer;
  }
};
