class Solution {
public:

    void dfs(int index, vector<vector<int>>& v, vector<bool>& vis){
        vis[index]=true;
        for(auto x: v[index]){
            if(!vis[x]){
                dfs(x,v,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
        vector<bool> vis(n,false);
        for(auto edge: edges){
            v[edge[0]].push_back(edge[1]);
            v[edge[1]].push_back(edge[0]);
        }
        int components=0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                components++;
                dfs(i,v,vis);
            }
        }
        return components;
    }
};
