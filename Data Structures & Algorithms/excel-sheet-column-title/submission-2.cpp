class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string result="";
    while (columnNumber > 0) {
      columnNumber--;
      int remainder = columnNumber % 26;
      char ch = remainder + 'A';
      columnNumber/=26;
      result += ch;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};