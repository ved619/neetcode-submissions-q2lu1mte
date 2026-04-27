class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());

    if (dead.count("0000")) {
      return -1;
    }

    queue<string> q;
    unordered_set<string> visited;

    q.push("0000");
    visited.insert("0000");

    int steps = 0;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        string curr = q.front();
        q.pop();

        if (curr == target) {
          return steps;
        }

        for (int j = 0; j < 4; ++j) {
          char original = curr[j];

          curr[j] = (original - '0' + 1) % 10 + '0';
          if (!dead.count(curr) and !visited.count(curr)) {
            q.push(curr);
            visited.insert(curr);
          }

          curr[j] = (original - '0' - 1 + 10) % 10 + '0';
          if (!dead.count(curr) and !visited.count(curr)) {
            q.push(curr);
            visited.insert(curr);
          }
          curr[j] = original;
        }
      }
      ++steps;
    }
    return -1;
  }
};