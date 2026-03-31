class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node]=true;
        for(int neighbor: adj[node]){
            if(!vis[neighbor]){
                dfs(neighbor,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int components=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                ++components;
                dfs(i,adj,vis);
            }
        }
        return components;
    }
};
