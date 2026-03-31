class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    bool isValid(int r,int c,int n,int m, vector<vector<bool>>& vis){
        if(r<0 or r>=n or c<0 or c>=m){
            return false;
        }
        if(vis[r][c]){
            return false;
        }
        return true;
    }
    void dfs(int r,int c,int n,int m,vector<vector<char>>& grid, vector<vector<bool>>& vis){

        for(int i=0;i<4;++i){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(isValid(nr,nc,n,m,vis) and grid[nr][nc]=='1'){
                vis[nr][nc]=true;
                dfs(nr,nc,n,m,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int countIslands=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1' and !vis[i][j]){
                    vis[i][j]=true;
                    dfs(i,j,n,m,grid,vis);
                    ++countIslands;
                }
            }
        }
        return countIslands;
    }
};
