class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis){
        vis[node]=true;
        for(int neighbor: adj[node]){
            if(!vis[neighbor]){
                dfs(neighbor,adj,vis);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){
            return false;
        }
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            int first=edge[0];
            int second=edge[1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        vector<bool> vis(n,false);
        dfs(0,adj,vis);
        for(bool v: vis){
            if(v==false){
                return false;
            }
        }
        return true;
    }
};
