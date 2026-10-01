class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string result = "";
    while (columnNumber) {
      columnNumber--;
      int x = columnNumber % 26;
      result += 'A' + x;
      columnNumber /= 26;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};