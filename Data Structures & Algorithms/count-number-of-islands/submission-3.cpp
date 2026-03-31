class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    int n,m;
    bool isValid(int row, int col, vector<vector<bool>>& vis){
        if(row<0 or row>=n or col<0 or col>=m){
            return false;
        }
        if(vis[row][col]){
            return false;
        }
        return true;
    }
    void dfs(int row, int col,vector<vector<char>>& grid, vector<vector<bool>>& vis){
        vis[row][col]=true;
        for(int i=0;i<4;++i){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(isValid(nr,nc,vis) and grid[nr][nc]=='1'){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1' and vis[i][j]==false){
                    dfs(i,j,grid,vis);
                    ++ans;
                }
            }
        }
        return ans;
    }
};
