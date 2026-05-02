class Solution {
 public:
  bool isAlienSorted(vector<string>& words, string order) {
    // creating the rank order
    vector<int> rank(26);
    for (int i = 0; i < order.length(); ++i) {
      rank[order[i] - 'a'] = i;
    }
    for (int i = 0; i < words.size() - 1; ++i) {
      string a = words[i];
      string b = words[i + 1];
      int j = 0;
      while (j < a.length() and j < b.length()) {
        if (a[j] == b[j]) {
          ++j;
          continue;
        }
        if (rank[a[j] - 'a'] > rank[b[j] - 'a']) {
          return false;
        }
        break;
      }
      if (j == b.length() and b.length() < a.length()) {
        return false;
      }
    }
    return true;
  }
};