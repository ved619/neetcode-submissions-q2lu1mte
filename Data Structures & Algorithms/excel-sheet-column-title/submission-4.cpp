class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string result = "";
    while (columnNumber != 0) {
      columnNumber--;
      result += (columnNumber % 26) + 'A';
      columnNumber /= 26;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};