class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string first = strs[0];
    string ans="";
    for (int i = 0; i < first.size(); ++i) {
      for (int j = 1; j < strs.size(); ++j) {
        string second = strs[j];
        if(first[i]!=second[i]){
            return ans;
        }
      }
      ans+=first[i];
    }
    return ans;
  }
};