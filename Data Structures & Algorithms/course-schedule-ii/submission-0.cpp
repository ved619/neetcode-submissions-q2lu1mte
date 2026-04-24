class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses, 0);

    // build graph
    for (auto& p : prerequisites) {
      int a = p[0];
      int b = p[1];
      adj[b].push_back(a);  // b->a
      inDegree[a]++;
    }

    queue<int> q;

    // push nodes with inDegree 0
    for (int i = 0; i < numCourses; ++i) {
      if (inDegree[i] == 0) {
        q.push(i);
      }
    }

    vector<int> result;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      result.push_back(node);

      for (int neigh : adj[node]) {
        inDegree[neigh]--;
        if (inDegree[neigh] == 0) {
          q.push(neigh);
        }
      }
    }
    if (result.size() != numCourses) {
      return {};
    }
    return result;
  }
};
