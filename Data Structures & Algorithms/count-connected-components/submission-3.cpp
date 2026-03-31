class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node]=true;
        for(int num : adj[node]){
            if(!vis[num]){
                dfs(num,adj,vis);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto edge: edges){
            int num1=edge[0];
            int num2=edge[1];
            adj[num1].push_back(num2);
            adj[num2].push_back(num1);
        }
        vector<bool> vis(n);
        int connectedComponents=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                ++connectedComponents;
                dfs(i,adj,vis);
            }
        }
        return connectedComponents;
    }
};
