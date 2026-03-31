class Solution {
public:
    void dfs(int index, vector<vector<int>>& adj, vector<bool>& vis){
        vis[index]=true;
        for(auto x: adj[index]){
            if(!vis[x]){
                dfs(x,adj,vis);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if((n-1)!=edges.size()){
            return false;
        }
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0,adj,vis);
        for(auto x: vis){
            if(!x){
                return false;
            }
        }
        return true;
    }
};
