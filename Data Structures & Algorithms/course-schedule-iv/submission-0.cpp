class Solution {
 public:
  vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    // build graph
    for (auto& p : prerequisites) {
      int u = p[0];
      int v = p[1];
      adj[u].push_back(v);
      indegree[v]++;
    }
    vector<vector<bool>> reach(numCourses, vector<bool>(numCourses, false));
    queue<int> q;
    // push nodes with indegree 0
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        reach[u][v] = true;

        for (int i = 0; i < numCourses; ++i) {
          if (reach[i][u]) {
            reach[i][v] = true;
          }
        }
        indegree[v]--;
        if (indegree[v] == 0) {
          q.push(v);
        }
      }
    }
    vector<bool> answer;
    for (auto& q : queries) {
      int u = q[0];
      int v = q[1];
      answer.push_back(reach[u][v]);
    }
    return answer;
  }
};
