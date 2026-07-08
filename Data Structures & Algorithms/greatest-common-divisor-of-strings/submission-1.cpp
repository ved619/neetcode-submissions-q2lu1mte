class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    int a=str1.length();
    int b=str2.length();
    if (str1 + str2 != str2 + str1) {
      return "";
    }
    int gcdLength=gcd(a,b);
    return str2.substr(0,gcdLength);
  }
};