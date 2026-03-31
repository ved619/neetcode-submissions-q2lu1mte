class Solution {
public:
    void dfs(int n, vector<vector<int>>& adj, vector<bool>& isVisited){
        isVisited[n]=true;
        for(int num: adj[n]){
            if(!isVisited[num]){
                dfs(num,adj,isVisited);
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
        vector<bool> isVisited(n,false);
        int connectedComponents=0;
        for(int i=0;i<n;++i){
            if(!isVisited[i]){
                ++connectedComponents;
                dfs(i,adj,isVisited);
            }
        }
        return connectedComponents;
    }
};
