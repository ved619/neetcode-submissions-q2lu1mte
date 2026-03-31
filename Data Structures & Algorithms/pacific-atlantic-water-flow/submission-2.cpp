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
    void dfs(int row, int col, vector<vector<bool>>& vis, vector<vector<int>>& heights){
        vis[row][col]=true;
        for(int i=0;i<4;++i){
            int nr=row+dr[i];
            int nc=col+dc[i];
            
            if(isValid(nr,nc,vis) and heights[nr][nc]>=heights[row][col]){
                dfs(nr,nc,vis,heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> visPacific(n,vector<bool>(m,false));
        vector<vector<bool>> visAtlantic(n,vector<bool>(m,false));
        //Pacific
        for(int i=0;i<n;++i){
            dfs(i,0,visPacific,heights);
        }
        for(int i=0;i<m;++i){
            dfs(0,i,visPacific,heights);
        }
        //Atlantic
        for(int i=0;i<m;++i){
            dfs(n-1,i,visAtlantic,heights);
        }
        for(int i=0;i<n;++i){
            dfs(i,m-1,visAtlantic,heights);
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(visPacific[i][j]==true and visAtlantic[i][j]==true){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};
