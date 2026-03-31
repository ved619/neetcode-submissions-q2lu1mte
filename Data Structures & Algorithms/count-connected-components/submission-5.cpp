class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node]=true;
        for(int curr: adj[node]){
            if(!vis[curr]){
                dfs(curr,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto x: edges){
            int first=x[0];
            int second=x[1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        int ans=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;++i){
            if(vis[i]==false){
                dfs(i,adj,vis);
                ++ans;
            }
        }
        return ans;
    }
};
