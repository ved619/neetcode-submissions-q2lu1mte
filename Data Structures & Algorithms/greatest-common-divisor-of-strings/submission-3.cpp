class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    int len;
    if (str1 + str2 == str2 + str1) {
      len = gcd(str1.length(), str2.length());
    } else {
      return "";
    }
    return str1.substr(0, len);
  }
};