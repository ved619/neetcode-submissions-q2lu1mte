class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis ){
        vis[node]=true;
        for(int nei: adj[node]){
            if(!vis[nei]){
                dfs(nei,adj,vis);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        //condition 1: Edge count
        if(edges.size()!=n-1){
            return false;
        }
        vector<vector<int>> adj(n);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n,false);
        dfs(0,adj,vis);
        
        //condition 2: connectivity
        for(bool v: vis){
            if(!v)return false;
        }
        return true;
    }
};
